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
