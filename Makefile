CC = cc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic
SOURCES = main.c ships_input.c slopeforships.c input_and_prove.c danger_signal.c

.PHONY: all
all: build/lab3

build/lab3: $(SOURCES) structures.h danger_signal.h
	mkdir -p build
	$(CC) $(CFLAGS) $(SOURCES) -o $@
