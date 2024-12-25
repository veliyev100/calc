#include <iostream>
#include <vector>
#include <string>
#include "calculator.h"

int main() {
    while (true) {
        try {
            std::string expression;
            std::cout << "Введите выражение: ";
            std::getline(std::cin, expression);

            if (!isValidExpression(expression)) throw "Ошибка: Неверный ввод!";

            std::vector<double> numbers;
            std::vector<char> operators;

            // Обработка выражения
            for (size_t i = 0; i < expression.size(); ++i) {
                // Проверка на число (включая отрицательное)
                if ((expression[i] >= '0' && expression[i] <= '9') || expression[i] == '.' ||
                            (expression[i] == '-' && (i == 0 || expression[i - 1] == '+' || expression[i - 1] == '-' || expression[i - 1] == '*' || expression[i - 1] == '/'))) {
                    size_t j = i;
                    while (j < expression.size() &&
                           ((expression[j] >= '0' && expression[j] <= '9') || expression[j] == '.' ||
                                (j == i && expression[j] == '-'))) ++j;
                    try {
                        numbers.push_back(std::stod(expression.substr(i, j - i)));
                    } catch (const std::exception&) {
                        throw "Ошибка: Неверный формат числа!";
                    }
                    i = j - 1;
                } else if (expression[i] == '+' || expression[i] == '-' ||
                expression[i] == '*' || expression[i] == '/') {
                    operators.push_back(expression[i]);
                } else if (expression[i] != ' ') { // Игнорируем пробелы
                    throw "Ошибка: Неверный символ в выражении!";
                }
            }

            // Обрабатываем операции умножения и деления
            for (size_t i = 0; i < operators.size(); ++i) {
                if (operators[i] == '*' || operators[i] == '/') {
                    numbers[i + 1] = applyOperation(numbers[i], numbers[i + 1], operators[i]);
                    numbers[i] = 0; // Не используемое значение
                    operators[i] = '+';  // Убираем оператор умножения или деления
                }
            }

            // Вычисление результата с учётом сложения и вычитания
            double result = numbers[0];
            for (size_t i = 0; i < operators.size(); ++i) {
                result = applyOperation(result, numbers[i + 1], operators[i]);
            }

            std::cout << "Результат: " << result << std::endl;
        } catch (const char* err) {
            std::cout << err << "\nМатематик.\n";
        }
    }
    return 0;
}