#include "calculator.h"
#include <stdexcept>
double applyOperation(double a, double b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') {
        if (b == 0) throw "Ошибка: В АКАДЕМ!";
        return a / b;
    }
    return 0;
}

bool isValidExpression(const std::string& expr) {
    for (char c : expr) {
        if (!((c >= '0' && c <= '9') || c == '+' || c == '-' || c == '*' || c == '/' || c == '.' || c == ' '))
            return false;
    }
    return true;
}
