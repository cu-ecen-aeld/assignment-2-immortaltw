# Compiler and flags (you can override CC for cross-compiling)
CROSS_COMPILE ?=
CC=$(CROSS_COMPILE)gcc
CFLAGS = -Wall -Wextra -O2

# Targets and source files
TARGET = writer
SRC = writer.c
OBJ = $(SRC:.c=.o)

# Default target
all: build

# Build target
build: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

# Clean target
clean:
	rm -f $(TARGET)

.PHONY: all build clean
