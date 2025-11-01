#include <iostream>
#include <string>

using namespace std;

#define MAX_ELEMENTS (100)

int main() {
    string stringhe[MAX_ELEMENTS];
    int i = 0;
    cout << "Type bye to exit" << endl;
    while (true) {
        if (i >= MAX_ELEMENTS) {
            break;
        }
        cin >> stringhe[i];
        cout << "ok" << endl;
        int result;
        if (stringhe[i] == "bye") {
            break;
        }
        if (stringhe[i] == "+" || stringhe[i] == "-" || stringhe[i] == "*" || stringhe[i] == "/") {
            if (i < 2) {
                cout << "I don't have enough numbers" << endl;
            } else {
                if (stringhe[i] == "+") {
                    result = stoi(stringhe[i-1]) + stoi(stringhe[i-2]);
                } else if (stringhe[i] == "-") {
                    result = stoi(stringhe[i-1]) - stoi(stringhe[i-2]);
                } else if (stringhe[i] == "*") {
                    result = stoi(stringhe[i-1]) * stoi(stringhe[i-2]);
                } else if (stringhe[i] == "/") {
                    result = stoi(stringhe[i-1]) / stoi(stringhe[i-2]);
                }
                i -= 2;
                stringhe[i] = to_string(result);
                i++;
            }
        } else if (stringhe[i] == ".") {
            if (i >= 1) {
                cout << stringhe[i-1] << endl;
                i--;
            } else {
                cout << "No number to print" << endl;
            }
        } else {
            i++;
        }
    }
    return 0;
}
