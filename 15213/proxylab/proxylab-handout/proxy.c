/*ANDREWID: roysung
 *
 * proxy.c - This is the entire code for the proxy. It basically combines
 *           code from tiny.c with some code to act like a client
 *           This does NOT implement a cache but it is multi-threaded
 */

#include <stdio.h>
#include <stdlib.h>
#include "csapp.h"

/* Recommended max cache and object sizes */
#define MAX_CACHE_SIZE 1049000
#define MAX_OBJECT_SIZE 102400

void doit(int fd);
void read_requesthdrs(rio_t *rp);
void clienterror(int fd, char *cause, char *errnum, char *shortmsg,
                 char *longmsg);
int gethostport(char *request, char *host, char *port);
void connectServer(rio_t *rp, char *host, char *port,int fd, char *newRequest);
void generateRequest(rio_t *rp, char *uri, char *newRequest, char *host);
int checkheader(char *buf);
void *thread(void *vargp);



/* You won't lose style points for including these long lines in your code */
static const char *user_agent_hdr = "User-Agent: Mozilla/5.0 (X11; Linux x86_64; rv:10.0.3) Gecko/20120305 Firefox/10.0.3\r\n";
static const char *accept_hdr = "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n";
static const char *accept_encoding_hdr = "Accept-Encoding: gzip, deflate\r\n";

int main(int argc, char **argv)
{

    int listenfd;
//    char hostname[MAXLINE],port[MAXLINE];
    socklen_t clientlen;
    struct sockaddr_storage clientaddr;

    pthread_t tid;

    int *connfdp;

    if (argc != 2)
    {
       fprintf(stderr, "usage: %s <port>\n", argv[0]);
       exit(1);
    }


    listenfd = Open_listenfd(argv[1]);
    while(1)
    {

        clientlen = sizeof(clientaddr);
        connfdp = Malloc(sizeof(int));
        *connfdp = Accept(listenfd, (SA *)&clientaddr, &clientlen);
        Pthread_create(&tid, NULL, thread, connfdp);

    }
//    printf("%s%s%s", user_agent_hdr, accept_hdr, accept_encoding_hdr);

    return 0;
}


/*
 * thread - calls doit function for the thread
 */
void *thread(void *vargp)
{
   int connfd = *((int *)vargp);
   Pthread_detach(pthread_self());
   signal(SIGPIPE,SIG_IGN);
   Free(vargp);
   doit(connfd);
   Close(connfd);

   return NULL;

}



/*
 * doit - This function does the bulk of the work so it calls
 *        the functions to write and read to servers and then
 *        writes that response back to the client
 */
void doit(int fd)
{


   char host[MAXLINE];
   char port[MAXLINE];


   char buf[MAXLINE], method[MAXLINE], uri[MAXLINE], version[MAXLINE];


   char newRequest[MAXBUF];


   rio_t rio;



   /* associate fd with rio */
   Rio_readinitb(&rio, fd);

   /* check for errors */
   if (!Rio_readlineb(&rio, buf, MAXLINE))
      return;
   printf("%s",buf);

   /* check if the request is a GET request if not then error
    * and then return and wait for next http request */
   sscanf(buf, "%s %s %s", method, uri, version);
   if (strcasecmp(method, "GET"))
   {
      clienterror(fd, method, "501", "Not Implemented",
                             "Tinty does not implement this method");
      return;
   }


   /* get the host name and the port to listen to */
   if ( gethostport(uri,host,port) == -1 )
   {
      clienterror(fd, method, "401", "Malformed Request",
                              "Malformed url request");

      return;

   }

   /* generate the new request */
   generateRequest(&rio,uri,newRequest,host);


//   printf("%s",newRequest);
   /* connect to server and pass off http request from client
    * to server */
   connectServer(&rio,host,port,fd,newRequest);

   return;

}


/* 
 * gethostport - extracts the host and port from the url
 */
int gethostport(char *uri, char *host, char *port)
{


    /* some temp variables to help with the string manipulation */
    char temp[MAXLINE];
    char *temp2;
    char *unparsedURI = temp;
    char *temphost;
    char finaluri[MAXLINE];

    /* checks to see there is an http in front */
    if ( sscanf(uri,"http://%s",temp) < 1)
       return -1;

    finaluri[0] = '/';

    temphost = strsep(&unparsedURI,"/");

    strcat(finaluri,unparsedURI);
    strcpy(uri,finaluri);

    temp2 = strsep(&temphost,":");


    /* default port set */
    if (temphost == NULL)
       strcpy(port, "80\0");
    else
       strcpy(port,temphost);

    strcpy(host,temp2);

    return 1;

     

}



/* 
 * generateRequest - generates the http request that the proxy will send
 *                   to the server
 */
void generateRequest(rio_t *rp, char *uri, char *newRequest, char *host)
{

     char buf[MAXLINE],body[MAXBUF];

     buf[0] = '\0';
     body[0] = '\0';

     char initialRequest[MAXLINE];

     initialRequest[0] = '\0';
     int hostCheck = 1;

    /* Build the intial line for request */
    strcpy(initialRequest,"GET ");
    strcat(initialRequest,uri);
    strcat(initialRequest, " HTTP/1.0\r\n");

 

    /* Read the first headers and put them in buf */
    Rio_readlineb(rp, buf, MAXLINE);
    if (strcmp(buf,"\r\n") ) {
        sprintf(body,"%s",buf);
    }



     /* loop until we reach the end of http request 
      * while looping we create new http request that we use to send*/
     while(strcmp(buf,"\r\n"))
     {


          /* Read the http request recieved from the client
           * and store it in buf */
          Rio_readlineb(rp, buf, MAXLINE);


          /* check if the header is host */
          if ( strstr(buf,"Host:") ) {
             hostCheck = 0;
          }

          /* if it is the end of all headers don't put it in body 
           * since we are going to add more */ 
          if ( strcmp(buf,"\r\n") && checkheader(buf) ) {
             sprintf(body,"%s%s",body,buf);
          }
    
     }


     /* if host was not specified then addd as header */
     if (hostCheck) {
         sprintf(body,"%sHost: %s\r\n",body,host);
     }


     /* add in required headers */
     sprintf(body, "%s%s", body, user_agent_hdr);
     sprintf(body, "%s%s", body, accept_hdr);
     sprintf(body, "%s%s", body, accept_encoding_hdr);
     sprintf(body, "%sConnection: close\r\n",body);
     sprintf(body, "%sProxy-Connection: close\r\n\r\n",body);


     /* combine header with the intial line */
     sprintf(newRequest,"%s%s",initialRequest,body);


     return;


}


/*
 *
 *   connectServer - connect to Server and pass off http request
 *                   to the server, so essentially act like a client
 *                   from the server point of view
 */
void connectServer(rio_t *rp, char *host, char *port, int fd, char *newRequest)
{

     int clientfd;

     char buf[MAXLINE];

     int n;
   
     rio_t rioServer;


     /* connect to server and write to the socket with the 
 *      newly formed http request */
     clientfd = Open_clientfd(host,port);

     Rio_readinitb(&rioServer,clientfd);

     Rio_writen(clientfd, newRequest, strlen(newRequest));


     /* Then read the response from the server and pass that off
     * to the client
     */
     while ( (n= Rio_readlineb(&rioServer,buf,MAXLINE)) != 0) {
           Rio_writen(fd,buf,n);
     }
     Close(clientfd);


     return;

}

/*
 *  checkheader - checks the header to see if it is one of the
 *                headers that we are required to send
 *                specific values for
 */
int checkheader(char *buf)
{

    if ( strstr(buf,"User-Agent:") ) {
       return 0;
    }
    if ( strstr(buf, "Accept:") ) {
       return 0;
    }
    if ( strstr(buf, "Accept-Encoding:") ) {
       return 0;
    }
    if ( strstr(buf, "Connection:") ) {
       return 0;
    }
    if ( strstr(buf, "Proxy-Connection:") ) {
       return 0;
    }

    return 1;




}




/*
 * clienterror - if there is a client error send and error
 *               message back to the client
 */
void clienterror(int fd, char *cause, char *errnum, char *shortmsg,
                 char *longmsg)
{

    char buf[MAXLINE], body[MAXBUF];

    /* buidl the http response boyd */
    sprintf(body, "<html><title>Error</title>");
    sprintf(body, "%s<body bgcolor=""ffffff"">\r\n", body);
    sprintf(body, "%s%s: %s\r\rn", body, errnum, shortmsg);
    sprintf(body, "%s<p>%s: %s\r\n", body, longmsg, cause);
    sprintf(body, "%s<hr><em>The Proxy Web server</em>\r\n", body);

    /* Print the http response */
    sprintf(buf, "HTTP/1.0 %s %s\r\n", errnum, shortmsg);
    Rio_writen(fd, buf, strlen(buf));
    sprintf(buf, "Content-type: text/html\r\n");
    sprintf(buf, "Conten-length: %d\r\n\r\n", (int)strlen(body));
    Rio_writen(fd, buf, strlen(buf));
    Rio_writen(fd, body, strlen(body));


}







