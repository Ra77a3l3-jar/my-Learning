# Simple makefile for the small project (only what's needed)
CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra
SRCS = Stack.cpp main.cpp
TARGET = forth_simple

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $(TARGET)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)
