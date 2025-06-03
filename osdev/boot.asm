[org 0x7c00]
mov dx, 0

mov bx, 1000
mov ax, bx
mov bx, 10
div bx
mov ah, 0
mov bx, ax


jmp $
num:
dw 8546
times 510-($-$$) db 0
db 0x55, 0xaa
