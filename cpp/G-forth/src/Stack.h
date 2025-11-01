#pragma once

#include <vector>
#include <iostream>

class Stack {
private:
    std::vector<int> data;

public:
    Stack() = default;
    void push(int value);
    int pop();
    int peek() const;
    bool isEmpty() const;
    size_t size() const;
    void clear();
    void print() const;
};
