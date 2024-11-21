
test.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <test>:
   0:	55                   	push   %rbp
   1:	48 89 e5             	mov    %rsp,%rbp
   4:	48 c7 c0 08 00 00 00 	mov    $0x8,%rax
   b:	ff d0                	call   *%rax
   d:	c9                   	leave
   e:	c3                   	ret
