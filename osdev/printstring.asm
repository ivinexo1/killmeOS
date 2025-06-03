[org 0x7c00]
mov bp, 0x7000
mov sp, bp
mov ax, 0
mov bx, 0
mov cx, 0
mov dx, 0

mov bx, string
mov ah, 0xe
print:
mov al, [bx]
cmp al, 0
je exit
int 0x10
inc bx
jmp print


exit:
jmp $
string:
db "Hello World!",0
times 510-($-$$) db 0
db 0x55, 0xaa
