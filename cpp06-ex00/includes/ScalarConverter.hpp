#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>
# include <limits>
# include <cmath>

# define DIGITS "0123456789"
# define SIGNAL "-+"
# define FLOATDIGITS "0123456789.f"
# define DOUBLEDIGITS "0123456789."

typedef enum { CHAR, INT, FLOAT, DOUBLE, PSEUDO } t_type;

class ScalarConverter
{

	public:
		static void convert(const std::string &str);

	private:
		//! Constructors and destructor
		ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);
		~ScalarConverter();

		//! Operator overloading
		ScalarConverter& operator=(const ScalarConverter& right);

		//! Parser helpers
		static bool isChar(const std::string &str);
		static bool isInt(const std::string &str);
		static bool isFloat(const std::string &str);
		static bool isDouble(const std::string &str);
		static bool isPseudo(const std::string &str);

		//! Conversions
		static void convertNumber(const std::string &str, long double number);
		static void printChar(char c, const std::string &input);
		static void printInt(int num, const std::string &str);
		static void printFloat(float num, const std::string &str);
		static void printDouble(double num, const std::string &str);
		static void printPseudo(const std::string &str);

		//! Overflow check
		static bool checkOverflow(const std::string &str, t_type type);
};

#endif