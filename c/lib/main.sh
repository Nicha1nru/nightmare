#!/bin/bash
for file in *.c; do
    gcc -shared -o "../${file%.c}.so" -fPIC "$file"
done
echo "All C files compiled into shared object files."