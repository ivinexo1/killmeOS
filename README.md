# <p align="center" dir="auto">killmeOS</p>
<div align="center" dir="auto">
  <img src="https://img.shields.io/github/contributors/ivinexo1/killmeOS"></img>
  <img src="https://img.shields.io/github/commit-activity/w/ivinexo1/killmeOS"></img>
  <img src="https://img.shields.io/github/stars/ivinexo1/killmeOS"></img>
</div>

<div align="center" dir="auto">
  <img src="https://github.com/user-attachments/assets/c319f234-fbf6-473a-9af1-dc54adec1504"></img>
</div>

Open-source OS made from scratch.

## How to setup

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
8. Go to where you installed QEMU and add that as an environment path (for example: `C:\Program Files\qemu\`)
9. Go to powershell and `wsl --install`
10. `wsl -l -o` to check distros
11. Then install Arch Linux `wsl --install -d archlinux` (name might be different but it's archlinux for me)
12. Now you might need to setup stuff like user so you can do specific commands
13. Install nano (or any other text editor) `sudo pacman -S nano`
14. Then inside Arch Linux `sudo pacman -S --needed git base-devel`
15. `git clone https://aur.archlinux.org/yay.git`
16. `cd yay`
17. `makepkg -si` (make sure you're not in the root but using some user)
18. Go to `sudo nano /etc/locale.gen` (nano or any other text editor)
19. And uncomment `#en_US.UTF-8 UTF-8` to `en_US.UTF-8 UTF-8`, then save
20. `sudo locale-gen`
21. Before installing i386-elf-gcc make sure you have ENOUGH MEMORY!! It finally worked for me when I set it to 6gb
22. Check available filesize `df -h`, memory can be changed here `"C:\Users\[your name]\.wslconfig"`
23. And tmpfs file max storage by using `sudo mount -o remount,size=6G /tmp` (this will get reset next reboot)
24. Before you install i386-elf-gcc just know that WSL is going to be using like 90% of your CPU
25. `yay i386-elf-gcc` and enter 1 (for the other options just press enter)
26. Now wait until you download i386-elf-gcc (this might take somewhere between 40 minutes to 3 hours)
27. After it's installed you can check by `i386-elf-gcc -v`
28. If it's installed correctly navigate to the dir of killmeOS build `cd '/mnt/c/Users/[your name]/Documents/GitHub/killmeOS/build'` and execute `./makeNrun.sh`
29. Find where you have installed nasm (for example: `C:\Program Files\NASM`) and open the `nasmpath.bat` file
30. Then go back to the QEMU folder and find a file called `qemu-system-x86_64.exe`, then copy as path
32. Now back in `nasmpath.bat` enter `cd C:\Users\[your name]\Documents\GitHub\killmeOS\build`
33. `"C:\Program Files\qemu\qemu-system-x86_64.exe" -drive format=raw,file="OS.bin",index=0,if=floppy -m 128M`
34. If you've done everything correctly you should now see a QEMU instance running killmeOS :DD
![image](https://github.com/user-attachments/assets/00dc81c1-3106-4da2-bc8e-d1c86b9fc6cd)

