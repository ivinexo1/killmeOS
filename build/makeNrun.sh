i386-elf-gcc -ffreestanding -m32 -W -g -c ../src/kernel.c -o ./objfiles/kernel.o
i386-elf-gcc -ffreestanding -m32 -W -g -c ../src/vga_driver.c -o ./objfiles/vga_driver.o
i386-elf-gcc -ffreestanding -m32 -W -g -c ../src/ports.c -o ./objfiles/ports.o
i386-elf-gcc -ffreestanding -m32 -W -g -c ../src/idt.c -o ./objfiles/idt.o
i386-elf-gcc -ffreestanding -m32 -W -g -c ../src/isr.c -o ./objfiles/isr.o
i386-elf-gcc -ffreestanding -m32 -g -c ../src/keyboard.c -o ./objfiles/keyboard.o
i386-elf-gcc -ffreestanding -m32 -g -c ../src/shell.c -o ./objfiles/shell.o
nasm ../src/isrhandler.asm -f elf -o ./objfiles/isrhandler.o
nasm ../src/kernel_entry.asm -f elf -o ./objfiles/kernel_entry.o
i386-elf-ld -o ./binfiles/full_kernel.bin -Ttext 0x1000 ./objfiles/kernel_entry.o ./objfiles/kernel.o ./objfiles/vga_driver.o ./objfiles/ports.o ./objfiles/idt.o ./objfiles/isr.o ./objfiles/isrhandler.o ./objfiles/keyboard.o ./objfiles/shell.o --oformat binary
nasm ../src/boot.asm -f bin -o ./binfiles/boot.bin
cat ./binfiles/boot.bin ./binfiles/full_kernel.bin >./binfiles/everything.bin
cat ./binfiles/everything.bin zeroes.bin >OS.bin
qemu-system-i386 -drive format=raw,file="OS.bin",index=0,if=floppy -m 128M
#qemu-system-i386 -fda OS.bin

