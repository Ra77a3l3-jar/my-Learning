#include "Stack.h"
#include <stdexcept>

void Stack::push(int value) {
    data.push_back(value);
}

int Stack::pop() {
    if (data.empty()) {
        throw std::runtime_error("Stack underflow");
    }
    int v = data.back();
    data.pop_back();
    return v;
}

// Returns the data at the top of the stack
int Stack::peek() const {
    if (data.empty()) {
        throw std::runtime_error("Stack is empty");
    }
    return data.back();
}

bool Stack::isEmpty() const {
    return data.empty();
}

size_t Stack::size() const {
    return data.size();
}

void Stack::clear() {
    data.clear();
}

void Stack::print() const {
    std::cout << "Stack: [";
    for (size_t i = 0; i < data.size(); ++i) {
        std::cout << data[i];
        if (i + 1 < data.size()) std::cout << " ";
    }
    std::cout << "]\n";
}
