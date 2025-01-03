EFLAG = -Wall -Werror
LFLAG = -lsodium

run: des
	./des

des: key.o
	gcc -o des key.o des.c $(EFLAG) $(LFLAG)

key: key.c
	gcc -c key.c $(EFLAG) $(LFLAG)

clean:
	rm *.o des
