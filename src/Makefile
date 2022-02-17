.PHONY: all clean

CC = gcc
CFLAGS = -c -Wall -Werror -Wextra -std=c11

rebuild: clean all

all: ../build/Quest_1

../build/Quest_1: door_struct
	$(CC) door_struct.o -o ../build/Quest_1

door_struct: dmanager_module.c
	$(CC) $(CFLAGS) -c dmanager_module.c -o door_struct.o -DDMANAGER_MODULE_C

clean:
	rm -rf *.o main
