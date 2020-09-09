#!/bin/bash

# Aditionally sudo apt install gcc-multilib required on 64-bit linux
echo "[+] Compile gcc -g -fno-stack-protector -z execstack -m32 -o $1.out $1.c ..."
gcc -g -fno-stack-protector -z execstack -m32 -o $1.out $1.c

echo '[+] Done!'