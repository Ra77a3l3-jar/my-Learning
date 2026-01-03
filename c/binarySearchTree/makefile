# Compiler and flags
CC      ?= clang
CFLAGS  ?= -Wall -Wextra -std=c11 -g
DBGFLAGS = -g
RELFLAGS = -O2

# Target binary name 
TARGET  ?= app

# Source and build directories
SRCDIR  = src
BUILDDIR = build

# Collect all .c files automatically
SRCS    := $(wildcard $(SRCDIR)/*.c)
OBJS    := $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SRCS))

# Test file
TEST    = testBST.c
TESTOBJ = $(BUILDDIR)/testBST.o

# Default build type
all: debug

debug: CFLAGS += $(DBGFLAGS)
debug: $(TARGET)

release: CFLAGS += $(RELFLAGS)
release: $(TARGET)

$(TARGET): $(OBJS) $(TESTOBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TESTOBJ): $(TEST)
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(BUILDDIR) $(TARGET)

.PHONY: all debug release run clean
