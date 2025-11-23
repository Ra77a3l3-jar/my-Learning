# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -I./include -I../hashMap/include
LDFLAGS =

# Directories
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build

# Automatically collect source files (including hash_map.c for hash function)
SRCS = $(wildcard $(SRC_DIR)/*.c) ../hashMap/src/hash_map.c
OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(filter $(SRC_DIR)/%.c,$(SRCS))) $(BUILD_DIR)/hash_map.o

# Test files
TEST_SRCS = testSet.c
TEST_BINS = $(patsubst %.c,%,$(TEST_SRCS))

# Build modes
DEBUG ?= 0
ifeq ($(DEBUG), 1)
    CFLAGS += -g -DDEBUG
else
    CFLAGS += -O2
endif

# Default target
all: $(BUILD_DIR) $(TEST_BINS)

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compile source files to object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile hash_map.c from hashMap directory
$(BUILD_DIR)/hash_map.o: ../hashMap/src/hash_map.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Build test executables
testSet: testSet.c $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# Run tests
test: testSet
	./testSet

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR) $(TEST_BINS)

# Phony targets
.PHONY: all clean test
