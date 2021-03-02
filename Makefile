# Makefile for idog
# Author: mmdjiji(JiJi)
# GitHub: https://github.com/mmdjiji/idog

VPATH := src
CC := g++
TAR := idog
OBJ := checkid.o main.o tryid.o

$(TAR): $(OBJ)
	$(CC) $(OBJ) -o $(TAR)

%.o: %.cpp
	$(CC) -c $^ -o $@

.PHONY: install uninstall clean

install:
	sudo cp idog /usr/local/bin

uninstall:
	sudo rm /usr/local/bin/idog

clean:
	${RM} $(OBJ)
