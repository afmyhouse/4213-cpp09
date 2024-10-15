#include <iostream>
#include <stack>
#include <sstream>
#include <stdexcept>

// Function to evaluate an RPN expression
double evaluateRPN(const std::string& expression) {
	std::stack<double> stack;
	std::istringstream tokens(expression);
	std::string token;

	while (tokens >> token) {
		if (std::isdigit(token[0]) || (token.size() > 1 && std::isdigit(token[1]))) {
			// Token is a number, push it onto the stack
			stack.push(std::stod(token));
		} else {
			// Token is an operator, pop two operands from the stack
			if (stack.size() < 2) {
				throw std::runtime_error("Invalid RPN expression: not enough operands.");
			}
			double operand2 = stack.top(); stack.pop();
			double operand1 = stack.top(); stack.pop();

			if (token == "+") {
				stack.push(operand1 + operand2);
			} else if (token == "-") {
				stack.push(operand1 - operand2);
			} else if (token == "*") {
				stack.push(operand1 * operand2);
			} else if (token == "/") {
				if (operand2 == 0) {
					throw std::runtime_error("Division by zero.");
				}
				stack.push(operand1 / operand2);
			} else {
				throw std::runtime_error("Unknown operator: " + token);
			}
		}
	}

	if (stack.size() != 1) {
		throw std::runtime_error("Invalid RPN expression: too many operands.");
	}

	return stack.top();
}

int main() {
	std::string expression = "3 5 8 * 7 + *";
	try {
		double result = evaluateRPN(expression);
		std::cout << "Result: " << result << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}
