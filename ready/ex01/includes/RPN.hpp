// RPNCalculator.hpp

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <stdexcept>
#include <sstream>

// Type promotion template to deduce the result type based on input types
template <typename T1, typename T2>
struct PromoteType {
	typedef T1 ResultType;
};

// Specializations for specific type promotions
template <>
struct PromoteType<int, double> {
	typedef double ResultType;
};

template <>
struct PromoteType<double, int> {
	typedef double ResultType;
};

template <>
struct PromoteType<float, double> {
	typedef double ResultType;
};

template <>
struct PromoteType<double, float> {
	typedef double ResultType;
};

template <>
struct PromoteType<int, float> {
	typedef float ResultType;
};

template <>
struct PromoteType<float, int> {
	typedef float ResultType;
};

// Template class for RPNCalculator
template <typename T>
class RPNCalculator {
private:
	// Private constructor to prevent instantiation
	RPNCalculator();

	// Function to handle stack operations (private)
	static void applyOperation(std::stack<T>& stack, const std::string& operation);

public:
	// Public static method to evaluate an RPN expression
	static T calculate(const std::string& expression);
};

#endif // RPNCALCULATOR_HPP
