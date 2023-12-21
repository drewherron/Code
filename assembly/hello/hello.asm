section .data
    hello db 'Hello, World!',0xA,0    ; Define a string "Hello, World!" followed by a new line (0xA) and a null terminator

section .text
    global _start

_start:
    ; Write the string to stdout
    mov eax, 4              ; System call number for sys_write
    mov ebx, 1              ; File descriptor 1 is stdout
    mov ecx, hello          ; Pointer to the string to write
    mov edx, 14             ; Number of bytes to write
    int 0x80                ; Call kernel

    ; Exit the program
    mov eax, 1              ; System call number for sys_exit
    xor ebx, ebx            ; Return 0 status
    int 0x80                ; Call kernel
