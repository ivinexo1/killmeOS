global isr0

isr0:
push byte 0
push byte 0
jmp isr_common_stup

[extern isr_handler]
isr_common_stup:
pusha

mov ax, ds
push eax

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

push esp
call isr_handler
pop eax

pop eax
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax
popa

add esp, 8

iret
