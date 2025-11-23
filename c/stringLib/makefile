# ===== Generic Reusable Makefile =====

# Compiler and flags
CC      ?= clang
CFLAGS  ?= -Wall -Wextra -std=c11
DBGFLAGS = -g
RELFLAGS = -O2

# Target binary name (override with: make TARGET=myprog)
TARGET  ?= app

# Source and build directories
SRCDIR  = .
BUILDDIR = build

# Collect all .c files automatically
SRCS    := $(wildcard $(SRCDIR)/*.c)
OBJS    := $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SRCS))

# Default build type
all: debug

# === Build types ===
debug: CFLAGS += $(DBGFLAGS)
debug: $(TARGET)

release: CFLAGS += $(RELFLAGS)
release: $(TARGET)

# === Link target ===
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# === Build objects to build/ ===
$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# === Run program ===
run: $(TARGET)
	./$(TARGET)

# === Clean ===
clean:
	rm -rf $(BUILDDIR) $(TARGET)

.PHONY: all debug release run clean
