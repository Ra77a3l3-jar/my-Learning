# ===== Linked List Makefile =====

# Compiler and flags
CC      ?= clang
CFLAGS  ?= -Wall -Wextra -std=c11
DBGFLAGS = -g
RELFLAGS = -O2

# Source and build directories
SRCDIR  = .
BUILDDIR = build

# Library source file
LIB_SRC = src/list.c
LIB_OBJ = $(BUILDDIR)/list.o

# Test files
TEST_SINGLE = testSingleList
TEST_DOUBLE = testDoublyList

# Default build type
all: debug

# === Build types ===
debug: CFLAGS += $(DBGFLAGS)
debug: $(TEST_SINGLE) $(TEST_DOUBLE)

release: CFLAGS += $(RELFLAGS)
release: $(TEST_SINGLE) $(TEST_DOUBLE)

# === Link library object ===
$(LIB_OBJ): $(LIB_SRC)
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# === Link test binaries ===
$(TEST_SINGLE): $(BUILDDIR)/$(TEST_SINGLE).o $(LIB_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(TEST_DOUBLE): $(BUILDDIR)/$(TEST_DOUBLE).o $(LIB_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# === Build test objects ===
$(BUILDDIR)/$(TEST_SINGLE).o: $(TEST_SINGLE).c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR)/$(TEST_DOUBLE).o: $(TEST_DOUBLE).c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# === Run programs ===
run-single: $(TEST_SINGLE)
	./$(TEST_SINGLE)

run-double: $(TEST_DOUBLE)
	./$(TEST_DOUBLE)

run: run-single run-double

# === Clean ===
clean:
	rm -rf $(BUILDDIR) $(TEST_SINGLE) $(TEST_DOUBLE)

.PHONY: all debug release run run-single run-double clean
