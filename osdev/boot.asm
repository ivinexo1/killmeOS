[org 0x7c00]
mov bp, 0x7000
mov sp, bp
mov ax, 0
mov bx, 0
mov cx, 0
mov dx, 0
mov ax, [num]

mov bx, 10000

print:
div bx
add ax, '0'
mov ah, 0xe
int 0x10
push dx

cmp bx, 1
je exit
mov dx, 0
mov ax, bx
mov bx, 10
div bx
mov bx, ax

pop ax
jmp print

exit:
jmp $
num:
dw 64845
times 510-($-$$) db 0
db 0x55, 0xaa
