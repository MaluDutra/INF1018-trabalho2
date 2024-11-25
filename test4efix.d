
test.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <test>:
   0:	55                   	push   %rbp
   1:	48 89 e5             	mov    %rsp,%rbp
   4:	bf 00 04 00 00       	mov    $0x400,%edi
   9:	be 00 04 00 00       	mov    $0x400,%esi
   e:	ba 00 04 00 00       	mov    $0x400,%edx
  13:	c9                   	leave
  14:	c3                   	ret
