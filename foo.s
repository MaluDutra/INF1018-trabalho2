.text
.globl foo
foo:
   pushq %rbp
   movq %rsp, %rbp
   
   movl %edi, %r8d
   movl %esi, %r8d
   movl %edx, %r8d
   movl $0x1234, %r8d

   movq %rdi, %r8
   movq %rsi, %r8
   movq %rdx, %r8
   movq $0, %r8
   
   movl %edi, %r9d
   movl %esi, %r9d
   movl %edx, %r9d
   movl $0, %r9d

   movq %rdi, %r9
   movq %rsi, %r9
   movq %rdx, %r9
   movq $0, %r9

   movl %edi, %r10d
   movl %esi, %r10d
   movl %edx, %r10d
   movl $0, %r10d

   movq %rdi, %r10
   movq (%rdi), %r10
   movq %rsi, %r10
   movq %rdx, %r10
   movq $0xFFFFFFFFFFFFFFFF, %r10 /*não entendi*/

   movq %rdi, %rax
   call *%rax
   
   leave
   ret