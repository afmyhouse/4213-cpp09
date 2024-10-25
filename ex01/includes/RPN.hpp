#ifndef RPN_HPP
#define RPN_HPP

#include <stdexcept>
#include <sstream>
#include <stack>

// Template class for RPNCalculator
template <typename T>
class RPNCalculator {
private:
	// Private constructor to prevent instantiation
	RPNCalculator();
	~RPNCalculator();
	// Function to handle stack operations (private)
	static void applyOperation(std::stack<T>& stack, const std::string& operation);

public:
	// Public static method to evaluate an RPN expression
	static T calculate(const std::string& expression);
};

#endif // RPNCALCULATOR_HPP
