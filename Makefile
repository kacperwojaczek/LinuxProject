PLATFORM=desktop
CFLAGS=-c -Wall
PATHTOARM=/home/kacper/LinuxProject/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin/

ifeq ($(PLATFORM), arm)
	CC= $(PATHTOARM)/arm-linux-gnueabihf-g++
else
	CC=g++ -static
endif

all: main

main: main.o board.o gameController.o player.o database.o
	$(CC) main.o board.o gameController.o player.o database.o -o main

main.o: main.cpp 
	$(CC) $(CFLAGS) main.cpp -o main.o

board.o: board.h board.cpp
	$(CC) $(CFLAGS) board.cpp -o board.o

gameController.o : gameController.h gameController.cpp
	$(CC) $(CFLAGS) gameController.cpp -o gameController.o

player.o : player.h player.cpp
	$(CC) $(CFLAGS) player.cpp -o player.o

database.o : database.h database.cpp
	$(CC) $(CFLAGS) database.cpp -o database.o

.PHONY: clean

clean:
	rm -f *o main
