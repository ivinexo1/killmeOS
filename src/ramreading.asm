[org 0x7c00]

xor ax, ax
mov es, ax

mov [disknum], dl
mov ah, 2
mov al, 1
mov ch, 0
mov cl, 2
mov dh, 0
mov dl, [disknum]
mov bx, 0x7e00
int 0x13

mov ah, 0xe
mov al, [0x7e00]
int 0x10



jmp $
disknum:
db 0
times 510-($-$$) db 0
db 0x55, 0xaa
times 512 db 'a'
