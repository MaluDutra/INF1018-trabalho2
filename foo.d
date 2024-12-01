
foo.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <foo>:
   0:	55                   	push   %rbp
   1:	48 89 e5             	mov    %rsp,%rbp
   4:	41 89 f8             	mov    %edi,%r8d
   7:	41 89 f0             	mov    %esi,%r8d
   a:	41 89 d0             	mov    %edx,%r8d
   d:	45 8b 00             	mov    (%r8),%r8d
  10:	41 b8 cd ab 34 12    	mov    $0x1234abcd,%r8d
  16:	49 89 f8             	mov    %rdi,%r8
  19:	49 89 f0             	mov    %rsi,%r8
  1c:	49 89 d0             	mov    %rdx,%r8
  1f:	4d 8b 00             	mov    (%r8),%r8
  22:	49 c7 c0 00 00 00 00 	mov    $0x0,%r8
  29:	41 89 f9             	mov    %edi,%r9d
  2c:	41 89 f1             	mov    %esi,%r9d
  2f:	41 89 d1             	mov    %edx,%r9d
  32:	45 8b 09             	mov    (%r9),%r9d
  35:	41 b9 00 00 00 00    	mov    $0x0,%r9d
  3b:	49 89 f9             	mov    %rdi,%r9
  3e:	49 89 f1             	mov    %rsi,%r9
  41:	49 89 d1             	mov    %rdx,%r9
  44:	4d 8b 09             	mov    (%r9),%r9
  47:	49 c7 c1 00 00 00 00 	mov    $0x0,%r9
  4e:	41 89 fa             	mov    %edi,%r10d
  51:	41 89 f2             	mov    %esi,%r10d
  54:	41 89 d2             	mov    %edx,%r10d
  57:	45 8b 12             	mov    (%r10),%r10d
  5a:	41 ba 00 00 00 00    	mov    $0x0,%r10d
  60:	49 89 fa             	mov    %rdi,%r10
  63:	4c 8b 17             	mov    (%rdi),%r10
  66:	49 89 f2             	mov    %rsi,%r10
  69:	49 89 d2             	mov    %rdx,%r10
  6c:	4d 8b 12             	mov    (%r10),%r10
  6f:	49 c7 c2 ff ff ff ff 	mov    $0xffffffffffffffff,%r10
  76:	44 89 c7             	mov    %r8d,%edi
  79:	4c 89 c7             	mov    %r8,%rdi
  7c:	44 89 ce             	mov    %r9d,%esi
  7f:	4c 89 ce             	mov    %r9,%rsi
  82:	44 89 d2             	mov    %r10d,%edx
  85:	4c 89 d2             	mov    %r10,%rdx
  88:	48 89 f8             	mov    %rdi,%rax
  8b:	ff d0                	call   *%rax
  8d:	c9                   	leave
  8e:	c3                   	ret
