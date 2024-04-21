#!/usr/bin/env bash

make

# Допустимые значения: 10000, 100000
size=100000

if [ ! -f wordlist.${size} ]; then
  wget https://www.mit.edu/~ecprice/wordlist.${size}
fi

./sort_strings < wordlist.${size}