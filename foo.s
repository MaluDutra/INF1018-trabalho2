.text
.globl foo
foo:
   pushq %rbp
   movq %rsp, %rbp
  
   movq %rdi, %rax
   call *%rax
   
   leave
   ret