
teste.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <f_mult>:
   0:	55                   	push   %rbp
   1:	48 89 e5             	mov    %rsp,%rbp
   4:	41 89 f8             	mov    %edi,%r8d
   7:	41 89 f1             	mov    %esi,%r9d
   a:	41 ba 0a 00 00 00    	mov    $0xa,%r10d
  10:	44 89 c7             	mov    %r8d,%edi
  13:	44 89 ce             	mov    %r9d,%esi
  16:	44 89 d2             	mov    %r10d,%edx
  19:	e8 00 00 00 00       	call   1e <f_mult+0x1e>
  1e:	c9                   	leave
  1f:	c3                   	ret
