
test.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <test>:
   0:	55                   	push   %rbp
   1:	48 89 e5             	mov    %rsp,%rbp
   4:	48 c7 c7 0a 00 00 00 	mov    $0xa,%rdi
   b:	48 c7 c6 0a 00 00 00 	mov    $0xa,%rsi
  12:	48 c7 c2 0a 00 00 00 	mov    $0xa,%rdx
  19:	c9                   	leave
  1a:	c3                   	ret
