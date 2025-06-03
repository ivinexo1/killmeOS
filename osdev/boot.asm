[org 0x7c00]

mov ah, 0
int 0x16

exit:
jmp $
times 510-($-$$) db 0
db 0x55, 0xaa
