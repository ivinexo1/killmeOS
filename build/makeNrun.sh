i386-elf-gcc -ffreestanding -m32 -W -g -c ../src/kernel.c -o kernel.o
i386-elf-gcc -ffreestanding -m32 -W -g -c ../src/vga_driver.c -o vga_driver.o
i386-elf-gcc -ffreestanding -m32 -W -g -c ../src/ports.c -o ports.o
i386-elf-gcc -ffreestanding -m32 -W -g -c ../src/idt.c -o idt.o
i386-elf-gcc -ffreestanding -m32 -W -g -c ../src/isr.c -o isr.o
i386-elf-gcc -ffreestanding -m32 -g -c ../src/keyboard.c -o keyboard.o
nasm ../src/isrhandler.asm -f elf -o isrhandler.o
nasm ../src/kernel_entry.asm -f elf -o kernel_entry.o

i386-elf-ld -o full_kernel.bin -Ttext 0x1000 kernel_entry.o kernel.o vga_driver.o ports.o idt.o isr.o isrhandler.o keyboard.o --oformat binary
nasm ../src/boot.asm -f bin -o boot.bin
cat boot.bin full_kernel.bin >everything.bin
cat everything.bin zeroes.bin >OS.bin
qemu-system-i386 -drive format=raw,file="OS.bin",index=0,if=floppy -m 128M
#qemu-system-i386 -fda OS.bin
