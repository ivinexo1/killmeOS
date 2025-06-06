# <p align="center" dir="auto">killmeOS</p>
<div align="center" dir="auto">
  <img src="https://img.shields.io/github/contributors/ivinexo1/killmeOS"></img>
  <img src="https://img.shields.io/github/commit-activity/w/ivinexo1/killmeOS"></img>
  <img src="https://img.shields.io/github/stars/ivinexo1/killmeOS"></img>
</div>

Open-source OS made from scratch.

## How to contribute

~ Tutorial for Linux users
1. Clone the repository `git clone "https://github.com/ivinexo1/killmeOS/"`
2. Install qemu:\
For debian: `apt-get install qemu-system`\
For arch: `pacman -S qemu-full`\
Or build it yourself:
```
wget https://download.qemu.org/qemu-10.0.2.tar.xz
tar xvJf qemu-10.0.2.tar.xz
cd qemu-10.0.2
./configure
make
```
3. Install nasm:\
For debian: `apt-get install nasm`\
For arch: `pacman -S nasm`\
Or for your distro\
4. Install i386-elf-gcc\
For arch: `yay i386-elf-gcc` or `paru i368-elf-gcc`\
For debian: will add later but there shoud be resources on the web
5. ~Be happy to not use Windows :>~

~ Tutorial for Windows 10/11 users :pp
1. Clone the repository `git clone "https://github.com/ivinexo1/killmeOS/"`
2. Install [QEMU](https://download.qemu.org/)
3. Open Powershell as admin
4. `winget install nasm -i`
5. Find where you have installed nasm (for example: `C:\Program Files\NASM`) and open the `nasmpath.bat` file
6. `cd "C:\Users\[your name]\Documents\GitHub\killmeOS\osdev"` Go to the dir where you clonned the repo
7. `nasm -f bin boot.asm -o boot.bin`
8. Go to where you installed QEMU and add that as an environment path (for example: `C:\Program Files\qemu\`)
9. Then go back to the QEMU folder and find a file called `qemu-system-x86_64.exe`, then copy as path
10. Now back in `nasmpath.bat` enter the path to the .exe followed by boot.bin (for example: `"C:\Program Files\qemu\qemu-system-x86_64.exe" boot.bin`)
11. Now, finally if you've done everything correctly it should launch killmeOS in QEMU virtual machine :>
