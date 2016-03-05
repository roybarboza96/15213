#include <stdlib.h> 

struct person_node { 
    char* name;
    int age;
};

struct pet_node { 
    char* name; 
    char type[10]; 
};

typedef struct person_node person; 
typedef struct pet_node pet; 

int main() { 
    /* TODO: dynamically allocate enough memory, assign the blocks to these pointers */
    
    int* A;     // Construct a 10-elmeent integer array 
    int** B;    // Construct a 2D array of 10 x 10 integers,  
    person* C;  // Construct an array of 10 persons, allocate 10 characters for each name
    pet* D;     // Construct an array of 10 pets, allocate 10 characters for each name;

    // free any memory you just allocated before you return!
    return 0; 
}
