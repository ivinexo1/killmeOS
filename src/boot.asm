[org 0x7c00]                        
KERNEL_LOCATION equ 0x1000
xor ax, ax                          
mov es, ax
mov ds, ax
mov bp, 0x8000
mov sp, bp 
      

mov bx, KERNEL_LOCATION


mov ah, 2
mov al, 50
mov ch, 0
mov dh, 0
mov cl, 2
mov dl, [BOOT_DISK]
int 0x13

mov ah, 0
mov al, 0x3
int 0x10

mov dx, 0x3da
in  al, dx
mov dx, 0x3c0
mov al, 0x30
out dx, al
inc dx
in al, dx
and al, 0xf7
dec dx
out dx, al

CODE_SEG equ GDT_code - GDT_start
DATA_SEG equ GDT_data - GDT_start

cli
lgdt [GDT_descriptor]
mov eax, cr0
or eax, 1
mov cr0, eax
jmp CODE_SEG:start_protected_mode

jmp $
                                   
BOOT_DISK:
db 0                                    
GDT_start:                          ; must be at the end of real mode code
    GDT_null:
        dd 0x0
        dd 0x0

    GDT_code:
        dw 0xffff
        dw 0x0
        db 0x0
        db 0b10011010
        db 0b11001111
        db 0x0

    GDT_data:
        dw 0xffff
        dw 0x0
        db 0x0
        db 0b10010010
        db 0b11001111
        db 0x0

GDT_end:

GDT_descriptor:
    dw GDT_end - GDT_start - 1
    dd GDT_start


[bits 32]
start_protected_mode:
mov ax, DATA_SEG
mov ds, ax
mov ss, ax
mov es, ax
mov fs, ax
mov gs, ax
mov ebp, 0x90000
mov esp, ebp
jmp KERNEL_LOCATION

 
times 510-($-$$) db 0              
dw 0xaa55
