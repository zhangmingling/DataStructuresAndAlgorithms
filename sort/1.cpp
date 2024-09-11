#include <iostream>
#include <stack>
#include <string>
#include <sstream>

// 定义运算符函数
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { 
    if (b == 0) throw std::runtime_error("Division by zero"); 
    return a / b; 
} // 注意这里采用整数除法，并检查除数是否为零

// 计算逆波兰表达式的函数
int evaluatePostfix() {
    std::string expression;
    std::cout << "Enter the postfix expression: ";
    std::getline(std::cin, expression); // 读取一行输入作为表达式
    std::istringstream iss(expression);
    std::stack<int> numbers;
    std::string token;

    while (iss >> token) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            // 如果是数字则入栈
            numbers.push(std::stoi(token));
        } else if (token.length() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) {
            // 如果是运算符
            int operand2 = numbers.top(); numbers.pop();  // 先弹出的数字是第一个操作数
            int operand1 = numbers.top(); numbers.pop();  // 后弹出的数字是第二个操作数
            int result;

            switch (token[0]) {
                case '+':
                    result = add(operand1, operand2);
                    break;
                case '-':
                    result = subtract(operand1, operand2);
                    break;
                case '*':
                    result = multiply(operand1, operand2);
                    break;
                case '/':
                    result = divide(operand1, operand2);
                    break;
                default:
                    throw std::runtime_error("Unknown operator");
            }

            // 将结果压回栈中
            numbers.push(result);
        } else {
            throw std::runtime_error("Invalid token encountered");
        }
    }

    // 最终结果应该在栈顶
    if (numbers.empty()) {
        throw std::runtime_error("Stack is empty, invalid expression");
    }
    int result = numbers.top();
    numbers.pop();
    if (!numbers.empty()) {
        throw std::runtime_error("More than one value left on stack");
    }
    return result;
}

int main() {
    try {
        int result = evaluatePostfix();
        std::cout << "The result is " << result << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}