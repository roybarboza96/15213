
bufbomb:     file format elf32-i386


Disassembly of section .init:

0804877c <_init>:
 804877c:	55                   	push   %ebp
 804877d:	89 e5                	mov    %esp,%ebp
 804877f:	53                   	push   %ebx
 8048780:	83 ec 04             	sub    $0x4,%esp
 8048783:	e8 00 00 00 00       	call   8048788 <_init+0xc>
 8048788:	5b                   	pop    %ebx
 8048789:	81 c3 58 29 00 00    	add    $0x2958,%ebx
 804878f:	8b 93 fc ff ff ff    	mov    -0x4(%ebx),%edx
 8048795:	85 d2                	test   %edx,%edx
 8048797:	74 05                	je     804879e <_init+0x22>
 8048799:	e8 9e 00 00 00       	call   804883c <__gmon_start__@plt>
 804879e:	e8 ed 02 00 00       	call   8048a90 <frame_dummy>
 80487a3:	e8 b8 18 00 00       	call   804a060 <__do_global_ctors_aux>
 80487a8:	58                   	pop    %eax
 80487a9:	5b                   	pop    %ebx
 80487aa:	c9                   	leave  
 80487ab:	c3                   	ret    

Disassembly of section .plt:

080487ac <__errno_location@plt-0x10>:
 80487ac:	ff 35 e4 b0 04 08    	pushl  0x804b0e4
 80487b2:	ff 25 e8 b0 04 08    	jmp    *0x804b0e8
 80487b8:	00 00                	add    %al,(%eax)
	...

080487bc <__errno_location@plt>:
 80487bc:	ff 25 ec b0 04 08    	jmp    *0x804b0ec
 80487c2:	68 00 00 00 00       	push   $0x0
 80487c7:	e9 e0 ff ff ff       	jmp    80487ac <_init+0x30>

080487cc <sprintf@plt>:
 80487cc:	ff 25 f0 b0 04 08    	jmp    *0x804b0f0
 80487d2:	68 08 00 00 00       	push   $0x8
 80487d7:	e9 d0 ff ff ff       	jmp    80487ac <_init+0x30>

080487dc <srand@plt>:
 80487dc:	ff 25 f4 b0 04 08    	jmp    *0x804b0f4
 80487e2:	68 10 00 00 00       	push   $0x10
 80487e7:	e9 c0 ff ff ff       	jmp    80487ac <_init+0x30>

080487ec <connect@plt>:
 80487ec:	ff 25 f8 b0 04 08    	jmp    *0x804b0f8
 80487f2:	68 18 00 00 00       	push   $0x18
 80487f7:	e9 b0 ff ff ff       	jmp    80487ac <_init+0x30>

080487fc <mmap@plt>:
 80487fc:	ff 25 fc b0 04 08    	jmp    *0x804b0fc
 8048802:	68 20 00 00 00       	push   $0x20
 8048807:	e9 a0 ff ff ff       	jmp    80487ac <_init+0x30>

0804880c <getpid@plt>:
 804880c:	ff 25 00 b1 04 08    	jmp    *0x804b100
 8048812:	68 28 00 00 00       	push   $0x28
 8048817:	e9 90 ff ff ff       	jmp    80487ac <_init+0x30>

0804881c <random@plt>:
 804881c:	ff 25 04 b1 04 08    	jmp    *0x804b104
 8048822:	68 30 00 00 00       	push   $0x30
 8048827:	e9 80 ff ff ff       	jmp    80487ac <_init+0x30>

0804882c <signal@plt>:
 804882c:	ff 25 08 b1 04 08    	jmp    *0x804b108
 8048832:	68 38 00 00 00       	push   $0x38
 8048837:	e9 70 ff ff ff       	jmp    80487ac <_init+0x30>

0804883c <__gmon_start__@plt>:
 804883c:	ff 25 0c b1 04 08    	jmp    *0x804b10c
 8048842:	68 40 00 00 00       	push   $0x40
 8048847:	e9 60 ff ff ff       	jmp    80487ac <_init+0x30>

0804884c <__isoc99_sscanf@plt>:
 804884c:	ff 25 10 b1 04 08    	jmp    *0x804b110
 8048852:	68 48 00 00 00       	push   $0x48
 8048857:	e9 50 ff ff ff       	jmp    80487ac <_init+0x30>

0804885c <calloc@plt>:
 804885c:	ff 25 14 b1 04 08    	jmp    *0x804b114
 8048862:	68 50 00 00 00       	push   $0x50
 8048867:	e9 40 ff ff ff       	jmp    80487ac <_init+0x30>

0804886c <write@plt>:
 804886c:	ff 25 18 b1 04 08    	jmp    *0x804b118
 8048872:	68 58 00 00 00       	push   $0x58
 8048877:	e9 30 ff ff ff       	jmp    80487ac <_init+0x30>

0804887c <memset@plt>:
 804887c:	ff 25 1c b1 04 08    	jmp    *0x804b11c
 8048882:	68 60 00 00 00       	push   $0x60
 8048887:	e9 20 ff ff ff       	jmp    80487ac <_init+0x30>

0804888c <__libc_start_main@plt>:
 804888c:	ff 25 20 b1 04 08    	jmp    *0x804b120
 8048892:	68 68 00 00 00       	push   $0x68
 8048897:	e9 10 ff ff ff       	jmp    80487ac <_init+0x30>

0804889c <_IO_getc@plt>:
 804889c:	ff 25 24 b1 04 08    	jmp    *0x804b124
 80488a2:	68 70 00 00 00       	push   $0x70
 80488a7:	e9 00 ff ff ff       	jmp    80487ac <_init+0x30>

080488ac <read@plt>:
 80488ac:	ff 25 28 b1 04 08    	jmp    *0x804b128
 80488b2:	68 78 00 00 00       	push   $0x78
 80488b7:	e9 f0 fe ff ff       	jmp    80487ac <_init+0x30>

080488bc <socket@plt>:
 80488bc:	ff 25 2c b1 04 08    	jmp    *0x804b12c
 80488c2:	68 80 00 00 00       	push   $0x80
 80488c7:	e9 e0 fe ff ff       	jmp    80487ac <_init+0x30>

080488cc <bcopy@plt>:
 80488cc:	ff 25 30 b1 04 08    	jmp    *0x804b130
 80488d2:	68 88 00 00 00       	push   $0x88
 80488d7:	e9 d0 fe ff ff       	jmp    80487ac <_init+0x30>

080488dc <getopt@plt>:
 80488dc:	ff 25 34 b1 04 08    	jmp    *0x804b134
 80488e2:	68 90 00 00 00       	push   $0x90
 80488e7:	e9 c0 fe ff ff       	jmp    80487ac <_init+0x30>

080488ec <memcpy@plt>:
 80488ec:	ff 25 38 b1 04 08    	jmp    *0x804b138
 80488f2:	68 98 00 00 00       	push   $0x98
 80488f7:	e9 b0 fe ff ff       	jmp    80487ac <_init+0x30>

080488fc <fopen@plt>:
 80488fc:	ff 25 3c b1 04 08    	jmp    *0x804b13c
 8048902:	68 a0 00 00 00       	push   $0xa0
 8048907:	e9 a0 fe ff ff       	jmp    80487ac <_init+0x30>

0804890c <alarm@plt>:
 804890c:	ff 25 40 b1 04 08    	jmp    *0x804b140
 8048912:	68 a8 00 00 00       	push   $0xa8
 8048917:	e9 90 fe ff ff       	jmp    80487ac <_init+0x30>

0804891c <strcpy@plt>:
 804891c:	ff 25 44 b1 04 08    	jmp    *0x804b144
 8048922:	68 b0 00 00 00       	push   $0xb0
 8048927:	e9 80 fe ff ff       	jmp    80487ac <_init+0x30>

0804892c <printf@plt>:
 804892c:	ff 25 48 b1 04 08    	jmp    *0x804b148
 8048932:	68 b8 00 00 00       	push   $0xb8
 8048937:	e9 70 fe ff ff       	jmp    80487ac <_init+0x30>

0804893c <strcasecmp@plt>:
 804893c:	ff 25 4c b1 04 08    	jmp    *0x804b14c
 8048942:	68 c0 00 00 00       	push   $0xc0
 8048947:	e9 60 fe ff ff       	jmp    80487ac <_init+0x30>

0804894c <srandom@plt>:
 804894c:	ff 25 50 b1 04 08    	jmp    *0x804b150
 8048952:	68 c8 00 00 00       	push   $0xc8
 8048957:	e9 50 fe ff ff       	jmp    80487ac <_init+0x30>

0804895c <close@plt>:
 804895c:	ff 25 54 b1 04 08    	jmp    *0x804b154
 8048962:	68 d0 00 00 00       	push   $0xd0
 8048967:	e9 40 fe ff ff       	jmp    80487ac <_init+0x30>

0804896c <fwrite@plt>:
 804896c:	ff 25 58 b1 04 08    	jmp    *0x804b158
 8048972:	68 d8 00 00 00       	push   $0xd8
 8048977:	e9 30 fe ff ff       	jmp    80487ac <_init+0x30>

0804897c <fprintf@plt>:
 804897c:	ff 25 5c b1 04 08    	jmp    *0x804b15c
 8048982:	68 e0 00 00 00       	push   $0xe0
 8048987:	e9 20 fe ff ff       	jmp    80487ac <_init+0x30>

0804898c <gethostname@plt>:
 804898c:	ff 25 60 b1 04 08    	jmp    *0x804b160
 8048992:	68 e8 00 00 00       	push   $0xe8
 8048997:	e9 10 fe ff ff       	jmp    80487ac <_init+0x30>

0804899c <puts@plt>:
 804899c:	ff 25 64 b1 04 08    	jmp    *0x804b164
 80489a2:	68 f0 00 00 00       	push   $0xf0
 80489a7:	e9 00 fe ff ff       	jmp    80487ac <_init+0x30>

080489ac <rand@plt>:
 80489ac:	ff 25 68 b1 04 08    	jmp    *0x804b168
 80489b2:	68 f8 00 00 00       	push   $0xf8
 80489b7:	e9 f0 fd ff ff       	jmp    80487ac <_init+0x30>

080489bc <munmap@plt>:
 80489bc:	ff 25 6c b1 04 08    	jmp    *0x804b16c
 80489c2:	68 00 01 00 00       	push   $0x100
 80489c7:	e9 e0 fd ff ff       	jmp    80487ac <_init+0x30>

080489cc <gethostbyname@plt>:
 80489cc:	ff 25 70 b1 04 08    	jmp    *0x804b170
 80489d2:	68 08 01 00 00       	push   $0x108
 80489d7:	e9 d0 fd ff ff       	jmp    80487ac <_init+0x30>

080489dc <__strdup@plt>:
 80489dc:	ff 25 74 b1 04 08    	jmp    *0x804b174
 80489e2:	68 10 01 00 00       	push   $0x110
 80489e7:	e9 c0 fd ff ff       	jmp    80487ac <_init+0x30>

080489ec <exit@plt>:
 80489ec:	ff 25 78 b1 04 08    	jmp    *0x804b178
 80489f2:	68 18 01 00 00       	push   $0x118
 80489f7:	e9 b0 fd ff ff       	jmp    80487ac <_init+0x30>

Disassembly of section .text:

08048a00 <_start>:
 8048a00:	31 ed                	xor    %ebp,%ebp
 8048a02:	5e                   	pop    %esi
 8048a03:	89 e1                	mov    %esp,%ecx
 8048a05:	83 e4 f0             	and    $0xfffffff0,%esp
 8048a08:	50                   	push   %eax
 8048a09:	54                   	push   %esp
 8048a0a:	52                   	push   %edx
 8048a0b:	68 f0 9f 04 08       	push   $0x8049ff0
 8048a10:	68 00 a0 04 08       	push   $0x804a000
 8048a15:	51                   	push   %ecx
 8048a16:	56                   	push   %esi
 8048a17:	68 48 8f 04 08       	push   $0x8048f48
 8048a1c:	e8 6b fe ff ff       	call   804888c <__libc_start_main@plt>
 8048a21:	f4                   	hlt    
 8048a22:	90                   	nop
 8048a23:	90                   	nop
 8048a24:	90                   	nop
 8048a25:	90                   	nop
 8048a26:	90                   	nop
 8048a27:	90                   	nop
 8048a28:	90                   	nop
 8048a29:	90                   	nop
 8048a2a:	90                   	nop
 8048a2b:	90                   	nop
 8048a2c:	90                   	nop
 8048a2d:	90                   	nop
 8048a2e:	90                   	nop
 8048a2f:	90                   	nop

08048a30 <__do_global_dtors_aux>:
 8048a30:	55                   	push   %ebp
 8048a31:	89 e5                	mov    %esp,%ebp
 8048a33:	53                   	push   %ebx
 8048a34:	83 ec 04             	sub    $0x4,%esp
 8048a37:	80 3d 0c b3 04 08 00 	cmpb   $0x0,0x804b30c
 8048a3e:	75 3f                	jne    8048a7f <__do_global_dtors_aux+0x4f>
 8048a40:	a1 10 b3 04 08       	mov    0x804b310,%eax
 8048a45:	bb 0c b0 04 08       	mov    $0x804b00c,%ebx
 8048a4a:	81 eb 08 b0 04 08    	sub    $0x804b008,%ebx
 8048a50:	c1 fb 02             	sar    $0x2,%ebx
 8048a53:	83 eb 01             	sub    $0x1,%ebx
 8048a56:	39 d8                	cmp    %ebx,%eax
 8048a58:	73 1e                	jae    8048a78 <__do_global_dtors_aux+0x48>
 8048a5a:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
 8048a60:	83 c0 01             	add    $0x1,%eax
 8048a63:	a3 10 b3 04 08       	mov    %eax,0x804b310
 8048a68:	ff 14 85 08 b0 04 08 	call   *0x804b008(,%eax,4)
 8048a6f:	a1 10 b3 04 08       	mov    0x804b310,%eax
 8048a74:	39 d8                	cmp    %ebx,%eax
 8048a76:	72 e8                	jb     8048a60 <__do_global_dtors_aux+0x30>
 8048a78:	c6 05 0c b3 04 08 01 	movb   $0x1,0x804b30c
 8048a7f:	83 c4 04             	add    $0x4,%esp
 8048a82:	5b                   	pop    %ebx
 8048a83:	5d                   	pop    %ebp
 8048a84:	c3                   	ret    
 8048a85:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
 8048a89:	8d bc 27 00 00 00 00 	lea    0x0(%edi,%eiz,1),%edi

08048a90 <frame_dummy>:
 8048a90:	55                   	push   %ebp
 8048a91:	89 e5                	mov    %esp,%ebp
 8048a93:	83 ec 18             	sub    $0x18,%esp
 8048a96:	a1 10 b0 04 08       	mov    0x804b010,%eax
 8048a9b:	85 c0                	test   %eax,%eax
 8048a9d:	74 12                	je     8048ab1 <frame_dummy+0x21>
 8048a9f:	b8 00 00 00 00       	mov    $0x0,%eax
 8048aa4:	85 c0                	test   %eax,%eax
 8048aa6:	74 09                	je     8048ab1 <frame_dummy+0x21>
 8048aa8:	c7 04 24 10 b0 04 08 	movl   $0x804b010,(%esp)
 8048aaf:	ff d0                	call   *%eax
 8048ab1:	c9                   	leave  
 8048ab2:	c3                   	ret    
 8048ab3:	90                   	nop
 8048ab4:	90                   	nop
 8048ab5:	90                   	nop
 8048ab6:	90                   	nop
 8048ab7:	90                   	nop
 8048ab8:	90                   	nop
 8048ab9:	90                   	nop
 8048aba:	90                   	nop
 8048abb:	90                   	nop
 8048abc:	90                   	nop
 8048abd:	90                   	nop
 8048abe:	90                   	nop
 8048abf:	90                   	nop

08048ac0 <usage>:
 8048ac0:	55                   	push   %ebp
 8048ac1:	89 e5                	mov    %esp,%ebp
 8048ac3:	83 ec 18             	sub    $0x18,%esp
 8048ac6:	89 44 24 04          	mov    %eax,0x4(%esp)
 8048aca:	c7 04 24 b4 a0 04 08 	movl   $0x804a0b4,(%esp)
 8048ad1:	e8 56 fe ff ff       	call   804892c <printf@plt>
 8048ad6:	c7 04 24 d8 a0 04 08 	movl   $0x804a0d8,(%esp)
 8048add:	e8 ba fe ff ff       	call   804899c <puts@plt>
 8048ae2:	c7 04 24 6e a2 04 08 	movl   $0x804a26e,(%esp)
 8048ae9:	e8 ae fe ff ff       	call   804899c <puts@plt>
 8048aee:	c7 04 24 fc a0 04 08 	movl   $0x804a0fc,(%esp)
 8048af5:	e8 a2 fe ff ff       	call   804899c <puts@plt>
 8048afa:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
 8048b01:	e8 e6 fe ff ff       	call   80489ec <exit@plt>

08048b06 <illegalhandler>:
 8048b06:	55                   	push   %ebp
 8048b07:	89 e5                	mov    %esp,%ebp
 8048b09:	83 ec 18             	sub    $0x18,%esp
 8048b0c:	c7 04 24 20 a1 04 08 	movl   $0x804a120,(%esp)
 8048b13:	e8 84 fe ff ff       	call   804899c <puts@plt>
 8048b18:	c7 04 24 85 a2 04 08 	movl   $0x804a285,(%esp)
 8048b1f:	e8 78 fe ff ff       	call   804899c <puts@plt>
 8048b24:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
 8048b2b:	e8 bc fe ff ff       	call   80489ec <exit@plt>

08048b30 <seghandler>:
 8048b30:	55                   	push   %ebp
 8048b31:	89 e5                	mov    %esp,%ebp
 8048b33:	83 ec 18             	sub    $0x18,%esp
 8048b36:	c7 04 24 4c a1 04 08 	movl   $0x804a14c,(%esp)
 8048b3d:	e8 5a fe ff ff       	call   804899c <puts@plt>
 8048b42:	c7 04 24 85 a2 04 08 	movl   $0x804a285,(%esp)
 8048b49:	e8 4e fe ff ff       	call   804899c <puts@plt>
 8048b4e:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
 8048b55:	e8 92 fe ff ff       	call   80489ec <exit@plt>

08048b5a <bushandler>:
 8048b5a:	55                   	push   %ebp
 8048b5b:	89 e5                	mov    %esp,%ebp
 8048b5d:	83 ec 18             	sub    $0x18,%esp
 8048b60:	c7 04 24 74 a1 04 08 	movl   $0x804a174,(%esp)
 8048b67:	e8 30 fe ff ff       	call   804899c <puts@plt>
 8048b6c:	c7 04 24 85 a2 04 08 	movl   $0x804a285,(%esp)
 8048b73:	e8 24 fe ff ff       	call   804899c <puts@plt>
 8048b78:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
 8048b7f:	e8 68 fe ff ff       	call   80489ec <exit@plt>

08048b84 <uniqueval>:
 8048b84:	55                   	push   %ebp
 8048b85:	89 e5                	mov    %esp,%ebp
 8048b87:	83 ec 18             	sub    $0x18,%esp
 8048b8a:	e8 7d fc ff ff       	call   804880c <getpid@plt>
 8048b8f:	89 04 24             	mov    %eax,(%esp)
 8048b92:	e8 b5 fd ff ff       	call   804894c <srandom@plt>
 8048b97:	e8 80 fc ff ff       	call   804881c <random@plt>
 8048b9c:	c9                   	leave  
 8048b9d:	c3                   	ret    

08048b9e <Gets>:
 8048b9e:	55                   	push   %ebp
 8048b9f:	89 e5                	mov    %esp,%ebp
 8048ba1:	57                   	push   %edi
 8048ba2:	56                   	push   %esi
 8048ba3:	53                   	push   %ebx
 8048ba4:	83 ec 2c             	sub    $0x2c,%esp
 8048ba7:	c7 05 28 b3 04 08 00 	movl   $0x0,0x804b328
 8048bae:	00 00 00 
 8048bb1:	8b 5d 08             	mov    0x8(%ebp),%ebx
 8048bb4:	be a9 a3 04 08       	mov    $0x804a3a9,%esi
 8048bb9:	eb 4d                	jmp    8048c08 <Gets+0x6a>
 8048bbb:	88 45 d8             	mov    %al,-0x28(%ebp)
 8048bbe:	88 03                	mov    %al,(%ebx)
 8048bc0:	a1 28 b3 04 08       	mov    0x804b328,%eax
 8048bc5:	3d ff 03 00 00       	cmp    $0x3ff,%eax
 8048bca:	7f 39                	jg     8048c05 <Gets+0x67>
 8048bcc:	8d 14 40             	lea    (%eax,%eax,2),%edx
 8048bcf:	0f b6 4d d8          	movzbl -0x28(%ebp),%ecx
 8048bd3:	c0 e9 04             	shr    $0x4,%cl
 8048bd6:	0f be f9             	movsbl %cl,%edi
 8048bd9:	0f b6 3c 3e          	movzbl (%esi,%edi,1),%edi
 8048bdd:	89 f9                	mov    %edi,%ecx
 8048bdf:	88 8a 40 b3 04 08    	mov    %cl,0x804b340(%edx)
 8048be5:	0f b6 4d d8          	movzbl -0x28(%ebp),%ecx
 8048be9:	83 e1 0f             	and    $0xf,%ecx
 8048bec:	0f b6 0c 0e          	movzbl (%esi,%ecx,1),%ecx
 8048bf0:	88 8a 41 b3 04 08    	mov    %cl,0x804b341(%edx)
 8048bf6:	c6 82 42 b3 04 08 20 	movb   $0x20,0x804b342(%edx)
 8048bfd:	83 c0 01             	add    $0x1,%eax
 8048c00:	a3 28 b3 04 08       	mov    %eax,0x804b328
 8048c05:	83 c3 01             	add    $0x1,%ebx
 8048c08:	a1 14 b3 04 08       	mov    0x804b314,%eax
 8048c0d:	89 04 24             	mov    %eax,(%esp)
 8048c10:	e8 87 fc ff ff       	call   804889c <_IO_getc@plt>
 8048c15:	83 f8 ff             	cmp    $0xffffffff,%eax
 8048c18:	74 05                	je     8048c1f <Gets+0x81>
 8048c1a:	83 f8 0a             	cmp    $0xa,%eax
 8048c1d:	75 9c                	jne    8048bbb <Gets+0x1d>
 8048c1f:	c6 03 00             	movb   $0x0,(%ebx)
 8048c22:	a1 28 b3 04 08       	mov    0x804b328,%eax
 8048c27:	c6 84 40 40 b3 04 08 	movb   $0x0,0x804b340(%eax,%eax,2)
 8048c2e:	00 
 8048c2f:	8b 45 08             	mov    0x8(%ebp),%eax
 8048c32:	83 c4 2c             	add    $0x2c,%esp
 8048c35:	5b                   	pop    %ebx
 8048c36:	5e                   	pop    %esi
 8048c37:	5f                   	pop    %edi
 8048c38:	5d                   	pop    %ebp
 8048c39:	c3                   	ret    

08048c3a <testn>:
 8048c3a:	55                   	push   %ebp
 8048c3b:	89 e5                	mov    %esp,%ebp
 8048c3d:	53                   	push   %ebx
 8048c3e:	83 ec 24             	sub    $0x24,%esp
 8048c41:	e8 3e ff ff ff       	call   8048b84 <uniqueval>
 8048c46:	89 45 f4             	mov    %eax,-0xc(%ebp)
 8048c49:	e8 32 05 00 00       	call   8049180 <getbufn>
 8048c4e:	89 c3                	mov    %eax,%ebx
 8048c50:	e8 2f ff ff ff       	call   8048b84 <uniqueval>
 8048c55:	8b 55 f4             	mov    -0xc(%ebp),%edx
 8048c58:	39 d0                	cmp    %edx,%eax
 8048c5a:	74 0e                	je     8048c6a <testn+0x30>
 8048c5c:	c7 04 24 94 a1 04 08 	movl   $0x804a194,(%esp)
 8048c63:	e8 34 fd ff ff       	call   804899c <puts@plt>
 8048c68:	eb 36                	jmp    8048ca0 <testn+0x66>
 8048c6a:	3b 1d 18 b3 04 08    	cmp    0x804b318,%ebx
 8048c70:	75 1e                	jne    8048c90 <testn+0x56>
 8048c72:	89 5c 24 04          	mov    %ebx,0x4(%esp)
 8048c76:	c7 04 24 c0 a1 04 08 	movl   $0x804a1c0,(%esp)
 8048c7d:	e8 aa fc ff ff       	call   804892c <printf@plt>
 8048c82:	c7 04 24 04 00 00 00 	movl   $0x4,(%esp)
 8048c89:	e8 a1 05 00 00       	call   804922f <validate>
 8048c8e:	eb 10                	jmp    8048ca0 <testn+0x66>
 8048c90:	89 5c 24 04          	mov    %ebx,0x4(%esp)
 8048c94:	c7 04 24 9b a2 04 08 	movl   $0x804a29b,(%esp)
 8048c9b:	e8 8c fc ff ff       	call   804892c <printf@plt>
 8048ca0:	83 c4 24             	add    $0x24,%esp
 8048ca3:	5b                   	pop    %ebx
 8048ca4:	5d                   	pop    %ebp
 8048ca5:	c3                   	ret    

08048ca6 <bang>:
 8048ca6:	55                   	push   %ebp
 8048ca7:	89 e5                	mov    %esp,%ebp
 8048ca9:	83 ec 18             	sub    $0x18,%esp
 8048cac:	a1 24 b3 04 08       	mov    0x804b324,%eax
 8048cb1:	3b 05 18 b3 04 08    	cmp    0x804b318,%eax
 8048cb7:	75 1e                	jne    8048cd7 <bang+0x31>
 8048cb9:	89 44 24 04          	mov    %eax,0x4(%esp)
 8048cbd:	c7 04 24 e0 a1 04 08 	movl   $0x804a1e0,(%esp)
 8048cc4:	e8 63 fc ff ff       	call   804892c <printf@plt>
 8048cc9:	c7 04 24 02 00 00 00 	movl   $0x2,(%esp)
 8048cd0:	e8 5a 05 00 00       	call   804922f <validate>
 8048cd5:	eb 10                	jmp    8048ce7 <bang+0x41>
 8048cd7:	89 44 24 04          	mov    %eax,0x4(%esp)
 8048cdb:	c7 04 24 b7 a2 04 08 	movl   $0x804a2b7,(%esp)
 8048ce2:	e8 45 fc ff ff       	call   804892c <printf@plt>
 8048ce7:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
 8048cee:	e8 f9 fc ff ff       	call   80489ec <exit@plt>

08048cf3 <fizz>:
 8048cf3:	55                   	push   %ebp
 8048cf4:	89 e5                	mov    %esp,%ebp
 8048cf6:	83 ec 18             	sub    $0x18,%esp
 8048cf9:	8b 45 08             	mov    0x8(%ebp),%eax
 8048cfc:	3b 05 18 b3 04 08    	cmp    0x804b318,%eax
 8048d02:	75 1e                	jne    8048d22 <fizz+0x2f>
 8048d04:	89 44 24 04          	mov    %eax,0x4(%esp)
 8048d08:	c7 04 24 d5 a2 04 08 	movl   $0x804a2d5,(%esp)
 8048d0f:	e8 18 fc ff ff       	call   804892c <printf@plt>
 8048d14:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
 8048d1b:	e8 0f 05 00 00       	call   804922f <validate>
 8048d20:	eb 10                	jmp    8048d32 <fizz+0x3f>
 8048d22:	89 44 24 04          	mov    %eax,0x4(%esp)
 8048d26:	c7 04 24 08 a2 04 08 	movl   $0x804a208,(%esp)
 8048d2d:	e8 fa fb ff ff       	call   804892c <printf@plt>
 8048d32:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
 8048d39:	e8 ae fc ff ff       	call   80489ec <exit@plt>

08048d3e <smoke>:
 8048d3e:	55                   	push   %ebp
 8048d3f:	89 e5                	mov    %esp,%ebp
 8048d41:	83 ec 18             	sub    $0x18,%esp
 8048d44:	c7 04 24 f3 a2 04 08 	movl   $0x804a2f3,(%esp)
 8048d4b:	e8 4c fc ff ff       	call   804899c <puts@plt>
 8048d50:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
 8048d57:	e8 d3 04 00 00       	call   804922f <validate>
 8048d5c:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
 8048d63:	e8 84 fc ff ff       	call   80489ec <exit@plt>

08048d68 <test>:
 8048d68:	55                   	push   %ebp
 8048d69:	89 e5                	mov    %esp,%ebp
 8048d6b:	53                   	push   %ebx
 8048d6c:	83 ec 24             	sub    $0x24,%esp
 8048d6f:	e8 10 fe ff ff       	call   8048b84 <uniqueval>
 8048d74:	89 45 f4             	mov    %eax,-0xc(%ebp)
 8048d77:	e8 22 04 00 00       	call   804919e <getbuf>
 8048d7c:	89 c3                	mov    %eax,%ebx
 8048d7e:	e8 01 fe ff ff       	call   8048b84 <uniqueval>
 8048d83:	8b 55 f4             	mov    -0xc(%ebp),%edx
 8048d86:	39 d0                	cmp    %edx,%eax
 8048d88:	74 0e                	je     8048d98 <test+0x30>
 8048d8a:	c7 04 24 94 a1 04 08 	movl   $0x804a194,(%esp)
 8048d91:	e8 06 fc ff ff       	call   804899c <puts@plt>
 8048d96:	eb 36                	jmp    8048dce <test+0x66>
 8048d98:	3b 1d 18 b3 04 08    	cmp    0x804b318,%ebx
 8048d9e:	75 1e                	jne    8048dbe <test+0x56>
 8048da0:	89 5c 24 04          	mov    %ebx,0x4(%esp)
 8048da4:	c7 04 24 0e a3 04 08 	movl   $0x804a30e,(%esp)
 8048dab:	e8 7c fb ff ff       	call   804892c <printf@plt>
 8048db0:	c7 04 24 03 00 00 00 	movl   $0x3,(%esp)
 8048db7:	e8 73 04 00 00       	call   804922f <validate>
 8048dbc:	eb 10                	jmp    8048dce <test+0x66>
 8048dbe:	89 5c 24 04          	mov    %ebx,0x4(%esp)
 8048dc2:	c7 04 24 2b a3 04 08 	movl   $0x804a32b,(%esp)
 8048dc9:	e8 5e fb ff ff       	call   804892c <printf@plt>
 8048dce:	83 c4 24             	add    $0x24,%esp
 8048dd1:	5b                   	pop    %ebx
 8048dd2:	5d                   	pop    %ebp
 8048dd3:	c3                   	ret    

08048dd4 <launch>:
 8048dd4:	55                   	push   %ebp
 8048dd5:	89 e5                	mov    %esp,%ebp
 8048dd7:	53                   	push   %ebx
 8048dd8:	83 ec 54             	sub    $0x54,%esp
 8048ddb:	89 c3                	mov    %eax,%ebx
 8048ddd:	8d 45 b8             	lea    -0x48(%ebp),%eax
 8048de0:	25 f8 3f 00 00       	and    $0x3ff8,%eax
 8048de5:	01 c2                	add    %eax,%edx
 8048de7:	8d 42 1e             	lea    0x1e(%edx),%eax
 8048dea:	83 e0 f0             	and    $0xfffffff0,%eax
 8048ded:	29 c4                	sub    %eax,%esp
 8048def:	8d 44 24 1b          	lea    0x1b(%esp),%eax
 8048df3:	83 e0 f0             	and    $0xfffffff0,%eax
 8048df6:	89 54 24 08          	mov    %edx,0x8(%esp)
 8048dfa:	c7 44 24 04 f4 00 00 	movl   $0xf4,0x4(%esp)
 8048e01:	00 
 8048e02:	89 04 24             	mov    %eax,(%esp)
 8048e05:	e8 72 fa ff ff       	call   804887c <memset@plt>
 8048e0a:	c7 04 24 46 a3 04 08 	movl   $0x804a346,(%esp)
 8048e11:	e8 16 fb ff ff       	call   804892c <printf@plt>
 8048e16:	85 db                	test   %ebx,%ebx
 8048e18:	74 08                	je     8048e22 <launch+0x4e>
 8048e1a:	e8 1b fe ff ff       	call   8048c3a <testn>
 8048e1f:	90                   	nop
 8048e20:	eb 05                	jmp    8048e27 <launch+0x53>
 8048e22:	e8 41 ff ff ff       	call   8048d68 <test>
 8048e27:	83 3d 20 b3 04 08 00 	cmpl   $0x0,0x804b320
 8048e2e:	75 16                	jne    8048e46 <launch+0x72>
 8048e30:	c7 04 24 85 a2 04 08 	movl   $0x804a285,(%esp)
 8048e37:	e8 60 fb ff ff       	call   804899c <puts@plt>
 8048e3c:	c7 05 20 b3 04 08 00 	movl   $0x0,0x804b320
 8048e43:	00 00 00 
 8048e46:	8b 5d fc             	mov    -0x4(%ebp),%ebx
 8048e49:	c9                   	leave  
 8048e4a:	c3                   	ret    

08048e4b <launcher>:
 8048e4b:	55                   	push   %ebp
 8048e4c:	89 e5                	mov    %esp,%ebp
 8048e4e:	53                   	push   %ebx
 8048e4f:	83 ec 24             	sub    $0x24,%esp
 8048e52:	8b 45 08             	mov    0x8(%ebp),%eax
 8048e55:	a3 2c b3 04 08       	mov    %eax,0x804b32c
 8048e5a:	8b 45 0c             	mov    0xc(%ebp),%eax
 8048e5d:	a3 30 b3 04 08       	mov    %eax,0x804b330
 8048e62:	c7 44 24 14 00 00 00 	movl   $0x0,0x14(%esp)
 8048e69:	00 
 8048e6a:	c7 44 24 10 00 00 00 	movl   $0x0,0x10(%esp)
 8048e71:	00 
 8048e72:	c7 44 24 0c 22 01 00 	movl   $0x122,0xc(%esp)
 8048e79:	00 
 8048e7a:	c7 44 24 08 07 00 00 	movl   $0x7,0x8(%esp)
 8048e81:	00 
 8048e82:	c7 44 24 04 00 00 10 	movl   $0x100000,0x4(%esp)
 8048e89:	00 
 8048e8a:	c7 04 24 00 60 58 55 	movl   $0x55586000,(%esp)
 8048e91:	e8 66 f9 ff ff       	call   80487fc <mmap@plt>
 8048e96:	89 c3                	mov    %eax,%ebx
 8048e98:	83 f8 ff             	cmp    $0xffffffff,%eax
 8048e9b:	75 31                	jne    8048ece <launcher+0x83>
 8048e9d:	a1 00 b3 04 08       	mov    0x804b300,%eax
 8048ea2:	89 44 24 0c          	mov    %eax,0xc(%esp)
 8048ea6:	c7 44 24 08 23 00 00 	movl   $0x23,0x8(%esp)
 8048ead:	00 
 8048eae:	c7 44 24 04 01 00 00 	movl   $0x1,0x4(%esp)
 8048eb5:	00 
 8048eb6:	c7 04 24 28 a2 04 08 	movl   $0x804a228,(%esp)
 8048ebd:	e8 aa fa ff ff       	call   804896c <fwrite@plt>
 8048ec2:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
 8048ec9:	e8 1e fb ff ff       	call   80489ec <exit@plt>
 8048ece:	8d 90 f8 ff 0f 00    	lea    0xffff8(%eax),%edx
 8048ed4:	89 15 44 bf 04 08    	mov    %edx,0x804bf44
 8048eda:	89 e0                	mov    %esp,%eax
 8048edc:	89 d4                	mov    %edx,%esp
 8048ede:	89 c2                	mov    %eax,%edx
 8048ee0:	89 15 34 b3 04 08    	mov    %edx,0x804b334
 8048ee6:	8b 15 30 b3 04 08    	mov    0x804b330,%edx
 8048eec:	a1 2c b3 04 08       	mov    0x804b32c,%eax
 8048ef1:	e8 de fe ff ff       	call   8048dd4 <launch>
 8048ef6:	a1 34 b3 04 08       	mov    0x804b334,%eax
 8048efb:	89 c4                	mov    %eax,%esp
 8048efd:	c7 44 24 04 00 00 10 	movl   $0x100000,0x4(%esp)
 8048f04:	00 
 8048f05:	89 1c 24             	mov    %ebx,(%esp)
 8048f08:	e8 af fa ff ff       	call   80489bc <munmap@plt>
 8048f0d:	85 c0                	test   %eax,%eax
 8048f0f:	79 31                	jns    8048f42 <launcher+0xf7>
 8048f11:	a1 00 b3 04 08       	mov    0x804b300,%eax
 8048f16:	89 44 24 0c          	mov    %eax,0xc(%esp)
 8048f1a:	c7 44 24 08 1d 00 00 	movl   $0x1d,0x8(%esp)
 8048f21:	00 
 8048f22:	c7 44 24 04 01 00 00 	movl   $0x1,0x4(%esp)
 8048f29:	00 
 8048f2a:	c7 04 24 53 a3 04 08 	movl   $0x804a353,(%esp)
 8048f31:	e8 36 fa ff ff       	call   804896c <fwrite@plt>
 8048f36:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
 8048f3d:	e8 aa fa ff ff       	call   80489ec <exit@plt>
 8048f42:	83 c4 24             	add    $0x24,%esp
 8048f45:	5b                   	pop    %ebx
 8048f46:	5d                   	pop    %ebp
 8048f47:	c3                   	ret    

08048f48 <main>:
 8048f48:	55                   	push   %ebp
 8048f49:	89 e5                	mov    %esp,%ebp
 8048f4b:	83 e4 f0             	and    $0xfffffff0,%esp
 8048f4e:	57                   	push   %edi
 8048f4f:	56                   	push   %esi
 8048f50:	53                   	push   %ebx
 8048f51:	83 ec 34             	sub    $0x34,%esp
 8048f54:	8b 75 08             	mov    0x8(%ebp),%esi
 8048f57:	8b 5d 0c             	mov    0xc(%ebp),%ebx
 8048f5a:	c7 44 24 04 30 8b 04 	movl   $0x8048b30,0x4(%esp)
 8048f61:	08 
 8048f62:	c7 04 24 0b 00 00 00 	movl   $0xb,(%esp)
 8048f69:	e8 be f8 ff ff       	call   804882c <signal@plt>
 8048f6e:	c7 44 24 04 5a 8b 04 	movl   $0x8048b5a,0x4(%esp)
 8048f75:	08 
 8048f76:	c7 04 24 07 00 00 00 	movl   $0x7,(%esp)
 8048f7d:	e8 aa f8 ff ff       	call   804882c <signal@plt>
 8048f82:	c7 44 24 04 06 8b 04 	movl   $0x8048b06,0x4(%esp)
 8048f89:	08 
 8048f8a:	c7 04 24 04 00 00 00 	movl   $0x4,(%esp)
 8048f91:	e8 96 f8 ff ff       	call   804882c <signal@plt>
 8048f96:	e8 0a 04 00 00       	call   80493a5 <initialize_bomb>
 8048f9b:	a1 04 b3 04 08       	mov    0x804b304,%eax
 8048fa0:	a3 14 b3 04 08       	mov    %eax,0x804b314
 8048fa5:	bf 01 00 00 00       	mov    $0x1,%edi
 8048faa:	c7 44 24 2c 00 00 00 	movl   $0x0,0x2c(%esp)
 8048fb1:	00 
 8048fb2:	e9 d2 00 00 00       	jmp    8049089 <main+0x141>
 8048fb7:	3c 68                	cmp    $0x68,%al
 8048fb9:	74 39                	je     8048ff4 <main+0xac>
 8048fbb:	3c 68                	cmp    $0x68,%al
 8048fbd:	7f 0a                	jg     8048fc9 <main+0x81>
 8048fbf:	3c 66                	cmp    $0x66,%al
 8048fc1:	0f 85 bb 00 00 00    	jne    8049082 <main+0x13a>
 8048fc7:	eb 7d                	jmp    8049046 <main+0xfe>
 8048fc9:	3c 6e                	cmp    $0x6e,%al
 8048fcb:	90                   	nop
 8048fcc:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
 8048fd0:	74 10                	je     8048fe2 <main+0x9a>
 8048fd2:	3c 74                	cmp    $0x74,%al
 8048fd4:	0f 85 a8 00 00 00    	jne    8049082 <main+0x13a>
 8048fda:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
 8048fe0:	eb 1e                	jmp    8049000 <main+0xb8>
 8048fe2:	bf 05 00 00 00       	mov    $0x5,%edi
 8048fe7:	c7 44 24 2c 01 00 00 	movl   $0x1,0x2c(%esp)
 8048fee:	00 
 8048fef:	e9 95 00 00 00       	jmp    8049089 <main+0x141>
 8048ff4:	8b 03                	mov    (%ebx),%eax
 8048ff6:	e8 c5 fa ff ff       	call   8048ac0 <usage>
 8048ffb:	e9 89 00 00 00       	jmp    8049089 <main+0x141>
 8049000:	a1 08 b3 04 08       	mov    0x804b308,%eax
 8049005:	89 04 24             	mov    %eax,(%esp)
 8049008:	e8 cf f9 ff ff       	call   80489dc <__strdup@plt>
 804900d:	a3 1c b3 04 08       	mov    %eax,0x804b31c
 8049012:	89 44 24 04          	mov    %eax,0x4(%esp)
 8049016:	c7 04 24 71 a3 04 08 	movl   $0x804a371,(%esp)
 804901d:	e8 0a f9 ff ff       	call   804892c <printf@plt>
 8049022:	a1 1c b3 04 08       	mov    0x804b31c,%eax
 8049027:	89 04 24             	mov    %eax,(%esp)
 804902a:	e8 7e 0f 00 00       	call   8049fad <gencookie>
 804902f:	a3 18 b3 04 08       	mov    %eax,0x804b318
 8049034:	89 44 24 04          	mov    %eax,0x4(%esp)
 8049038:	c7 04 24 7d a3 04 08 	movl   $0x804a37d,(%esp)
 804903f:	e8 e8 f8 ff ff       	call   804892c <printf@plt>
 8049044:	eb 43                	jmp    8049089 <main+0x141>
 8049046:	c7 44 24 04 8b a3 04 	movl   $0x804a38b,0x4(%esp)
 804904d:	08 
 804904e:	a1 08 b3 04 08       	mov    0x804b308,%eax
 8049053:	89 04 24             	mov    %eax,(%esp)
 8049056:	e8 a1 f8 ff ff       	call   80488fc <fopen@plt>
 804905b:	a3 14 b3 04 08       	mov    %eax,0x804b314
 8049060:	85 c0                	test   %eax,%eax
 8049062:	75 25                	jne    8049089 <main+0x141>
 8049064:	a1 08 b3 04 08       	mov    0x804b308,%eax
 8049069:	89 44 24 04          	mov    %eax,0x4(%esp)
 804906d:	c7 04 24 8d a3 04 08 	movl   $0x804a38d,(%esp)
 8049074:	e8 b3 f8 ff ff       	call   804892c <printf@plt>
 8049079:	8b 03                	mov    (%ebx),%eax
 804907b:	e8 40 fa ff ff       	call   8048ac0 <usage>
 8049080:	eb 07                	jmp    8049089 <main+0x141>
 8049082:	8b 03                	mov    (%ebx),%eax
 8049084:	e8 37 fa ff ff       	call   8048ac0 <usage>
 8049089:	c7 44 24 08 a2 a3 04 	movl   $0x804a3a2,0x8(%esp)
 8049090:	08 
 8049091:	89 5c 24 04          	mov    %ebx,0x4(%esp)
 8049095:	89 34 24             	mov    %esi,(%esp)
 8049098:	e8 3f f8 ff ff       	call   80488dc <getopt@plt>
 804909d:	3c ff                	cmp    $0xff,%al
 804909f:	0f 85 12 ff ff ff    	jne    8048fb7 <main+0x6f>
 80490a5:	83 3d 1c b3 04 08 00 	cmpl   $0x0,0x804b31c
 80490ac:	75 13                	jne    80490c1 <main+0x179>
 80490ae:	c7 04 24 4c a2 04 08 	movl   $0x804a24c,(%esp)
 80490b5:	e8 e2 f8 ff ff       	call   804899c <puts@plt>
 80490ba:	8b 03                	mov    (%ebx),%eax
 80490bc:	e8 ff f9 ff ff       	call   8048ac0 <usage>
 80490c1:	a1 18 b3 04 08       	mov    0x804b318,%eax
 80490c6:	89 04 24             	mov    %eax,(%esp)
 80490c9:	e8 7e f8 ff ff       	call   804894c <srandom@plt>
 80490ce:	e8 49 f7 ff ff       	call   804881c <random@plt>
 80490d3:	25 f8 0f 00 00       	and    $0xff8,%eax
 80490d8:	89 44 24 28          	mov    %eax,0x28(%esp)
 80490dc:	89 7c 24 1c          	mov    %edi,0x1c(%esp)
 80490e0:	c7 44 24 04 04 00 00 	movl   $0x4,0x4(%esp)
 80490e7:	00 
 80490e8:	89 3c 24             	mov    %edi,(%esp)
 80490eb:	e8 6c f7 ff ff       	call   804885c <calloc@plt>
 80490f0:	89 c6                	mov    %eax,%esi
 80490f2:	89 44 24 20          	mov    %eax,0x20(%esp)
 80490f6:	8d 47 fe             	lea    -0x2(%edi),%eax
 80490f9:	89 44 24 24          	mov    %eax,0x24(%esp)
 80490fd:	85 c0                	test   %eax,%eax
 80490ff:	7e 21                	jle    8049122 <main+0x1da>
 8049101:	bb 00 00 00 00       	mov    $0x0,%ebx
 8049106:	89 7c 24 18          	mov    %edi,0x18(%esp)
 804910a:	89 c7                	mov    %eax,%edi
 804910c:	e8 0b f7 ff ff       	call   804881c <random@plt>
 8049111:	83 e0 38             	and    $0x38,%eax
 8049114:	89 04 9e             	mov    %eax,(%esi,%ebx,4)
 8049117:	83 c3 01             	add    $0x1,%ebx
 804911a:	39 fb                	cmp    %edi,%ebx
 804911c:	7c ee                	jl     804910c <main+0x1c4>
 804911e:	8b 7c 24 18          	mov    0x18(%esp),%edi
 8049122:	83 ff 01             	cmp    $0x1,%edi
 8049125:	7e 10                	jle    8049137 <main+0x1ef>
 8049127:	8b 54 24 1c          	mov    0x1c(%esp),%edx
 804912b:	8b 44 24 20          	mov    0x20(%esp),%eax
 804912f:	c7 44 90 f8 38 00 00 	movl   $0x38,-0x8(%eax,%edx,4)
 8049136:	00 
 8049137:	8b 54 24 1c          	mov    0x1c(%esp),%edx
 804913b:	8b 44 24 20          	mov    0x20(%esp),%eax
 804913f:	c7 44 90 fc 00 00 00 	movl   $0x0,-0x4(%eax,%edx,4)
 8049146:	00 
 8049147:	85 ff                	test   %edi,%edi
 8049149:	7e 23                	jle    804916e <main+0x226>
 804914b:	bb 00 00 00 00       	mov    $0x0,%ebx
 8049150:	8b 44 24 28          	mov    0x28(%esp),%eax
 8049154:	03 04 9e             	add    (%esi,%ebx,4),%eax
 8049157:	89 44 24 04          	mov    %eax,0x4(%esp)
 804915b:	8b 54 24 2c          	mov    0x2c(%esp),%edx
 804915f:	89 14 24             	mov    %edx,(%esp)
 8049162:	e8 e4 fc ff ff       	call   8048e4b <launcher>
 8049167:	83 c3 01             	add    $0x1,%ebx
 804916a:	39 df                	cmp    %ebx,%edi
 804916c:	7f e2                	jg     8049150 <main+0x208>
 804916e:	b8 00 00 00 00       	mov    $0x0,%eax
 8049173:	83 c4 34             	add    $0x34,%esp
 8049176:	5b                   	pop    %ebx
 8049177:	5e                   	pop    %esi
 8049178:	5f                   	pop    %edi
 8049179:	89 ec                	mov    %ebp,%esp
 804917b:	5d                   	pop    %ebp
 804917c:	c3                   	ret    
 804917d:	90                   	nop
 804917e:	90                   	nop
 804917f:	90                   	nop

08049180 <getbufn>:
 8049180:	55                   	push   %ebp
 8049181:	89 e5                	mov    %esp,%ebp
 8049183:	81 ec 18 02 00 00    	sub    $0x218,%esp
 8049189:	8d 85 f8 fd ff ff    	lea    -0x208(%ebp),%eax
 804918f:	89 04 24             	mov    %eax,(%esp)
 8049192:	e8 07 fa ff ff       	call   8048b9e <Gets>
 8049197:	b8 01 00 00 00       	mov    $0x1,%eax
 804919c:	c9                   	leave  
 804919d:	c3                   	ret    

0804919e <getbuf>:
 804919e:	55                   	push   %ebp
 804919f:	89 e5                	mov    %esp,%ebp
 80491a1:	83 ec 38             	sub    $0x38,%esp
 80491a4:	8d 45 d8             	lea    -0x28(%ebp),%eax
 80491a7:	89 04 24             	mov    %eax,(%esp)
 80491aa:	e8 ef f9 ff ff       	call   8048b9e <Gets>
 80491af:	b8 01 00 00 00       	mov    $0x1,%eax
 80491b4:	c9                   	leave  
 80491b5:	c3                   	ret    
 80491b6:	90                   	nop
 80491b7:	90                   	nop

080491b8 <server_check>:
 80491b8:	55                   	push   %ebp
 80491b9:	89 e5                	mov    %esp,%ebp
 80491bb:	83 ec 18             	sub    $0x18,%esp
 80491be:	8b 45 08             	mov    0x8(%ebp),%eax
 80491c1:	83 3d 1c b3 04 08 00 	cmpl   $0x0,0x804b31c
 80491c8:	75 0e                	jne    80491d8 <server_check+0x20>
 80491ca:	c7 04 24 bc a3 04 08 	movl   $0x804a3bc,(%esp)
 80491d1:	e8 c6 f7 ff ff       	call   804899c <puts@plt>
 80491d6:	eb 55                	jmp    804922d <server_check+0x75>
 80491d8:	83 f8 04             	cmp    $0x4,%eax
 80491db:	76 0e                	jbe    80491eb <server_check+0x33>
 80491dd:	c7 04 24 e8 a3 04 08 	movl   $0x804a3e8,(%esp)
 80491e4:	e8 b3 f7 ff ff       	call   804899c <puts@plt>
 80491e9:	eb 42                	jmp    804922d <server_check+0x75>
 80491eb:	c7 05 20 b3 04 08 01 	movl   $0x1,0x804b320
 80491f2:	00 00 00 
 80491f5:	b9 e4 b2 04 08       	mov    $0x804b2e4,%ecx
 80491fa:	8b 14 81             	mov    (%ecx,%eax,4),%edx
 80491fd:	83 ea 01             	sub    $0x1,%edx
 8049200:	89 14 81             	mov    %edx,(%ecx,%eax,4)
 8049203:	85 d2                	test   %edx,%edx
 8049205:	7e 0e                	jle    8049215 <server_check+0x5d>
 8049207:	c7 04 24 73 a5 04 08 	movl   $0x804a573,(%esp)
 804920e:	e8 89 f7 ff ff       	call   804899c <puts@plt>
 8049213:	eb 18                	jmp    804922d <server_check+0x75>
 8049215:	c7 04 24 7e a5 04 08 	movl   $0x804a57e,(%esp)
 804921c:	e8 7b f7 ff ff       	call   804899c <puts@plt>
 8049221:	c7 04 24 87 a5 04 08 	movl   $0x804a587,(%esp)
 8049228:	e8 6f f7 ff ff       	call   804899c <puts@plt>
 804922d:	c9                   	leave  
 804922e:	c3                   	ret    

0804922f <validate>:
 804922f:	55                   	push   %ebp
 8049230:	89 e5                	mov    %esp,%ebp
 8049232:	81 ec 28 40 00 00    	sub    $0x4028,%esp
 8049238:	89 5d f8             	mov    %ebx,-0x8(%ebp)
 804923b:	89 7d fc             	mov    %edi,-0x4(%ebp)
 804923e:	8b 5d 08             	mov    0x8(%ebp),%ebx
 8049241:	83 3d 1c b3 04 08 00 	cmpl   $0x0,0x804b31c
 8049248:	75 11                	jne    804925b <validate+0x2c>
 804924a:	c7 04 24 bc a3 04 08 	movl   $0x804a3bc,(%esp)
 8049251:	e8 46 f7 ff ff       	call   804899c <puts@plt>
 8049256:	e9 0e 01 00 00       	jmp    8049369 <validate+0x13a>
 804925b:	83 fb 04             	cmp    $0x4,%ebx
 804925e:	76 11                	jbe    8049271 <validate+0x42>
 8049260:	c7 04 24 e8 a3 04 08 	movl   $0x804a3e8,(%esp)
 8049267:	e8 30 f7 ff ff       	call   804899c <puts@plt>
 804926c:	e9 f8 00 00 00       	jmp    8049369 <validate+0x13a>
 8049271:	c7 05 20 b3 04 08 01 	movl   $0x1,0x804b320
 8049278:	00 00 00 
 804927b:	ba e4 b2 04 08       	mov    $0x804b2e4,%edx
 8049280:	8b 04 9a             	mov    (%edx,%ebx,4),%eax
 8049283:	83 e8 01             	sub    $0x1,%eax
 8049286:	89 04 9a             	mov    %eax,(%edx,%ebx,4)
 8049289:	85 c0                	test   %eax,%eax
 804928b:	7e 11                	jle    804929e <validate+0x6f>
 804928d:	c7 04 24 73 a5 04 08 	movl   $0x804a573,(%esp)
 8049294:	e8 03 f7 ff ff       	call   804899c <puts@plt>
 8049299:	e9 cb 00 00 00       	jmp    8049369 <validate+0x13a>
 804929e:	c7 04 24 91 a5 04 08 	movl   $0x804a591,(%esp)
 80492a5:	e8 f2 f6 ff ff       	call   804899c <puts@plt>
 80492aa:	a1 e0 b2 04 08       	mov    0x804b2e0,%eax
 80492af:	83 f8 01             	cmp    $0x1,%eax
 80492b2:	0f 85 a5 00 00 00    	jne    804935d <validate+0x12e>
 80492b8:	bf 40 b3 04 08       	mov    $0x804b340,%edi
 80492bd:	b8 00 00 00 00       	mov    $0x0,%eax
 80492c2:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
 80492c7:	f2 ae                	repnz scas %es:(%edi),%al
 80492c9:	f7 d1                	not    %ecx
 80492cb:	83 c1 1f             	add    $0x1f,%ecx
 80492ce:	81 f9 00 20 00 00    	cmp    $0x2000,%ecx
 80492d4:	76 11                	jbe    80492e7 <validate+0xb8>
 80492d6:	c7 04 24 10 a4 04 08 	movl   $0x804a410,(%esp)
 80492dd:	e8 ba f6 ff ff       	call   804899c <puts@plt>
 80492e2:	e9 82 00 00 00       	jmp    8049369 <validate+0x13a>
 80492e7:	c7 44 24 10 40 b3 04 	movl   $0x804b340,0x10(%esp)
 80492ee:	08 
 80492ef:	a1 18 b3 04 08       	mov    0x804b318,%eax
 80492f4:	89 44 24 0c          	mov    %eax,0xc(%esp)
 80492f8:	89 5c 24 08          	mov    %ebx,0x8(%esp)
 80492fc:	c7 44 24 04 97 a5 04 	movl   $0x804a597,0x4(%esp)
 8049303:	08 
 8049304:	8d 9d f8 df ff ff    	lea    -0x2008(%ebp),%ebx
 804930a:	89 1c 24             	mov    %ebx,(%esp)
 804930d:	e8 ba f4 ff ff       	call   80487cc <sprintf@plt>
 8049312:	8d 85 f8 bf ff ff    	lea    -0x4008(%ebp),%eax
 8049318:	89 44 24 0c          	mov    %eax,0xc(%esp)
 804931c:	c7 44 24 08 00 00 00 	movl   $0x0,0x8(%esp)
 8049323:	00 
 8049324:	89 5c 24 04          	mov    %ebx,0x4(%esp)
 8049328:	a1 1c b3 04 08       	mov    0x804b31c,%eax
 804932d:	89 04 24             	mov    %eax,(%esp)
 8049330:	e8 61 0b 00 00       	call   8049e96 <driver_post>
 8049335:	85 c0                	test   %eax,%eax
 8049337:	75 0e                	jne    8049347 <validate+0x118>
 8049339:	c7 04 24 40 a4 04 08 	movl   $0x804a440,(%esp)
 8049340:	e8 57 f6 ff ff       	call   804899c <puts@plt>
 8049345:	eb 16                	jmp    804935d <validate+0x12e>
 8049347:	8d 85 f8 bf ff ff    	lea    -0x4008(%ebp),%eax
 804934d:	89 44 24 04          	mov    %eax,0x4(%esp)
 8049351:	c7 04 24 70 a4 04 08 	movl   $0x804a470,(%esp)
 8049358:	e8 cf f5 ff ff       	call   804892c <printf@plt>
 804935d:	c7 04 24 a0 a5 04 08 	movl   $0x804a5a0,(%esp)
 8049364:	e8 33 f6 ff ff       	call   804899c <puts@plt>
 8049369:	8b 5d f8             	mov    -0x8(%ebp),%ebx
 804936c:	8b 7d fc             	mov    -0x4(%ebp),%edi
 804936f:	89 ec                	mov    %ebp,%esp
 8049371:	5d                   	pop    %ebp
 8049372:	c3                   	ret    

08049373 <alarmhandler>:
 8049373:	55                   	push   %ebp
 8049374:	89 e5                	mov    %esp,%ebp
 8049376:	83 ec 18             	sub    $0x18,%esp
 8049379:	c7 44 24 04 58 02 00 	movl   $0x258,0x4(%esp)
 8049380:	00 
 8049381:	c7 04 24 b0 a4 04 08 	movl   $0x804a4b0,(%esp)
 8049388:	e8 9f f5 ff ff       	call   804892c <printf@plt>
 804938d:	c7 04 24 85 a2 04 08 	movl   $0x804a285,(%esp)
 8049394:	e8 03 f6 ff ff       	call   804899c <puts@plt>
 8049399:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
 80493a0:	e8 47 f6 ff ff       	call   80489ec <exit@plt>

080493a5 <initialize_bomb>:
 80493a5:	55                   	push   %ebp
 80493a6:	89 e5                	mov    %esp,%ebp
 80493a8:	81 ec 68 20 00 00    	sub    $0x2068,%esp
 80493ae:	89 5d f4             	mov    %ebx,-0xc(%ebp)
 80493b1:	89 75 f8             	mov    %esi,-0x8(%ebp)
 80493b4:	89 7d fc             	mov    %edi,-0x4(%ebp)
 80493b7:	a1 e0 b2 04 08       	mov    0x804b2e0,%eax
 80493bc:	83 f8 01             	cmp    $0x1,%eax
 80493bf:	0f 85 d4 00 00 00    	jne    8049499 <initialize_bomb+0xf4>
 80493c5:	c7 44 24 04 40 00 00 	movl   $0x40,0x4(%esp)
 80493cc:	00 
 80493cd:	8d 45 a8             	lea    -0x58(%ebp),%eax
 80493d0:	89 04 24             	mov    %eax,(%esp)
 80493d3:	e8 b4 f5 ff ff       	call   804898c <gethostname@plt>
 80493d8:	85 c0                	test   %eax,%eax
 80493da:	75 1b                	jne    80493f7 <initialize_bomb+0x52>
 80493dc:	a1 a0 b1 04 08       	mov    0x804b1a0,%eax
 80493e1:	bb 00 00 00 00       	mov    $0x0,%ebx
 80493e6:	8d 75 a8             	lea    -0x58(%ebp),%esi
 80493e9:	bf a0 b1 04 08       	mov    $0x804b1a0,%edi
 80493ee:	85 c0                	test   %eax,%eax
 80493f0:	75 1d                	jne    804940f <initialize_bomb+0x6a>
 80493f2:	e9 8a 00 00 00       	jmp    8049481 <initialize_bomb+0xdc>
 80493f7:	c7 04 24 e4 a4 04 08 	movl   $0x804a4e4,(%esp)
 80493fe:	e8 99 f5 ff ff       	call   804899c <puts@plt>
 8049403:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
 804940a:	e8 dd f5 ff ff       	call   80489ec <exit@plt>
 804940f:	89 74 24 04          	mov    %esi,0x4(%esp)
 8049413:	89 04 24             	mov    %eax,(%esp)
 8049416:	e8 21 f5 ff ff       	call   804893c <strcasecmp@plt>
 804941b:	85 c0                	test   %eax,%eax
 804941d:	74 0c                	je     804942b <initialize_bomb+0x86>
 804941f:	83 c3 01             	add    $0x1,%ebx
 8049422:	8b 04 9f             	mov    (%edi,%ebx,4),%eax
 8049425:	85 c0                	test   %eax,%eax
 8049427:	75 e6                	jne    804940f <initialize_bomb+0x6a>
 8049429:	eb 56                	jmp    8049481 <initialize_bomb+0xdc>
 804942b:	8d 85 a8 df ff ff    	lea    -0x2058(%ebp),%eax
 8049431:	89 04 24             	mov    %eax,(%esp)
 8049434:	e8 77 00 00 00       	call   80494b0 <init_driver>
 8049439:	85 c0                	test   %eax,%eax
 804943b:	79 22                	jns    804945f <initialize_bomb+0xba>
 804943d:	8d 85 a8 df ff ff    	lea    -0x2058(%ebp),%eax
 8049443:	89 44 24 04          	mov    %eax,0x4(%esp)
 8049447:	c7 04 24 aa a5 04 08 	movl   $0x804a5aa,(%esp)
 804944e:	e8 d9 f4 ff ff       	call   804892c <printf@plt>
 8049453:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
 804945a:	e8 8d f5 ff ff       	call   80489ec <exit@plt>
 804945f:	c7 44 24 04 73 93 04 	movl   $0x8049373,0x4(%esp)
 8049466:	08 
 8049467:	c7 04 24 0e 00 00 00 	movl   $0xe,(%esp)
 804946e:	e8 b9 f3 ff ff       	call   804882c <signal@plt>
 8049473:	c7 04 24 58 02 00 00 	movl   $0x258,(%esp)
 804947a:	e8 8d f4 ff ff       	call   804890c <alarm@plt>
 804947f:	eb 18                	jmp    8049499 <initialize_bomb+0xf4>
 8049481:	c7 04 24 1c a5 04 08 	movl   $0x804a51c,(%esp)
 8049488:	e8 0f f5 ff ff       	call   804899c <puts@plt>
 804948d:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
 8049494:	e8 53 f5 ff ff       	call   80489ec <exit@plt>
 8049499:	8b 5d f4             	mov    -0xc(%ebp),%ebx
 804949c:	8b 75 f8             	mov    -0x8(%ebp),%esi
 804949f:	8b 7d fc             	mov    -0x4(%ebp),%edi
 80494a2:	89 ec                	mov    %ebp,%esp
 80494a4:	5d                   	pop    %ebp
 80494a5:	c3                   	ret    
 80494a6:	90                   	nop
 80494a7:	90                   	nop
 80494a8:	90                   	nop
 80494a9:	90                   	nop
 80494aa:	90                   	nop
 80494ab:	90                   	nop
 80494ac:	90                   	nop
 80494ad:	90                   	nop
 80494ae:	90                   	nop
 80494af:	90                   	nop

080494b0 <init_driver>:
 80494b0:	55                   	push   %ebp
 80494b1:	89 e5                	mov    %esp,%ebp
 80494b3:	57                   	push   %edi
 80494b4:	56                   	push   %esi
 80494b5:	53                   	push   %ebx
 80494b6:	83 ec 2c             	sub    $0x2c,%esp
 80494b9:	8b 7d 08             	mov    0x8(%ebp),%edi
 80494bc:	c7 44 24 04 01 00 00 	movl   $0x1,0x4(%esp)
 80494c3:	00 
 80494c4:	c7 04 24 0d 00 00 00 	movl   $0xd,(%esp)
 80494cb:	e8 5c f3 ff ff       	call   804882c <signal@plt>
 80494d0:	c7 44 24 04 01 00 00 	movl   $0x1,0x4(%esp)
 80494d7:	00 
 80494d8:	c7 04 24 1d 00 00 00 	movl   $0x1d,(%esp)
 80494df:	e8 48 f3 ff ff       	call   804882c <signal@plt>
 80494e4:	c7 44 24 04 01 00 00 	movl   $0x1,0x4(%esp)
 80494eb:	00 
 80494ec:	c7 04 24 1d 00 00 00 	movl   $0x1d,(%esp)
 80494f3:	e8 34 f3 ff ff       	call   804882c <signal@plt>
 80494f8:	c7 44 24 08 00 00 00 	movl   $0x0,0x8(%esp)
 80494ff:	00 
 8049500:	c7 44 24 04 01 00 00 	movl   $0x1,0x4(%esp)
 8049507:	00 
 8049508:	c7 04 24 02 00 00 00 	movl   $0x2,(%esp)
 804950f:	e8 a8 f3 ff ff       	call   80488bc <socket@plt>
 8049514:	89 c6                	mov    %eax,%esi
 8049516:	85 c0                	test   %eax,%eax
 8049518:	79 4e                	jns    8049568 <init_driver+0xb8>
 804951a:	c7 07 45 72 72 6f    	movl   $0x6f727245,(%edi)
 8049520:	c7 47 04 72 3a 20 43 	movl   $0x43203a72,0x4(%edi)
 8049527:	c7 47 08 6c 69 65 6e 	movl   $0x6e65696c,0x8(%edi)
 804952e:	c7 47 0c 74 20 75 6e 	movl   $0x6e752074,0xc(%edi)
 8049535:	c7 47 10 61 62 6c 65 	movl   $0x656c6261,0x10(%edi)
 804953c:	c7 47 14 20 74 6f 20 	movl   $0x206f7420,0x14(%edi)
 8049543:	c7 47 18 63 72 65 61 	movl   $0x61657263,0x18(%edi)
 804954a:	c7 47 1c 74 65 20 73 	movl   $0x73206574,0x1c(%edi)
 8049551:	c7 47 20 6f 63 6b 65 	movl   $0x656b636f,0x20(%edi)
 8049558:	66 c7 47 24 74 00    	movw   $0x74,0x24(%edi)
 804955e:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8049563:	e9 3b 01 00 00       	jmp    80496a3 <init_driver+0x1f3>
 8049568:	c7 04 24 f4 a7 04 08 	movl   $0x804a7f4,(%esp)
 804956f:	e8 58 f4 ff ff       	call   80489cc <gethostbyname@plt>
 8049574:	85 c0                	test   %eax,%eax
 8049576:	75 68                	jne    80495e0 <init_driver+0x130>
 8049578:	c7 07 45 72 72 6f    	movl   $0x6f727245,(%edi)
 804957e:	c7 47 04 72 3a 20 44 	movl   $0x44203a72,0x4(%edi)
 8049585:	c7 47 08 4e 53 20 69 	movl   $0x6920534e,0x8(%edi)
 804958c:	c7 47 0c 73 20 75 6e 	movl   $0x6e752073,0xc(%edi)
 8049593:	c7 47 10 61 62 6c 65 	movl   $0x656c6261,0x10(%edi)
 804959a:	c7 47 14 20 74 6f 20 	movl   $0x206f7420,0x14(%edi)
 80495a1:	c7 47 18 72 65 73 6f 	movl   $0x6f736572,0x18(%edi)
 80495a8:	c7 47 1c 6c 76 65 20 	movl   $0x2065766c,0x1c(%edi)
 80495af:	c7 47 20 73 65 72 76 	movl   $0x76726573,0x20(%edi)
 80495b6:	c7 47 24 65 72 20 61 	movl   $0x61207265,0x24(%edi)
 80495bd:	c7 47 28 64 64 72 65 	movl   $0x65726464,0x28(%edi)
 80495c4:	66 c7 47 2c 73 73    	movw   $0x7373,0x2c(%edi)
 80495ca:	c6 47 2e 00          	movb   $0x0,0x2e(%edi)
 80495ce:	89 34 24             	mov    %esi,(%esp)
 80495d1:	e8 86 f3 ff ff       	call   804895c <close@plt>
 80495d6:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 80495db:	e9 c3 00 00 00       	jmp    80496a3 <init_driver+0x1f3>
 80495e0:	8d 5d d8             	lea    -0x28(%ebp),%ebx
 80495e3:	c7 03 00 00 00 00    	movl   $0x0,(%ebx)
 80495e9:	c7 43 04 00 00 00 00 	movl   $0x0,0x4(%ebx)
 80495f0:	c7 43 08 00 00 00 00 	movl   $0x0,0x8(%ebx)
 80495f7:	c7 43 0c 00 00 00 00 	movl   $0x0,0xc(%ebx)
 80495fe:	66 c7 45 d8 02 00    	movw   $0x2,-0x28(%ebp)
 8049604:	8b 50 0c             	mov    0xc(%eax),%edx
 8049607:	89 54 24 08          	mov    %edx,0x8(%esp)
 804960b:	8d 55 dc             	lea    -0x24(%ebp),%edx
 804960e:	89 54 24 04          	mov    %edx,0x4(%esp)
 8049612:	8b 40 10             	mov    0x10(%eax),%eax
 8049615:	8b 00                	mov    (%eax),%eax
 8049617:	89 04 24             	mov    %eax,(%esp)
 804961a:	e8 ad f2 ff ff       	call   80488cc <bcopy@plt>
 804961f:	66 c7 45 da 00 50    	movw   $0x5000,-0x26(%ebp)
 8049625:	c7 44 24 08 10 00 00 	movl   $0x10,0x8(%esp)
 804962c:	00 
 804962d:	89 5c 24 04          	mov    %ebx,0x4(%esp)
 8049631:	89 34 24             	mov    %esi,(%esp)
 8049634:	e8 b3 f1 ff ff       	call   80487ec <connect@plt>
 8049639:	85 c0                	test   %eax,%eax
 804963b:	79 50                	jns    804968d <init_driver+0x1dd>
 804963d:	c7 07 45 72 72 6f    	movl   $0x6f727245,(%edi)
 8049643:	c7 47 04 72 3a 20 55 	movl   $0x55203a72,0x4(%edi)
 804964a:	c7 47 08 6e 61 62 6c 	movl   $0x6c62616e,0x8(%edi)
 8049651:	c7 47 0c 65 20 74 6f 	movl   $0x6f742065,0xc(%edi)
 8049658:	c7 47 10 20 63 6f 6e 	movl   $0x6e6f6320,0x10(%edi)
 804965f:	c7 47 14 6e 65 63 74 	movl   $0x7463656e,0x14(%edi)
 8049666:	c7 47 18 20 74 6f 20 	movl   $0x206f7420,0x18(%edi)
 804966d:	c7 47 1c 73 65 72 76 	movl   $0x76726573,0x1c(%edi)
 8049674:	66 c7 47 20 65 72    	movw   $0x7265,0x20(%edi)
 804967a:	c6 47 22 00          	movb   $0x0,0x22(%edi)
 804967e:	89 34 24             	mov    %esi,(%esp)
 8049681:	e8 d6 f2 ff ff       	call   804895c <close@plt>
 8049686:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 804968b:	eb 16                	jmp    80496a3 <init_driver+0x1f3>
 804968d:	89 34 24             	mov    %esi,(%esp)
 8049690:	e8 c7 f2 ff ff       	call   804895c <close@plt>
 8049695:	66 c7 07 4f 4b       	movw   $0x4b4f,(%edi)
 804969a:	c6 47 02 00          	movb   $0x0,0x2(%edi)
 804969e:	b8 00 00 00 00       	mov    $0x0,%eax
 80496a3:	83 c4 2c             	add    $0x2c,%esp
 80496a6:	5b                   	pop    %ebx
 80496a7:	5e                   	pop    %esi
 80496a8:	5f                   	pop    %edi
 80496a9:	5d                   	pop    %ebp
 80496aa:	c3                   	ret    

080496ab <init_timeout>:
 80496ab:	55                   	push   %ebp
 80496ac:	89 e5                	mov    %esp,%ebp
 80496ae:	53                   	push   %ebx
 80496af:	83 ec 14             	sub    $0x14,%esp
 80496b2:	8b 5d 08             	mov    0x8(%ebp),%ebx
 80496b5:	85 db                	test   %ebx,%ebx
 80496b7:	74 26                	je     80496df <init_timeout+0x34>
 80496b9:	c7 44 24 04 1b 9f 04 	movl   $0x8049f1b,0x4(%esp)
 80496c0:	08 
 80496c1:	c7 04 24 0e 00 00 00 	movl   $0xe,(%esp)
 80496c8:	e8 5f f1 ff ff       	call   804882c <signal@plt>
 80496cd:	85 db                	test   %ebx,%ebx
 80496cf:	b8 00 00 00 00       	mov    $0x0,%eax
 80496d4:	0f 48 d8             	cmovs  %eax,%ebx
 80496d7:	89 1c 24             	mov    %ebx,(%esp)
 80496da:	e8 2d f2 ff ff       	call   804890c <alarm@plt>
 80496df:	83 c4 14             	add    $0x14,%esp
 80496e2:	5b                   	pop    %ebx
 80496e3:	5d                   	pop    %ebp
 80496e4:	c3                   	ret    

080496e5 <rio_readlineb>:
 80496e5:	55                   	push   %ebp
 80496e6:	89 e5                	mov    %esp,%ebp
 80496e8:	57                   	push   %edi
 80496e9:	56                   	push   %esi
 80496ea:	53                   	push   %ebx
 80496eb:	83 ec 3c             	sub    $0x3c,%esp
 80496ee:	89 c3                	mov    %eax,%ebx
 80496f0:	89 4d c8             	mov    %ecx,-0x38(%ebp)
 80496f3:	89 55 d0             	mov    %edx,-0x30(%ebp)
 80496f6:	83 f9 01             	cmp    $0x1,%ecx
 80496f9:	0f 86 b4 00 00 00    	jbe    80497b3 <rio_readlineb+0xce>
 80496ff:	8d 78 0c             	lea    0xc(%eax),%edi
 8049702:	89 7d d4             	mov    %edi,-0x2c(%ebp)
 8049705:	c7 45 cc 01 00 00 00 	movl   $0x1,-0x34(%ebp)
 804970c:	eb 3c                	jmp    804974a <rio_readlineb+0x65>
 804970e:	c7 44 24 08 00 20 00 	movl   $0x2000,0x8(%esp)
 8049715:	00 
 8049716:	89 7c 24 04          	mov    %edi,0x4(%esp)
 804971a:	8b 03                	mov    (%ebx),%eax
 804971c:	89 04 24             	mov    %eax,(%esp)
 804971f:	e8 88 f1 ff ff       	call   80488ac <read@plt>
 8049724:	89 43 04             	mov    %eax,0x4(%ebx)
 8049727:	85 c0                	test   %eax,%eax
 8049729:	79 11                	jns    804973c <rio_readlineb+0x57>
 804972b:	e8 8c f0 ff ff       	call   80487bc <__errno_location@plt>
 8049730:	83 38 04             	cmpl   $0x4,(%eax)
 8049733:	74 15                	je     804974a <rio_readlineb+0x65>
 8049735:	be ff ff ff ff       	mov    $0xffffffff,%esi
 804973a:	eb 51                	jmp    804978d <rio_readlineb+0xa8>
 804973c:	85 c0                	test   %eax,%eax
 804973e:	0f 84 87 00 00 00    	je     80497cb <rio_readlineb+0xe6>
 8049744:	8b 45 d4             	mov    -0x2c(%ebp),%eax
 8049747:	89 43 08             	mov    %eax,0x8(%ebx)
 804974a:	8b 73 04             	mov    0x4(%ebx),%esi
 804974d:	85 f6                	test   %esi,%esi
 804974f:	7e bd                	jle    804970e <rio_readlineb+0x29>
 8049751:	85 f6                	test   %esi,%esi
 8049753:	75 7d                	jne    80497d2 <rio_readlineb+0xed>
 8049755:	8b 43 08             	mov    0x8(%ebx),%eax
 8049758:	89 74 24 08          	mov    %esi,0x8(%esp)
 804975c:	89 44 24 04          	mov    %eax,0x4(%esp)
 8049760:	8d 55 e7             	lea    -0x19(%ebp),%edx
 8049763:	89 14 24             	mov    %edx,(%esp)
 8049766:	e8 81 f1 ff ff       	call   80488ec <memcpy@plt>
 804976b:	01 73 08             	add    %esi,0x8(%ebx)
 804976e:	29 73 04             	sub    %esi,0x4(%ebx)
 8049771:	83 fe 01             	cmp    $0x1,%esi
 8049774:	75 17                	jne    804978d <rio_readlineb+0xa8>
 8049776:	0f b6 45 e7          	movzbl -0x19(%ebp),%eax
 804977a:	8b 55 d0             	mov    -0x30(%ebp),%edx
 804977d:	88 02                	mov    %al,(%edx)
 804977f:	83 c2 01             	add    $0x1,%edx
 8049782:	89 55 d0             	mov    %edx,-0x30(%ebp)
 8049785:	80 7d e7 0a          	cmpb   $0xa,-0x19(%ebp)
 8049789:	75 1a                	jne    80497a5 <rio_readlineb+0xc0>
 804978b:	eb 2d                	jmp    80497ba <rio_readlineb+0xd5>
 804978d:	8b 55 cc             	mov    -0x34(%ebp),%edx
 8049790:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8049795:	85 f6                	test   %esi,%esi
 8049797:	75 2a                	jne    80497c3 <rio_readlineb+0xde>
 8049799:	b8 00 00 00 00       	mov    $0x0,%eax
 804979e:	83 fa 01             	cmp    $0x1,%edx
 80497a1:	75 17                	jne    80497ba <rio_readlineb+0xd5>
 80497a3:	eb 1e                	jmp    80497c3 <rio_readlineb+0xde>
 80497a5:	83 45 cc 01          	addl   $0x1,-0x34(%ebp)
 80497a9:	8b 45 cc             	mov    -0x34(%ebp),%eax
 80497ac:	39 45 c8             	cmp    %eax,-0x38(%ebp)
 80497af:	77 99                	ja     804974a <rio_readlineb+0x65>
 80497b1:	eb 07                	jmp    80497ba <rio_readlineb+0xd5>
 80497b3:	c7 45 cc 01 00 00 00 	movl   $0x1,-0x34(%ebp)
 80497ba:	8b 55 d0             	mov    -0x30(%ebp),%edx
 80497bd:	c6 02 00             	movb   $0x0,(%edx)
 80497c0:	8b 45 cc             	mov    -0x34(%ebp),%eax
 80497c3:	83 c4 3c             	add    $0x3c,%esp
 80497c6:	5b                   	pop    %ebx
 80497c7:	5e                   	pop    %esi
 80497c8:	5f                   	pop    %edi
 80497c9:	5d                   	pop    %ebp
 80497ca:	c3                   	ret    
 80497cb:	be 00 00 00 00       	mov    $0x0,%esi
 80497d0:	eb bb                	jmp    804978d <rio_readlineb+0xa8>
 80497d2:	8b 43 08             	mov    0x8(%ebx),%eax
 80497d5:	0f b6 00             	movzbl (%eax),%eax
 80497d8:	88 45 e7             	mov    %al,-0x19(%ebp)
 80497db:	83 43 08 01          	addl   $0x1,0x8(%ebx)
 80497df:	83 6b 04 01          	subl   $0x1,0x4(%ebx)
 80497e3:	eb 91                	jmp    8049776 <rio_readlineb+0x91>

080497e5 <submitr>:
 80497e5:	55                   	push   %ebp
 80497e6:	89 e5                	mov    %esp,%ebp
 80497e8:	57                   	push   %edi
 80497e9:	56                   	push   %esi
 80497ea:	53                   	push   %ebx
 80497eb:	81 ec 6c a0 00 00    	sub    $0xa06c,%esp
 80497f1:	c7 85 c8 7f ff ff 00 	movl   $0x0,-0x8038(%ebp)
 80497f8:	00 00 00 
 80497fb:	c7 44 24 08 00 00 00 	movl   $0x0,0x8(%esp)
 8049802:	00 
 8049803:	c7 44 24 04 01 00 00 	movl   $0x1,0x4(%esp)
 804980a:	00 
 804980b:	c7 04 24 02 00 00 00 	movl   $0x2,(%esp)
 8049812:	e8 a5 f0 ff ff       	call   80488bc <socket@plt>
 8049817:	89 85 b0 5f ff ff    	mov    %eax,-0xa050(%ebp)
 804981d:	85 c0                	test   %eax,%eax
 804981f:	79 1b                	jns    804983c <submitr+0x57>
 8049821:	b8 14 a8 04 08       	mov    $0x804a814,%eax
 8049826:	b9 26 00 00 00       	mov    $0x26,%ecx
 804982b:	8b 7d 20             	mov    0x20(%ebp),%edi
 804982e:	89 c6                	mov    %eax,%esi
 8049830:	f3 a4                	rep movsb %ds:(%esi),%es:(%edi)
 8049832:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8049837:	e9 e1 05 00 00       	jmp    8049e1d <submitr+0x638>
 804983c:	8b 45 08             	mov    0x8(%ebp),%eax
 804983f:	89 04 24             	mov    %eax,(%esp)
 8049842:	e8 85 f1 ff ff       	call   80489cc <gethostbyname@plt>
 8049847:	85 c0                	test   %eax,%eax
 8049849:	75 29                	jne    8049874 <submitr+0x8f>
 804984b:	b8 3c a8 04 08       	mov    $0x804a83c,%eax
 8049850:	b9 37 00 00 00       	mov    $0x37,%ecx
 8049855:	8b 7d 20             	mov    0x20(%ebp),%edi
 8049858:	89 c6                	mov    %eax,%esi
 804985a:	f3 a4                	rep movsb %ds:(%esi),%es:(%edi)
 804985c:	8b 85 b0 5f ff ff    	mov    -0xa050(%ebp),%eax
 8049862:	89 04 24             	mov    %eax,(%esp)
 8049865:	e8 f2 f0 ff ff       	call   804895c <close@plt>
 804986a:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 804986f:	e9 a9 05 00 00       	jmp    8049e1d <submitr+0x638>
 8049874:	8d 5d d8             	lea    -0x28(%ebp),%ebx
 8049877:	c7 03 00 00 00 00    	movl   $0x0,(%ebx)
 804987d:	c7 43 04 00 00 00 00 	movl   $0x0,0x4(%ebx)
 8049884:	c7 43 08 00 00 00 00 	movl   $0x0,0x8(%ebx)
 804988b:	c7 43 0c 00 00 00 00 	movl   $0x0,0xc(%ebx)
 8049892:	66 c7 45 d8 02 00    	movw   $0x2,-0x28(%ebp)
 8049898:	8b 50 0c             	mov    0xc(%eax),%edx
 804989b:	89 54 24 08          	mov    %edx,0x8(%esp)
 804989f:	8d 55 dc             	lea    -0x24(%ebp),%edx
 80498a2:	89 54 24 04          	mov    %edx,0x4(%esp)
 80498a6:	8b 40 10             	mov    0x10(%eax),%eax
 80498a9:	8b 00                	mov    (%eax),%eax
 80498ab:	89 04 24             	mov    %eax,(%esp)
 80498ae:	e8 19 f0 ff ff       	call   80488cc <bcopy@plt>
 80498b3:	0f b7 45 0c          	movzwl 0xc(%ebp),%eax
 80498b7:	66 c1 c8 08          	ror    $0x8,%ax
 80498bb:	66 89 45 da          	mov    %ax,-0x26(%ebp)
 80498bf:	c7 44 24 08 10 00 00 	movl   $0x10,0x8(%esp)
 80498c6:	00 
 80498c7:	89 5c 24 04          	mov    %ebx,0x4(%esp)
 80498cb:	8b 8d b0 5f ff ff    	mov    -0xa050(%ebp),%ecx
 80498d1:	89 0c 24             	mov    %ecx,(%esp)
 80498d4:	e8 13 ef ff ff       	call   80487ec <connect@plt>
 80498d9:	85 c0                	test   %eax,%eax
 80498db:	79 29                	jns    8049906 <submitr+0x121>
 80498dd:	b8 74 a8 04 08       	mov    $0x804a874,%eax
 80498e2:	b9 2f 00 00 00       	mov    $0x2f,%ecx
 80498e7:	8b 7d 20             	mov    0x20(%ebp),%edi
 80498ea:	89 c6                	mov    %eax,%esi
 80498ec:	f3 a4                	rep movsb %ds:(%esi),%es:(%edi)
 80498ee:	8b 85 b0 5f ff ff    	mov    -0xa050(%ebp),%eax
 80498f4:	89 04 24             	mov    %eax,(%esp)
 80498f7:	e8 60 f0 ff ff       	call   804895c <close@plt>
 80498fc:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8049901:	e9 17 05 00 00       	jmp    8049e1d <submitr+0x638>
 8049906:	ba ff ff ff ff       	mov    $0xffffffff,%edx
 804990b:	8b 7d 1c             	mov    0x1c(%ebp),%edi
 804990e:	b8 00 00 00 00       	mov    $0x0,%eax
 8049913:	89 d1                	mov    %edx,%ecx
 8049915:	f2 ae                	repnz scas %es:(%edi),%al
 8049917:	89 cb                	mov    %ecx,%ebx
 8049919:	f7 d3                	not    %ebx
 804991b:	8b 7d 10             	mov    0x10(%ebp),%edi
 804991e:	89 d1                	mov    %edx,%ecx
 8049920:	f2 ae                	repnz scas %es:(%edi),%al
 8049922:	89 8d b4 5f ff ff    	mov    %ecx,-0xa04c(%ebp)
 8049928:	8b 7d 14             	mov    0x14(%ebp),%edi
 804992b:	89 d1                	mov    %edx,%ecx
 804992d:	f2 ae                	repnz scas %es:(%edi),%al
 804992f:	89 ce                	mov    %ecx,%esi
 8049931:	f7 d6                	not    %esi
 8049933:	8b 7d 18             	mov    0x18(%ebp),%edi
 8049936:	89 d1                	mov    %edx,%ecx
 8049938:	f2 ae                	repnz scas %es:(%edi),%al
 804993a:	2b b5 b4 5f ff ff    	sub    -0xa04c(%ebp),%esi
 8049940:	29 ce                	sub    %ecx,%esi
 8049942:	8d 44 5b fd          	lea    -0x3(%ebx,%ebx,2),%eax
 8049946:	8d 44 06 7b          	lea    0x7b(%esi,%eax,1),%eax
 804994a:	3d 00 20 00 00       	cmp    $0x2000,%eax
 804994f:	76 7c                	jbe    80499cd <submitr+0x1e8>
 8049951:	8b 75 20             	mov    0x20(%ebp),%esi
 8049954:	c7 06 45 72 72 6f    	movl   $0x6f727245,(%esi)
 804995a:	c7 46 04 72 3a 20 52 	movl   $0x52203a72,0x4(%esi)
 8049961:	c7 46 08 65 73 75 6c 	movl   $0x6c757365,0x8(%esi)
 8049968:	c7 46 0c 74 20 73 74 	movl   $0x74732074,0xc(%esi)
 804996f:	c7 46 10 72 69 6e 67 	movl   $0x676e6972,0x10(%esi)
 8049976:	c7 46 14 20 74 6f 6f 	movl   $0x6f6f7420,0x14(%esi)
 804997d:	c7 46 18 20 6c 61 72 	movl   $0x72616c20,0x18(%esi)
 8049984:	c7 46 1c 67 65 2e 20 	movl   $0x202e6567,0x1c(%esi)
 804998b:	c7 46 20 49 6e 63 72 	movl   $0x72636e49,0x20(%esi)
 8049992:	c7 46 24 65 61 73 65 	movl   $0x65736165,0x24(%esi)
 8049999:	c7 46 28 20 53 55 42 	movl   $0x42555320,0x28(%esi)
 80499a0:	c7 46 2c 4d 49 54 52 	movl   $0x5254494d,0x2c(%esi)
 80499a7:	c7 46 30 5f 4d 41 58 	movl   $0x58414d5f,0x30(%esi)
 80499ae:	c7 46 34 42 55 46 00 	movl   $0x465542,0x34(%esi)
 80499b5:	8b bd b0 5f ff ff    	mov    -0xa050(%ebp),%edi
 80499bb:	89 3c 24             	mov    %edi,(%esp)
 80499be:	e8 99 ef ff ff       	call   804895c <close@plt>
 80499c3:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 80499c8:	e9 50 04 00 00       	jmp    8049e1d <submitr+0x638>
 80499cd:	8d 95 cc 9f ff ff    	lea    -0x6034(%ebp),%edx
 80499d3:	b9 00 08 00 00       	mov    $0x800,%ecx
 80499d8:	b8 00 00 00 00       	mov    $0x0,%eax
 80499dd:	89 d7                	mov    %edx,%edi
 80499df:	f3 ab                	rep stos %eax,%es:(%edi)
 80499e1:	8b 7d 1c             	mov    0x1c(%ebp),%edi
 80499e4:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
 80499e9:	f2 ae                	repnz scas %es:(%edi),%al
 80499eb:	f7 d1                	not    %ecx
 80499ed:	89 cf                	mov    %ecx,%edi
 80499ef:	83 ef 01             	sub    $0x1,%edi
 80499f2:	0f 84 30 04 00 00    	je     8049e28 <submitr+0x643>
 80499f8:	89 d6                	mov    %edx,%esi
 80499fa:	bb 00 00 00 00       	mov    $0x0,%ebx
 80499ff:	89 bd b4 5f ff ff    	mov    %edi,-0xa04c(%ebp)
 8049a05:	8b 7d 1c             	mov    0x1c(%ebp),%edi
 8049a08:	0f b6 04 1f          	movzbl (%edi,%ebx,1),%eax
 8049a0c:	3c 2a                	cmp    $0x2a,%al
 8049a0e:	74 24                	je     8049a34 <submitr+0x24f>
 8049a10:	3c 2d                	cmp    $0x2d,%al
 8049a12:	74 20                	je     8049a34 <submitr+0x24f>
 8049a14:	3c 2e                	cmp    $0x2e,%al
 8049a16:	74 1c                	je     8049a34 <submitr+0x24f>
 8049a18:	3c 5f                	cmp    $0x5f,%al
 8049a1a:	74 18                	je     8049a34 <submitr+0x24f>
 8049a1c:	8d 50 d0             	lea    -0x30(%eax),%edx
 8049a1f:	80 fa 09             	cmp    $0x9,%dl
 8049a22:	76 10                	jbe    8049a34 <submitr+0x24f>
 8049a24:	8d 50 bf             	lea    -0x41(%eax),%edx
 8049a27:	80 fa 19             	cmp    $0x19,%dl
 8049a2a:	76 08                	jbe    8049a34 <submitr+0x24f>
 8049a2c:	8d 50 9f             	lea    -0x61(%eax),%edx
 8049a2f:	80 fa 19             	cmp    $0x19,%dl
 8049a32:	77 07                	ja     8049a3b <submitr+0x256>
 8049a34:	88 06                	mov    %al,(%esi)
 8049a36:	83 c6 01             	add    $0x1,%esi
 8049a39:	eb 55                	jmp    8049a90 <submitr+0x2ab>
 8049a3b:	3c 20                	cmp    $0x20,%al
 8049a3d:	75 08                	jne    8049a47 <submitr+0x262>
 8049a3f:	c6 06 2b             	movb   $0x2b,(%esi)
 8049a42:	83 c6 01             	add    $0x1,%esi
 8049a45:	eb 49                	jmp    8049a90 <submitr+0x2ab>
 8049a47:	8d 50 e0             	lea    -0x20(%eax),%edx
 8049a4a:	80 fa 5f             	cmp    $0x5f,%dl
 8049a4d:	76 04                	jbe    8049a53 <submitr+0x26e>
 8049a4f:	3c 09                	cmp    $0x9,%al
 8049a51:	75 51                	jne    8049aa4 <submitr+0x2bf>
 8049a53:	0f b6 c0             	movzbl %al,%eax
 8049a56:	89 44 24 08          	mov    %eax,0x8(%esp)
 8049a5a:	c7 44 24 04 4c aa 04 	movl   $0x804aa4c,0x4(%esp)
 8049a61:	08 
 8049a62:	8d 85 c0 5f ff ff    	lea    -0xa040(%ebp),%eax
 8049a68:	89 04 24             	mov    %eax,(%esp)
 8049a6b:	e8 5c ed ff ff       	call   80487cc <sprintf@plt>
 8049a70:	0f b6 85 c0 5f ff ff 	movzbl -0xa040(%ebp),%eax
 8049a77:	88 06                	mov    %al,(%esi)
 8049a79:	0f b6 85 c1 5f ff ff 	movzbl -0xa03f(%ebp),%eax
 8049a80:	88 46 01             	mov    %al,0x1(%esi)
 8049a83:	0f b6 85 c2 5f ff ff 	movzbl -0xa03e(%ebp),%eax
 8049a8a:	88 46 02             	mov    %al,0x2(%esi)
 8049a8d:	83 c6 03             	add    $0x3,%esi
 8049a90:	83 c3 01             	add    $0x1,%ebx
 8049a93:	3b 9d b4 5f ff ff    	cmp    -0xa04c(%ebp),%ebx
 8049a99:	0f 85 69 ff ff ff    	jne    8049a08 <submitr+0x223>
 8049a9f:	e9 84 03 00 00       	jmp    8049e28 <submitr+0x643>
 8049aa4:	b8 a4 a8 04 08       	mov    $0x804a8a4,%eax
 8049aa9:	b9 43 00 00 00       	mov    $0x43,%ecx
 8049aae:	8b 7d 20             	mov    0x20(%ebp),%edi
 8049ab1:	89 c6                	mov    %eax,%esi
 8049ab3:	f3 a4                	rep movsb %ds:(%esi),%es:(%edi)
 8049ab5:	8b 85 b0 5f ff ff    	mov    -0xa050(%ebp),%eax
 8049abb:	89 04 24             	mov    %eax,(%esp)
 8049abe:	e8 99 ee ff ff       	call   804895c <close@plt>
 8049ac3:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8049ac8:	e9 50 03 00 00       	jmp    8049e1d <submitr+0x638>
 8049acd:	01 c6                	add    %eax,%esi
 8049acf:	89 5c 24 08          	mov    %ebx,0x8(%esp)
 8049ad3:	89 74 24 04          	mov    %esi,0x4(%esp)
 8049ad7:	89 3c 24             	mov    %edi,(%esp)
 8049ada:	e8 8d ed ff ff       	call   804886c <write@plt>
 8049adf:	85 c0                	test   %eax,%eax
 8049ae1:	7f 0f                	jg     8049af2 <submitr+0x30d>
 8049ae3:	e8 d4 ec ff ff       	call   80487bc <__errno_location@plt>
 8049ae8:	83 38 04             	cmpl   $0x4,(%eax)
 8049aeb:	75 13                	jne    8049b00 <submitr+0x31b>
 8049aed:	b8 00 00 00 00       	mov    $0x0,%eax
 8049af2:	29 c3                	sub    %eax,%ebx
 8049af4:	75 d7                	jne    8049acd <submitr+0x2e8>
 8049af6:	8b bd b4 5f ff ff    	mov    -0xa04c(%ebp),%edi
 8049afc:	85 ff                	test   %edi,%edi
 8049afe:	79 64                	jns    8049b64 <submitr+0x37f>
 8049b00:	8b 7d 20             	mov    0x20(%ebp),%edi
 8049b03:	be e8 a8 04 08       	mov    $0x804a8e8,%esi
 8049b08:	b8 34 00 00 00       	mov    $0x34,%eax
 8049b0d:	f7 c7 01 00 00 00    	test   $0x1,%edi
 8049b13:	74 04                	je     8049b19 <submitr+0x334>
 8049b15:	a4                   	movsb  %ds:(%esi),%es:(%edi)
 8049b16:	83 e8 01             	sub    $0x1,%eax
 8049b19:	f7 c7 02 00 00 00    	test   $0x2,%edi
 8049b1f:	74 05                	je     8049b26 <submitr+0x341>
 8049b21:	66 a5                	movsw  %ds:(%esi),%es:(%edi)
 8049b23:	83 e8 02             	sub    $0x2,%eax
 8049b26:	89 c1                	mov    %eax,%ecx
 8049b28:	c1 e9 02             	shr    $0x2,%ecx
 8049b2b:	f3 a5                	rep movsl %ds:(%esi),%es:(%edi)
 8049b2d:	ba 00 00 00 00       	mov    $0x0,%edx
 8049b32:	a8 02                	test   $0x2,%al
 8049b34:	74 0b                	je     8049b41 <submitr+0x35c>
 8049b36:	0f b7 0c 16          	movzwl (%esi,%edx,1),%ecx
 8049b3a:	66 89 0c 17          	mov    %cx,(%edi,%edx,1)
 8049b3e:	83 c2 02             	add    $0x2,%edx
 8049b41:	a8 01                	test   $0x1,%al
 8049b43:	74 07                	je     8049b4c <submitr+0x367>
 8049b45:	0f b6 04 16          	movzbl (%esi,%edx,1),%eax
 8049b49:	88 04 17             	mov    %al,(%edi,%edx,1)
 8049b4c:	8b 8d b0 5f ff ff    	mov    -0xa050(%ebp),%ecx
 8049b52:	89 0c 24             	mov    %ecx,(%esp)
 8049b55:	e8 02 ee ff ff       	call   804895c <close@plt>
 8049b5a:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8049b5f:	e9 b9 02 00 00       	jmp    8049e1d <submitr+0x638>
 8049b64:	8b b5 b0 5f ff ff    	mov    -0xa050(%ebp),%esi
 8049b6a:	89 b5 cc df ff ff    	mov    %esi,-0x2034(%ebp)
 8049b70:	c7 85 d0 df ff ff 00 	movl   $0x0,-0x2030(%ebp)
 8049b77:	00 00 00 
 8049b7a:	8d 85 cc df ff ff    	lea    -0x2034(%ebp),%eax
 8049b80:	8d 95 d8 df ff ff    	lea    -0x2028(%ebp),%edx
 8049b86:	89 95 d4 df ff ff    	mov    %edx,-0x202c(%ebp)
 8049b8c:	8d 95 cc bf ff ff    	lea    -0x4034(%ebp),%edx
 8049b92:	b9 00 20 00 00       	mov    $0x2000,%ecx
 8049b97:	e8 49 fb ff ff       	call   80496e5 <rio_readlineb>
 8049b9c:	85 c0                	test   %eax,%eax
 8049b9e:	7f 29                	jg     8049bc9 <submitr+0x3e4>
 8049ba0:	b8 1c a9 04 08       	mov    $0x804a91c,%eax
 8049ba5:	b9 3e 00 00 00       	mov    $0x3e,%ecx
 8049baa:	8b 7d 20             	mov    0x20(%ebp),%edi
 8049bad:	89 c6                	mov    %eax,%esi
 8049baf:	f3 a4                	rep movsb %ds:(%esi),%es:(%edi)
 8049bb1:	8b 85 b0 5f ff ff    	mov    -0xa050(%ebp),%eax
 8049bb7:	89 04 24             	mov    %eax,(%esp)
 8049bba:	e8 9d ed ff ff       	call   804895c <close@plt>
 8049bbf:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8049bc4:	e9 54 02 00 00       	jmp    8049e1d <submitr+0x638>
 8049bc9:	8d bd cc bf ff ff    	lea    -0x4034(%ebp),%edi
 8049bcf:	8d 85 c8 5f ff ff    	lea    -0xa038(%ebp),%eax
 8049bd5:	89 44 24 10          	mov    %eax,0x10(%esp)
 8049bd9:	8d 85 c8 7f ff ff    	lea    -0x8038(%ebp),%eax
 8049bdf:	89 44 24 0c          	mov    %eax,0xc(%esp)
 8049be3:	8d 85 cc 7f ff ff    	lea    -0x8034(%ebp),%eax
 8049be9:	89 44 24 08          	mov    %eax,0x8(%esp)
 8049bed:	c7 44 24 04 53 aa 04 	movl   $0x804aa53,0x4(%esp)
 8049bf4:	08 
 8049bf5:	89 3c 24             	mov    %edi,(%esp)
 8049bf8:	e8 4f ec ff ff       	call   804884c <__isoc99_sscanf@plt>
 8049bfd:	8b 85 c8 7f ff ff    	mov    -0x8038(%ebp),%eax
 8049c03:	8d 9d cc bf ff ff    	lea    -0x4034(%ebp),%ebx
 8049c09:	8d b5 cc df ff ff    	lea    -0x2034(%ebp),%esi
 8049c0f:	3d c8 00 00 00       	cmp    $0xc8,%eax
 8049c14:	0f 84 cf 00 00 00    	je     8049ce9 <submitr+0x504>
 8049c1a:	8d 95 c8 5f ff ff    	lea    -0xa038(%ebp),%edx
 8049c20:	89 54 24 0c          	mov    %edx,0xc(%esp)
 8049c24:	89 44 24 08          	mov    %eax,0x8(%esp)
 8049c28:	c7 44 24 04 5c a9 04 	movl   $0x804a95c,0x4(%esp)
 8049c2f:	08 
 8049c30:	8b 4d 20             	mov    0x20(%ebp),%ecx
 8049c33:	89 0c 24             	mov    %ecx,(%esp)
 8049c36:	e8 91 eb ff ff       	call   80487cc <sprintf@plt>
 8049c3b:	8b b5 b0 5f ff ff    	mov    -0xa050(%ebp),%esi
 8049c41:	89 34 24             	mov    %esi,(%esp)
 8049c44:	e8 13 ed ff ff       	call   804895c <close@plt>
 8049c49:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8049c4e:	e9 ca 01 00 00       	jmp    8049e1d <submitr+0x638>
 8049c53:	b9 00 20 00 00       	mov    $0x2000,%ecx
 8049c58:	89 da                	mov    %ebx,%edx
 8049c5a:	89 f0                	mov    %esi,%eax
 8049c5c:	e8 84 fa ff ff       	call   80496e5 <rio_readlineb>
 8049c61:	85 c0                	test   %eax,%eax
 8049c63:	0f 8f 80 00 00 00    	jg     8049ce9 <submitr+0x504>
 8049c69:	8b 7d 20             	mov    0x20(%ebp),%edi
 8049c6c:	c7 07 45 72 72 6f    	movl   $0x6f727245,(%edi)
 8049c72:	c7 47 04 72 3a 20 43 	movl   $0x43203a72,0x4(%edi)
 8049c79:	c7 47 08 6c 69 65 6e 	movl   $0x6e65696c,0x8(%edi)
 8049c80:	c7 47 0c 74 20 75 6e 	movl   $0x6e752074,0xc(%edi)
 8049c87:	c7 47 10 61 62 6c 65 	movl   $0x656c6261,0x10(%edi)
 8049c8e:	c7 47 14 20 74 6f 20 	movl   $0x206f7420,0x14(%edi)
 8049c95:	c7 47 18 72 65 61 64 	movl   $0x64616572,0x18(%edi)
 8049c9c:	c7 47 1c 20 68 65 61 	movl   $0x61656820,0x1c(%edi)
 8049ca3:	c7 47 20 64 65 72 73 	movl   $0x73726564,0x20(%edi)
 8049caa:	c7 47 24 20 66 72 6f 	movl   $0x6f726620,0x24(%edi)
 8049cb1:	c7 47 28 6d 20 41 75 	movl   $0x7541206d,0x28(%edi)
 8049cb8:	c7 47 2c 74 6f 6c 61 	movl   $0x616c6f74,0x2c(%edi)
 8049cbf:	c7 47 30 62 20 73 65 	movl   $0x65732062,0x30(%edi)
 8049cc6:	c7 47 34 72 76 65 72 	movl   $0x72657672,0x34(%edi)
 8049ccd:	c6 47 38 00          	movb   $0x0,0x38(%edi)
 8049cd1:	8b 85 b0 5f ff ff    	mov    -0xa050(%ebp),%eax
 8049cd7:	89 04 24             	mov    %eax,(%esp)
 8049cda:	e8 7d ec ff ff       	call   804895c <close@plt>
 8049cdf:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8049ce4:	e9 34 01 00 00       	jmp    8049e1d <submitr+0x638>
 8049ce9:	b8 6a aa 04 08       	mov    $0x804aa6a,%eax
 8049cee:	0f b6 13             	movzbl (%ebx),%edx
 8049cf1:	3a 10                	cmp    (%eax),%dl
 8049cf3:	0f 85 5a ff ff ff    	jne    8049c53 <submitr+0x46e>
 8049cf9:	0f b6 53 01          	movzbl 0x1(%ebx),%edx
 8049cfd:	3a 50 01             	cmp    0x1(%eax),%dl
 8049d00:	0f 85 4d ff ff ff    	jne    8049c53 <submitr+0x46e>
 8049d06:	0f b6 53 02          	movzbl 0x2(%ebx),%edx
 8049d0a:	3a 50 02             	cmp    0x2(%eax),%dl
 8049d0d:	0f 85 40 ff ff ff    	jne    8049c53 <submitr+0x46e>
 8049d13:	8d 95 cc bf ff ff    	lea    -0x4034(%ebp),%edx
 8049d19:	8d 85 cc df ff ff    	lea    -0x2034(%ebp),%eax
 8049d1f:	b9 00 20 00 00       	mov    $0x2000,%ecx
 8049d24:	e8 bc f9 ff ff       	call   80496e5 <rio_readlineb>
 8049d29:	85 c0                	test   %eax,%eax
 8049d2b:	7f 64                	jg     8049d91 <submitr+0x5ac>
 8049d2d:	8b 7d 20             	mov    0x20(%ebp),%edi
 8049d30:	be 8c a9 04 08       	mov    $0x804a98c,%esi
 8049d35:	b8 40 00 00 00       	mov    $0x40,%eax
 8049d3a:	f7 c7 01 00 00 00    	test   $0x1,%edi
 8049d40:	74 04                	je     8049d46 <submitr+0x561>
 8049d42:	a4                   	movsb  %ds:(%esi),%es:(%edi)
 8049d43:	83 e8 01             	sub    $0x1,%eax
 8049d46:	f7 c7 02 00 00 00    	test   $0x2,%edi
 8049d4c:	74 05                	je     8049d53 <submitr+0x56e>
 8049d4e:	66 a5                	movsw  %ds:(%esi),%es:(%edi)
 8049d50:	83 e8 02             	sub    $0x2,%eax
 8049d53:	89 c1                	mov    %eax,%ecx
 8049d55:	c1 e9 02             	shr    $0x2,%ecx
 8049d58:	f3 a5                	rep movsl %ds:(%esi),%es:(%edi)
 8049d5a:	ba 00 00 00 00       	mov    $0x0,%edx
 8049d5f:	a8 02                	test   $0x2,%al
 8049d61:	74 0b                	je     8049d6e <submitr+0x589>
 8049d63:	0f b7 0c 16          	movzwl (%esi,%edx,1),%ecx
 8049d67:	66 89 0c 17          	mov    %cx,(%edi,%edx,1)
 8049d6b:	83 c2 02             	add    $0x2,%edx
 8049d6e:	a8 01                	test   $0x1,%al
 8049d70:	74 07                	je     8049d79 <submitr+0x594>
 8049d72:	0f b6 04 16          	movzbl (%esi,%edx,1),%eax
 8049d76:	88 04 17             	mov    %al,(%edi,%edx,1)
 8049d79:	8b 8d b0 5f ff ff    	mov    -0xa050(%ebp),%ecx
 8049d7f:	89 0c 24             	mov    %ecx,(%esp)
 8049d82:	e8 d5 eb ff ff       	call   804895c <close@plt>
 8049d87:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8049d8c:	e9 8c 00 00 00       	jmp    8049e1d <submitr+0x638>
 8049d91:	89 7c 24 04          	mov    %edi,0x4(%esp)
 8049d95:	8b 75 20             	mov    0x20(%ebp),%esi
 8049d98:	89 34 24             	mov    %esi,(%esp)
 8049d9b:	e8 7c eb ff ff       	call   804891c <strcpy@plt>
 8049da0:	8b bd b0 5f ff ff    	mov    -0xa050(%ebp),%edi
 8049da6:	89 3c 24             	mov    %edi,(%esp)
 8049da9:	e8 ae eb ff ff       	call   804895c <close@plt>
 8049dae:	89 f0                	mov    %esi,%eax
 8049db0:	0f b6 16             	movzbl (%esi),%edx
 8049db3:	b9 64 aa 04 08       	mov    $0x804aa64,%ecx
 8049db8:	0f b6 19             	movzbl (%ecx),%ebx
 8049dbb:	39 da                	cmp    %ebx,%edx
 8049dbd:	75 1b                	jne    8049dda <submitr+0x5f5>
 8049dbf:	0f b6 5e 01          	movzbl 0x1(%esi),%ebx
 8049dc3:	3a 59 01             	cmp    0x1(%ecx),%bl
 8049dc6:	75 12                	jne    8049dda <submitr+0x5f5>
 8049dc8:	0f b6 5e 02          	movzbl 0x2(%esi),%ebx
 8049dcc:	3a 59 02             	cmp    0x2(%ecx),%bl
 8049dcf:	75 09                	jne    8049dda <submitr+0x5f5>
 8049dd1:	0f b6 5e 03          	movzbl 0x3(%esi),%ebx
 8049dd5:	3a 59 03             	cmp    0x3(%ecx),%bl
 8049dd8:	74 37                	je     8049e11 <submitr+0x62c>
 8049dda:	8b 75 20             	mov    0x20(%ebp),%esi
 8049ddd:	bf 68 aa 04 08       	mov    $0x804aa68,%edi
 8049de2:	b9 05 00 00 00       	mov    $0x5,%ecx
 8049de7:	f3 a6                	repz cmpsb %es:(%edi),%ds:(%esi)
 8049de9:	0f 97 c3             	seta   %bl
 8049dec:	0f 92 c1             	setb   %cl
 8049def:	38 cb                	cmp    %cl,%bl
 8049df1:	74 1e                	je     8049e11 <submitr+0x62c>
 8049df3:	b9 6d aa 04 08       	mov    $0x804aa6d,%ecx
 8049df8:	0f b6 19             	movzbl (%ecx),%ebx
 8049dfb:	39 da                	cmp    %ebx,%edx
 8049dfd:	75 19                	jne    8049e18 <submitr+0x633>
 8049dff:	0f b6 50 01          	movzbl 0x1(%eax),%edx
 8049e03:	3a 51 01             	cmp    0x1(%ecx),%dl
 8049e06:	75 10                	jne    8049e18 <submitr+0x633>
 8049e08:	0f b6 40 02          	movzbl 0x2(%eax),%eax
 8049e0c:	3a 41 02             	cmp    0x2(%ecx),%al
 8049e0f:	75 07                	jne    8049e18 <submitr+0x633>
 8049e11:	b8 00 00 00 00       	mov    $0x0,%eax
 8049e16:	eb 05                	jmp    8049e1d <submitr+0x638>
 8049e18:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8049e1d:	81 c4 6c a0 00 00    	add    $0xa06c,%esp
 8049e23:	5b                   	pop    %ebx
 8049e24:	5e                   	pop    %esi
 8049e25:	5f                   	pop    %edi
 8049e26:	5d                   	pop    %ebp
 8049e27:	c3                   	ret    
 8049e28:	8b 45 08             	mov    0x8(%ebp),%eax
 8049e2b:	89 44 24 18          	mov    %eax,0x18(%esp)
 8049e2f:	8d 85 cc 9f ff ff    	lea    -0x6034(%ebp),%eax
 8049e35:	89 44 24 14          	mov    %eax,0x14(%esp)
 8049e39:	8b 4d 18             	mov    0x18(%ebp),%ecx
 8049e3c:	89 4c 24 10          	mov    %ecx,0x10(%esp)
 8049e40:	8b 75 14             	mov    0x14(%ebp),%esi
 8049e43:	89 74 24 0c          	mov    %esi,0xc(%esp)
 8049e47:	8b 7d 10             	mov    0x10(%ebp),%edi
 8049e4a:	89 7c 24 08          	mov    %edi,0x8(%esp)
 8049e4e:	c7 44 24 04 cc a9 04 	movl   $0x804a9cc,0x4(%esp)
 8049e55:	08 
 8049e56:	8d bd cc bf ff ff    	lea    -0x4034(%ebp),%edi
 8049e5c:	89 3c 24             	mov    %edi,(%esp)
 8049e5f:	e8 68 e9 ff ff       	call   80487cc <sprintf@plt>
 8049e64:	b8 00 00 00 00       	mov    $0x0,%eax
 8049e69:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
 8049e6e:	f2 ae                	repnz scas %es:(%edi),%al
 8049e70:	f7 d1                	not    %ecx
 8049e72:	89 cf                	mov    %ecx,%edi
 8049e74:	83 ef 01             	sub    $0x1,%edi
 8049e77:	0f 84 e7 fc ff ff    	je     8049b64 <submitr+0x37f>
 8049e7d:	89 fb                	mov    %edi,%ebx
 8049e7f:	8d b5 cc bf ff ff    	lea    -0x4034(%ebp),%esi
 8049e85:	89 bd b4 5f ff ff    	mov    %edi,-0xa04c(%ebp)
 8049e8b:	8b bd b0 5f ff ff    	mov    -0xa050(%ebp),%edi
 8049e91:	e9 39 fc ff ff       	jmp    8049acf <submitr+0x2ea>

08049e96 <driver_post>:
 8049e96:	55                   	push   %ebp
 8049e97:	89 e5                	mov    %esp,%ebp
 8049e99:	53                   	push   %ebx
 8049e9a:	83 ec 24             	sub    $0x24,%esp
 8049e9d:	8b 45 08             	mov    0x8(%ebp),%eax
 8049ea0:	8b 55 0c             	mov    0xc(%ebp),%edx
 8049ea3:	8b 5d 14             	mov    0x14(%ebp),%ebx
 8049ea6:	83 7d 10 00          	cmpl   $0x0,0x10(%ebp)
 8049eaa:	74 20                	je     8049ecc <driver_post+0x36>
 8049eac:	89 54 24 04          	mov    %edx,0x4(%esp)
 8049eb0:	c7 04 24 70 aa 04 08 	movl   $0x804aa70,(%esp)
 8049eb7:	e8 70 ea ff ff       	call   804892c <printf@plt>
 8049ebc:	66 c7 03 4f 4b       	movw   $0x4b4f,(%ebx)
 8049ec1:	c6 43 02 00          	movb   $0x0,0x2(%ebx)
 8049ec5:	b8 00 00 00 00       	mov    $0x0,%eax
 8049eca:	eb 49                	jmp    8049f15 <driver_post+0x7f>
 8049ecc:	85 c0                	test   %eax,%eax
 8049ece:	74 37                	je     8049f07 <driver_post+0x71>
 8049ed0:	80 38 00             	cmpb   $0x0,(%eax)
 8049ed3:	74 32                	je     8049f07 <driver_post+0x71>
 8049ed5:	89 5c 24 18          	mov    %ebx,0x18(%esp)
 8049ed9:	89 54 24 14          	mov    %edx,0x14(%esp)
 8049edd:	c7 44 24 10 87 aa 04 	movl   $0x804aa87,0x10(%esp)
 8049ee4:	08 
 8049ee5:	89 44 24 0c          	mov    %eax,0xc(%esp)
 8049ee9:	c7 44 24 08 8e aa 04 	movl   $0x804aa8e,0x8(%esp)
 8049ef0:	08 
 8049ef1:	c7 44 24 04 50 00 00 	movl   $0x50,0x4(%esp)
 8049ef8:	00 
 8049ef9:	c7 04 24 f4 a7 04 08 	movl   $0x804a7f4,(%esp)
 8049f00:	e8 e0 f8 ff ff       	call   80497e5 <submitr>
 8049f05:	eb 0e                	jmp    8049f15 <driver_post+0x7f>
 8049f07:	66 c7 03 4f 4b       	movw   $0x4b4f,(%ebx)
 8049f0c:	c6 43 02 00          	movb   $0x0,0x2(%ebx)
 8049f10:	b8 00 00 00 00       	mov    $0x0,%eax
 8049f15:	83 c4 24             	add    $0x24,%esp
 8049f18:	5b                   	pop    %ebx
 8049f19:	5d                   	pop    %ebp
 8049f1a:	c3                   	ret    

08049f1b <sigalrm_handler>:
 8049f1b:	55                   	push   %ebp
 8049f1c:	89 e5                	mov    %esp,%ebp
 8049f1e:	83 ec 18             	sub    $0x18,%esp
 8049f21:	c7 44 24 08 00 00 00 	movl   $0x0,0x8(%esp)
 8049f28:	00 
 8049f29:	c7 44 24 04 28 aa 04 	movl   $0x804aa28,0x4(%esp)
 8049f30:	08 
 8049f31:	a1 00 b3 04 08       	mov    0x804b300,%eax
 8049f36:	89 04 24             	mov    %eax,(%esp)
 8049f39:	e8 3e ea ff ff       	call   804897c <fprintf@plt>
 8049f3e:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
 8049f45:	e8 a2 ea ff ff       	call   80489ec <exit@plt>
 8049f4a:	90                   	nop
 8049f4b:	90                   	nop

08049f4c <hash>:
 8049f4c:	55                   	push   %ebp
 8049f4d:	89 e5                	mov    %esp,%ebp
 8049f4f:	8b 4d 08             	mov    0x8(%ebp),%ecx
 8049f52:	0f b6 11             	movzbl (%ecx),%edx
 8049f55:	b8 00 00 00 00       	mov    $0x0,%eax
 8049f5a:	84 d2                	test   %dl,%dl
 8049f5c:	74 13                	je     8049f71 <hash+0x25>
 8049f5e:	6b c0 67             	imul   $0x67,%eax,%eax
 8049f61:	0f be d2             	movsbl %dl,%edx
 8049f64:	8d 04 02             	lea    (%edx,%eax,1),%eax
 8049f67:	83 c1 01             	add    $0x1,%ecx
 8049f6a:	0f b6 11             	movzbl (%ecx),%edx
 8049f6d:	84 d2                	test   %dl,%dl
 8049f6f:	75 ed                	jne    8049f5e <hash+0x12>
 8049f71:	5d                   	pop    %ebp
 8049f72:	c3                   	ret    

08049f73 <check>:
 8049f73:	55                   	push   %ebp
 8049f74:	89 e5                	mov    %esp,%ebp
 8049f76:	8b 45 08             	mov    0x8(%ebp),%eax
 8049f79:	89 c2                	mov    %eax,%edx
 8049f7b:	c1 ea 1c             	shr    $0x1c,%edx
 8049f7e:	85 d2                	test   %edx,%edx
 8049f80:	74 24                	je     8049fa6 <check+0x33>
 8049f82:	3c 0a                	cmp    $0xa,%al
 8049f84:	74 20                	je     8049fa6 <check+0x33>
 8049f86:	0f b6 d4             	movzbl %ah,%edx
 8049f89:	83 fa 0a             	cmp    $0xa,%edx
 8049f8c:	74 18                	je     8049fa6 <check+0x33>
 8049f8e:	89 c2                	mov    %eax,%edx
 8049f90:	c1 ea 10             	shr    $0x10,%edx
 8049f93:	80 fa 0a             	cmp    $0xa,%dl
 8049f96:	74 0e                	je     8049fa6 <check+0x33>
 8049f98:	c1 e8 18             	shr    $0x18,%eax
 8049f9b:	83 f8 0a             	cmp    $0xa,%eax
 8049f9e:	0f 95 c0             	setne  %al
 8049fa1:	0f b6 c0             	movzbl %al,%eax
 8049fa4:	eb 05                	jmp    8049fab <check+0x38>
 8049fa6:	b8 00 00 00 00       	mov    $0x0,%eax
 8049fab:	5d                   	pop    %ebp
 8049fac:	c3                   	ret    

08049fad <gencookie>:
 8049fad:	55                   	push   %ebp
 8049fae:	89 e5                	mov    %esp,%ebp
 8049fb0:	53                   	push   %ebx
 8049fb1:	83 ec 14             	sub    $0x14,%esp
 8049fb4:	8b 45 08             	mov    0x8(%ebp),%eax
 8049fb7:	89 04 24             	mov    %eax,(%esp)
 8049fba:	e8 8d ff ff ff       	call   8049f4c <hash>
 8049fbf:	89 04 24             	mov    %eax,(%esp)
 8049fc2:	e8 15 e8 ff ff       	call   80487dc <srand@plt>
 8049fc7:	e8 e0 e9 ff ff       	call   80489ac <rand@plt>
 8049fcc:	89 c3                	mov    %eax,%ebx
 8049fce:	89 04 24             	mov    %eax,(%esp)
 8049fd1:	e8 9d ff ff ff       	call   8049f73 <check>
 8049fd6:	85 c0                	test   %eax,%eax
 8049fd8:	74 ed                	je     8049fc7 <gencookie+0x1a>
 8049fda:	89 d8                	mov    %ebx,%eax
 8049fdc:	83 c4 14             	add    $0x14,%esp
 8049fdf:	5b                   	pop    %ebx
 8049fe0:	5d                   	pop    %ebp
 8049fe1:	c3                   	ret    
 8049fe2:	90                   	nop
 8049fe3:	90                   	nop
 8049fe4:	90                   	nop
 8049fe5:	90                   	nop
 8049fe6:	90                   	nop
 8049fe7:	90                   	nop
 8049fe8:	90                   	nop
 8049fe9:	90                   	nop
 8049fea:	90                   	nop
 8049feb:	90                   	nop
 8049fec:	90                   	nop
 8049fed:	90                   	nop
 8049fee:	90                   	nop
 8049fef:	90                   	nop

08049ff0 <__libc_csu_fini>:
 8049ff0:	55                   	push   %ebp
 8049ff1:	89 e5                	mov    %esp,%ebp
 8049ff3:	5d                   	pop    %ebp
 8049ff4:	c3                   	ret    
 8049ff5:	66 66 2e 0f 1f 84 00 	data32 nopw %cs:0x0(%eax,%eax,1)
 8049ffc:	00 00 00 00 

0804a000 <__libc_csu_init>:
 804a000:	55                   	push   %ebp
 804a001:	89 e5                	mov    %esp,%ebp
 804a003:	57                   	push   %edi
 804a004:	56                   	push   %esi
 804a005:	53                   	push   %ebx
 804a006:	e8 4f 00 00 00       	call   804a05a <__i686.get_pc_thunk.bx>
 804a00b:	81 c3 d5 10 00 00    	add    $0x10d5,%ebx
 804a011:	83 ec 1c             	sub    $0x1c,%esp
 804a014:	e8 63 e7 ff ff       	call   804877c <_init>
 804a019:	8d bb 20 ff ff ff    	lea    -0xe0(%ebx),%edi
 804a01f:	8d 83 20 ff ff ff    	lea    -0xe0(%ebx),%eax
 804a025:	29 c7                	sub    %eax,%edi
 804a027:	c1 ff 02             	sar    $0x2,%edi
 804a02a:	85 ff                	test   %edi,%edi
 804a02c:	74 24                	je     804a052 <__libc_csu_init+0x52>
 804a02e:	31 f6                	xor    %esi,%esi
 804a030:	8b 45 10             	mov    0x10(%ebp),%eax
 804a033:	89 44 24 08          	mov    %eax,0x8(%esp)
 804a037:	8b 45 0c             	mov    0xc(%ebp),%eax
 804a03a:	89 44 24 04          	mov    %eax,0x4(%esp)
 804a03e:	8b 45 08             	mov    0x8(%ebp),%eax
 804a041:	89 04 24             	mov    %eax,(%esp)
 804a044:	ff 94 b3 20 ff ff ff 	call   *-0xe0(%ebx,%esi,4)
 804a04b:	83 c6 01             	add    $0x1,%esi
 804a04e:	39 fe                	cmp    %edi,%esi
 804a050:	72 de                	jb     804a030 <__libc_csu_init+0x30>
 804a052:	83 c4 1c             	add    $0x1c,%esp
 804a055:	5b                   	pop    %ebx
 804a056:	5e                   	pop    %esi
 804a057:	5f                   	pop    %edi
 804a058:	5d                   	pop    %ebp
 804a059:	c3                   	ret    

0804a05a <__i686.get_pc_thunk.bx>:
 804a05a:	8b 1c 24             	mov    (%esp),%ebx
 804a05d:	c3                   	ret    
 804a05e:	90                   	nop
 804a05f:	90                   	nop

0804a060 <__do_global_ctors_aux>:
 804a060:	55                   	push   %ebp
 804a061:	89 e5                	mov    %esp,%ebp
 804a063:	53                   	push   %ebx
 804a064:	83 ec 04             	sub    $0x4,%esp
 804a067:	a1 00 b0 04 08       	mov    0x804b000,%eax
 804a06c:	83 f8 ff             	cmp    $0xffffffff,%eax
 804a06f:	74 13                	je     804a084 <__do_global_ctors_aux+0x24>
 804a071:	bb 00 b0 04 08       	mov    $0x804b000,%ebx
 804a076:	66 90                	xchg   %ax,%ax
 804a078:	83 eb 04             	sub    $0x4,%ebx
 804a07b:	ff d0                	call   *%eax
 804a07d:	8b 03                	mov    (%ebx),%eax
 804a07f:	83 f8 ff             	cmp    $0xffffffff,%eax
 804a082:	75 f4                	jne    804a078 <__do_global_ctors_aux+0x18>
 804a084:	83 c4 04             	add    $0x4,%esp
 804a087:	5b                   	pop    %ebx
 804a088:	5d                   	pop    %ebp
 804a089:	c3                   	ret    
 804a08a:	90                   	nop
 804a08b:	90                   	nop

Disassembly of section .fini:

0804a08c <_fini>:
 804a08c:	55                   	push   %ebp
 804a08d:	89 e5                	mov    %esp,%ebp
 804a08f:	53                   	push   %ebx
 804a090:	83 ec 04             	sub    $0x4,%esp
 804a093:	e8 00 00 00 00       	call   804a098 <_fini+0xc>
 804a098:	5b                   	pop    %ebx
 804a099:	81 c3 48 10 00 00    	add    $0x1048,%ebx
 804a09f:	e8 8c e9 ff ff       	call   8048a30 <__do_global_dtors_aux>
 804a0a4:	59                   	pop    %ecx
 804a0a5:	5b                   	pop    %ebx
 804a0a6:	c9                   	leave  
 804a0a7:	c3                   	ret    
