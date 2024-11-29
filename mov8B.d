
test.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <test>:
   0:	55                   	push   %rbp
   1:	48 89 e5             	mov    %rsp,%rbp
   4:	49 b8 cd ab ef cd ab 	movabs $0xabcdefabcdefabcd,%r8
   b:	ef cd ab 
   e:	49 b9 cd ab ef cd ab 	movabs $0xabcdefabcdefabcd,%r9
  15:	ef cd ab 
  18:	49 ba cd ab ef cd ab 	movabs $0xabcdefabcdefabcd,%r10
  1f:	ef cd ab 
  22:	4d 8b 00             	mov    (%r8),%r8
  25:	45 8b 00             	mov    (%r8),%r8d
  28:	4d 8b 09             	mov    (%r9),%r9
  2b:	45 8b 09             	mov    (%r9),%r9d
  2e:	4d 8b 12             	mov    (%r10),%r10
  31:	45 8b 12             	mov    (%r10),%r10d
  34:	4c 89 c7             	mov    %r8,%rdi
  37:	44 89 c7             	mov    %r8d,%edi
  3a:	4c 89 ce             	mov    %r9,%rsi
  3d:	44 89 ce             	mov    %r9d,%esi
  40:	4c 89 d3             	mov    %r10,%rbx
  43:	44 89 d3             	mov    %r10d,%ebx
  46:	48 b8 cd ab ef bb aa 	movabs $0xababcdaabbefabcd,%rax
  4d:	cd ab ab 
  50:	ff d0                	call   *%rax
  52:	c9                   	leave
  53:	c3                   	ret
