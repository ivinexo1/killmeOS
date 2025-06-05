i386-elf-gcc -ffreestanding -m32 -g -c ../src/kernel.c -o kernel.o
i386-elf-gcc -ffreestanding -m32 -g -c ../src/vga_driver.c -o vga_driver.o
nasm ../src/kernel_entry.asm -f elf -o kernel_entry.o
i386-elf-ld -o full_kernel.bin -Ttext 0x1000 kernel_entry.o kernel.o vga_driver.o --oformat binary
nasm ../src/boot.asm -f bin -o boot.bin
cat boot.bin full_kernel.bin >everything.bin
cat everything.bin zeroes.bin >OS.bin
qemu-system-x86_64 -drive format=raw,file="OS.bin",index=0,if=floppy -m 128M
