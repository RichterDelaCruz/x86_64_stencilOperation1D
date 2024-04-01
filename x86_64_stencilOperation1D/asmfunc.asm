; assembly part using x86-64
section .data

section .text
    bits 64
    default rel; to handle address relocation

    global stencilOperation1D_ASM
    extern printf

stencilOperation1D_ASM:
    push rbp            ; Save the base pointer
    mov rbp, rsp        ; Set up the base pointer
    add rbp, 16

    ; Calculate the sum of XMM0 to XMM3
    addss xmm0, xmm1
    addss xmm0, xmm2
    addss xmm0, xmm3

    ; Load values from memory
    movss xmm4, [rbp + 32]   ; Load the 4th float from memory
    addss xmm0, xmm4         ; Add it to the sum

    ; Load values from memory
    movss xmm5, [rbp + 40]   ; Load the 5th float from memory
    addss xmm0, xmm5         ; Add it to the sum

    ; Load values from memory
    movss xmm6, [rbp + 48]   ; Load the 6th float from memory
    addss xmm0, xmm6         ; Add it to the sum

    ; Load values from memory
    movss xmm7, [rbp + 56]   ; Load the 6th float from memory
    addss xmm0, xmm7         ; Add it to the sum

    pop rbp             ; Restore the base pointer
    ret                 ; Return
    