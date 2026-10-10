CC = gcc
CFLAGS = -g
CPPFLAGS = -Iinclude
SRCS = $(shell find src -type f -name '*.c')
HEADERS = $(shell find include -type f -name '*.h')
TARGET = build/main

all: run

$(TARGET): $(SRCS) $(HEADERS) | build
	$(CC) $(CPPFLAGS) $(CFLAGS) $(SRCS) $(LDFLAGS) $(LDLIBS) -o $@

build:
	mkdir -p $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf build

.PHONY: all run clean
