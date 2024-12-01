.text
.globl f_mult
f_mult:
    pushq %rbp
    movq %rsp, %rbp

    movl   %edi,%r8d

    movl    %esi,%r9d

    movl    $0x0000000a,%r10d

    movl %r8d, %edi
    movl %r9d, %esi
    movl %r10d, %edx       
    call mult

    leave 
    ret