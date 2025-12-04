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

# Test files
TEST_LIST = testStackList
TEST_ARR = testStackArr

# Default build type
all: debug

debug: CFLAGS += $(DBGFLAGS)
debug: $(TEST_LIST) $(TEST_ARR)

release: CFLAGS += $(RELFLAGS)
release: $(TEST_LIST) $(TEST_ARR)

$(TEST_LIST): $(OBJS) $(BUILDDIR)/testStackList.o
	$(CC) $(CFLAGS) -o $@ $^

$(TEST_ARR): $(OBJS) $(BUILDDIR)/testStackArr.o
	$(CC) $(CFLAGS) -o $@ $^

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR)/testStackList.o: testStackList.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR)/testStackArr.o: testStackArr.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

run-list: $(TEST_LIST)
	./$(TEST_LIST)

run-arr: $(TEST_ARR)
	./$(TEST_ARR)

clean:
	rm -rf $(BUILDDIR) $(TEST_LIST) $(TEST_ARR)

.PHONY: all debug release run-list run-arr clean
