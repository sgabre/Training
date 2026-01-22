#!/bin/bash

# Create build directory and run cmake
mkdir -p build
cd build || exit 1
cmake .. 
cmake --build .
./Firmware/Applications/Host/Host
./Firmware/Applications/Assembly/Assembly 12
./Firmware/Applications/Assembly/Assembly 13
./Firmware/Applications/Idiocracy/Idiocracy -e "Voici Mon message a chiffre" -k 123456789
./Firmware/Applications/Idiocracy/Idiocracy -d "675D5A575C167A5757115F56474657505D195012505C5C50514A5C" -k 123456789
./Firmware/Applications/Idiocracy/Idiocracy -s "675D5A575C167A5757115F56474657505D195012505C5C50514A5C" -k ABCDEFGHIJ
./Firmware/Applications/Idiocracy/Idiocracy -v "675D5A575C167A5757115F56474657505D195012505C5C50514A5CABCDEFGHIJ" -k ABCDEFGHIJ