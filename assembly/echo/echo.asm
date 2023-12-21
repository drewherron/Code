section .data
    msg db 'Enter some text: ', 0
    len equ $ - msg               ; Length of the prompt message
    buffer resb 256               ; Reserve 256 bytes for input buffer

section .text
    global _start

_start:
    ; Print prompt message
    mov eax, 4                   ; sys_write
    mov ebx, 1                   ; File descriptor 1 (stdout)
    mov ecx, msg                 ; Pointer to message
    mov edx, len                 ; Length of message
    int 0x80                     ; Call kernel

    ; Read input from user
    mov eax, 3                   ; sys_read
    mov ebx, 0                   ; File descriptor 0 (stdin)
    mov ecx, buffer              ; Pointer to input buffer
    mov edx, 256                 ; Maximum number of bytes to read
    int 0x80                     ; Call kernel

    ; Save number of bytes read into edx
    mov edx, eax

    ; Print user input
    mov eax, 4                   ; sys_write
    mov ebx, 1                   ; File descriptor 1 (stdout)
    mov ecx, buffer              ; Pointer to input buffer
    int 0x80                     ; Call kernel

    ; Exit the program
    mov eax, 1                   ; sys_exit
    xor ebx, ebx                 ; Return 0 status
    int 0x80                     ; Call kernel
