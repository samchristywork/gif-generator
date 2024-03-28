CC=gcc
CFLAGS=$(shell pkg-config --cflags cairo)
LDFLAGS=$(shell pkg-config --libs cairo) -lm

all: build/main

build/main: src/main.c
	mkdir -p build
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

.PHONY: clean
clean:
	rm -rf build
