#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <vector>

// Функция для выполнения математических операций
double applyOperation(double a, double b, char op);

// Функция для проверки правильности ввода выражения
bool isValidExpression(const std::string& expr);

#endif // CALCULATOR_H
