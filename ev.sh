#!/bin/bash
git clone https://github.com/gavinfielder/pft.git
cd pft/
make re
./test
cd ..

git clone https://github.com/Mazoise/42TESTERS-PRINTF.git
cd 42TESTERS-PRINTF/
./runtest.sh
cd ..

git clone https://github.com/charMstr/printf_lover_v2.git
cd printf_lover_v2/
./printf_lover.sh
cd ..
