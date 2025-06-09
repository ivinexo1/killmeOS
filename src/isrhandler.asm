global isr0
global isr1
; ... nepacilo sa mi ako long to bolo, takze dodefinujte tie ostatne ked ich pojdete pouzit 
global isr31

; definovat asi treba vsetkych 32 gates, je to velmi smutne

; divide by zero
isr0:
    push byte 0
    push byte 0
    jmp isr_common_stup

; debug
isr1:
    push byte 0
    push byte 1
    jmp isr_common_stup

; TODO: definovat vsetkych 32 [ked to budeme potrebovat niekedy, mozno]

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
