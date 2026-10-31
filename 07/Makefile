CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic -g
SRCS = $(wildcard *.c) $(wildcard tasks/*.c)
TARGET = build/main

all: run

$(TARGET): $(SRCS) | build
	$(CC) $(CFLAGS) $(SRCS) $(LDFLAGS) $(LDLIBS) -o $@

build:
	mkdir -p $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf build

.PHONY: all run clean
