#!/bin/bash

./corewar champions/$1.cor champions/$2.cor > a.diff
./debug/42corewar champions/$1.cor champions/$2.cor > b.diff

diff -s a.diff b.diff
rm a.diff b.diff

