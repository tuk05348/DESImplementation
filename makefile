#Niaz Baharudeen
#26 January 2025
#DES Implementation
#Makefile: Lets us easily compile and link function files and run the main des file
#and clean our enviroment of object files as well

EFLAG = -Wall -Werror #Flag to enhance checking for errors when compiling
LFLAG = -lsodium #Flag to link libsodium when compiling key function file

run: des
	./des

des: key.o
	gcc -o des key.o des.c $(EFLAG) $(LFLAG)

key: key.c
	gcc -c key.c $(EFLAG) $(LFLAG)

clean:
	rm *.o des
