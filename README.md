# <p align="center" dir="auto">killmeOS</p>
<div align="center" dir="auto">
  <img src="https://img.shields.io/github/contributors/ivinexo1/killmeOS"></img>
  <img src="https://img.shields.io/github/commit-activity/w/ivinexo1/killmeOS"></img>
  <img src="https://img.shields.io/github/stars/ivinexo1/killmeOS"></img>
</div>

<div align="center" dir="auto">
  <img src="https://github.com/user-attachments/assets/c319f234-fbf6-473a-9af1-dc54adec1504"></img>
</div>

Open-source OS made from scratch

[join the killmeOS discord](http://discord.gg/cTumjQQkUp)

<img width="640" height="360" alt="image" src="https://github.com/user-attachments/assets/072e0721-a3fa-4b5e-a628-1a60e1012763" />

# How to setup!!
This guide contains tutorials for both Linux and Windows 11
## Linux 🐧

1. Clone repository
```bash
git clone "https://github.com/ivinexo1/killmeOS/"
```
2. Install QEMU (for Debian : ```apt-get install qemu-system```, Arch: ```pacman -S qemu-full```) or build it yourself
```bash
wget https://download.qemu.org/qemu-10.0.2.tar.xz
tar xvJf qemu-10.0.2.tar.xz
cd qemu-10.0.2
./configure
make
```
3. Install NASM (for Debian: ```apt-get install nasm```, Arch: ```pacman -S nasm```)
5. Install i386-elf-gcc (for Debian: add this later, Arch: ```yay i386-elf-gcc``` or ```paru i368-elf-gcc```)
6. Navigate to the repository and run ```./makeNrun.sh```

## Windows 11 🪟
1. Clone repository
```shell
git clone "https://github.com/ivinexo1/killmeOS/"
```
2. Install [QEMU](https://download.qemu.org/)
3. Install NASM
```shell
winget install nasm -i
```
4. Add QEMU as an env path
5. Install WSL ```wsl --install```, check for available distros ```wsl -l -o```
6. Install archlinux (optional, but that's what this tutorial is focusing on) ```wsl --install -d archlinux```
7. Install a text editor (doesn't matter which) ```sudo pacman -S nano```
```
sudo pacman -S --needed git base-devel
```
8. Install yay
```
git clone https://aur.archlinux.org/yay.git
cd yay
```
9. (Just make sure you're not in root but some user)
```
makepkg -si
```
10. Go to ```sudo nano /etc/locale.gen``` and uncomment ```#en_US.UTF-8 UTF-8``` (remove #)
11. ```sudo locale-gen```
12. Before installing i386-elf-gcc make sure you have ENOUGH MEMORY!! It finally worked for me when I set it to 6gb
13. Check available filesize ```df -h```, memory can be changed here ```C:\Users\[your name]\.wslconfig```
```
sudo mount -o remount,size=6G /tmp
```
14. Before you install i386-elf-gcc just know that WSL is going to be using like 90% of your CPU
15. ```yay i386-elf-gcc``` and enter 1 (for the other options just press enter)
16. Once it's done check ```i386-elf-gcc -v```
17. If it's installed navigate to killmeOS (running `./makeNrun.sh` is optional)
```
cd '/mnt/c/Users/[your name]/Documents/GitHub/killmeOS/build'
./makeNrun.sh
```
