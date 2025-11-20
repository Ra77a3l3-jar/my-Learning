# Minimal Makefile for testSingleList using clang

CC = clang
CFLAGS = -Wall -Wextra -std=c11 -g

SRCS = list.c testDoublyList.c
OBJS = $(SRCS:.c=.o)

TARGET = testList

.PHONY: all run clean

all: $(TARGET)

$(TARGET): testDoublyList.o list.o
	$(CC) $(CFLAGS) -o $@ $^

# Compile C sources to objects
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Run the test
run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
