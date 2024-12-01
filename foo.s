.text
.globl foo
foo:
   pushq %rbp
   movq %rsp, %rbp
   
   movl %edi, %r8d
   movl %esi, %r8d
   movl %edx, %r8d
   movl (%r8), %r8d
   movl $0x1234ABCD, %r8d

   movq %rdi, %r8
   movq %rsi, %r8
   movq %rdx, %r8
   movq (%r8), %r8
   movq $0, %r8
   
   movl %edi, %r9d
   movl %esi, %r9d
   movl %edx, %r9d
   movl (%r9), %r9d
   movl $0, %r9d

   movq %rdi, %r9
   movq %rsi, %r9
   movq %rdx, %r9
   movq (%r9), %r9
   movq $0, %r9

   movl %edi, %r10d
   movl %esi, %r10d
   movl %edx, %r10d
   movl (%r10), %r10d
   movl $0, %r10d

   movq %rdi, %r10
   movq (%rdi), %r10
   movq %rsi, %r10
   movq %rdx, %r10
   movq (%r10), %r10
   movq $0xFFFFFFFFFFFFFFFF, %r10 /*não entendi*/

   movl %r8d, %edi
   movq %r8, %rdi
 
   movl %r9d, %esi
   movq %r9, %rsi
      
   movl %r10d, %edx
   movq %r10, %rdx

   movq %rdi, %rax
   call *%rax
   
   leave
   ret