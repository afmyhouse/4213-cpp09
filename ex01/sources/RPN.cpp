#include "../includes/RPN.hpp"

// Implementation of the applyOperation method
template <typename T>
void RPNCalculator<T>::applyOperation(std::stack<T>& stack, const std::string& operation) {
	if (stack.size() < 2) {
		throw std::runtime_error("Not enough operands for the operation.");
	}
	T operand2 = stack.top(); stack.pop();
	T operand1 = stack.top(); stack.pop();

	if (operation == "+") {
		stack.push(operand1 + operand2);
	} else if (operation == "-") {
		stack.push(operand1 - operand2);
	} else if (operation == "*") {
		stack.push(operand1 * operand2);
	} else if (operation == "/") {
		if (operand2 == 0) {
			throw std::runtime_error("Division by zero.");
		}
		stack.push(operand1 / operand2);
	} else {
		throw std::runtime_error("Unknown operator: " + operation);
	}
}

// Implementation of the calculate method
template <typename T>
T RPNCalculator<T>::calculate(const std::string& expression) {
	std::stack<T> stack;
	std::istringstream stream(expression);
	std::string token;

	while (stream >> token) {
		if (std::isdigit(token[0])){
			if (token.size() > 1) {
				for (size_t i = 1; i < token.size(); i++) {
					if (!std::isdigit(token[i])) {
						throw std::runtime_error("Invalid RPN expression: unknow token.");
					}
				}
				throw std::runtime_error("Invalid RPN expression: number too large.");
			}
			std::istringstream numberStream(token);
			T number;
			numberStream >> number;
			stack.push(number);
		} else if (token.size() == 1 && (token== "+" || token == "-" || token == "*" || token == "/")) {
			applyOperation(stack, token);
		} else {
			throw std::runtime_error("Invalid RPN expression: unknown token.");
		}
	}
	if (stack.size() != 1) {
		throw std::runtime_error("Invalid RPN expression: too many operands.");
	}
	return stack.top();
}

// Explicit instantiation of template types to avoid linker errors
template class RPNCalculator<int>;
template class RPNCalculator<float>;
template class RPNCalculator<double>;
