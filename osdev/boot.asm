[org 0x7c00]
mov bp, 0x7000
mov sp, bp

scan:
mov ah, 0
int 0x16
cmp ah, 28
je exit
mov ah, 0
push ax
mov ah, 0xe
int 0x10
jmp scan

exit:
jmp $
times 510-($-$$) db 0
db 0x55, 0xaa
