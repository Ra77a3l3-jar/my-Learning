#include "Stack.h"

#include <iostream>
#include <string>


int main() {
    Stack stack;
    std::string token;

    std::cout << "Type bye to exit" << std::endl;
    while (std::cin >> token) {
        std::cout << "ok" << std::endl;

        if (token == "bye") {
            break;
        }

        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (stack.size() < 2) {
                std::cout << "I don't have enough numbers" << std::endl;
                continue;
            }
            int b = stack.pop();
            int a = stack.pop();
            if (token == "+") {
                stack.push(a + b);
            } else if (token == "-") {
                stack.push(a - b);
            } else if (token == "*") {
                stack.push(a * b);
            } else { // /
                if (b == 0) {
                    std::cout << "Division by zero" << std::endl;
                    stack.push(a);
                    stack.push(b);
                    continue;
                }
                stack.push(a / b);
            }
        } else if (token == ".") {
            if (stack.size() < 1) {
                std::cout << "No number to print" << std::endl;
            } else {
                std::cout << stack.pop() << std::endl;
            }
        } else {
            // try to parse integer and push
            try {
                size_t idx = 0;
                int n = stoi(token, &idx);
                if (idx == token.size()) {
                    stack.push(n);
                } else {
                    std::cout << "Unknown token: " << token << std::endl;
                }
            } catch (...) {
                std::cout << "Unknown token: " << token << std::endl;
            }
        }
    }

    return 0;
}
