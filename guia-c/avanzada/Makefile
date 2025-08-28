CC = gcc
CFLAGS = -Wall -Wextra -pedantic
TARGET = main

all: $(TARGET)

$(TARGET): main.o
	$(CC) $(FLAGS) $^ -o $@

main.o: main.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm *.o $(TARGET)

.PHONY: all clean

