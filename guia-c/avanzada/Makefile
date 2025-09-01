CC = gcc
CFLAGS = -Wall -Wextra -pedantic -MMD -MP -g
TARGET = main

SRCS = type.c list.c main.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(FLAGS) $^ -o $@

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm *.o $(TARGET) *.d

.PHONY: all clean

