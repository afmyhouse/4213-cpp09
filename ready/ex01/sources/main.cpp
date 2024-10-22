// main.cpp

#include "../includes/RPN.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " \"RPN_expression\"" << std::endl;
		return 1;
	}

	std::string expression = argv[1];

	try {
		double result = RPNCalculator<double>::calculate(expression);
		std::cout << "Result: " << result << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
