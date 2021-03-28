#!/bin/bash
echo -e "\033[32;1m"NORM"\033[m"
read $a
norminette *.c *.h
echo -e "\033[32;1m"PFT"\033[m"
read $a
git clone https://github.com/gavinfielder/pft.git
cd pft/
make re
./test
cd ..
echo -e "\033[32;1m"42TESTERS-PRINTF"\033[m"
read $a
git clone https://github.com/Mazoise/42TESTERS-PRINTF.git
cd 42TESTERS-PRINTF/
./runtest.sh
cd ..
echo -e "\033[32;1m"printf_lover_v2"\033[m"
read $a
git clone https://github.com/charMstr/printf_lover_v2.git
cd printf_lover_v2/
./printf_lover.sh
cd ..
rm -rf pft/ 42TESTERS-PRINTF/ printf_lover_v2/
make fclean
