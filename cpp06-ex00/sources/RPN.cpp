# include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& copy)
{
	*this = copy;
}

RPN::~RPN() {}

RPN& RPN::operator=(const RPN& right)
{
	if (this == &right)
		return (*this);
	return (*this);
}

void RPN::convert(const std::string &str)
{
	if (isChar(str))
	{
		// std::cout << "Char" << std::endl;
		convertNumber(str, str[0]);
	}
	else if (isInt(str))
	{
		// std::cout << "Int" << std::endl;
		convertNumber(str, std::atoi(str.c_str()));
	}
	else if (isFloat(str))
	{
		// std::cout << "Float" << std::endl;
		convertNumber(str, std::strtof(str.c_str(), NULL));
	}
	else if (isDouble(str))
	{
		// std::cout << "Double" << std::endl;
		convertNumber(str, std::strtod(str.c_str(), NULL));
	}
	else if (isPseudo(str))
	{
		// std::cout << "Pseudo" << std::endl;
		printPseudo(str);
	}else
		std::cout << std::endl << "' " << str << " ' : conversion not possible!" << std::endl << std::endl;
}

void RPN::convertNumber(const std::string& input, long double number)
{
	printChar(static_cast<char>(number), input);
	printInt(static_cast<int>(number), input);
	printFloat(static_cast<float>(number), input);
	printDouble(static_cast<double>(number), input);
}

void RPN::printChar(char c, const std::string &input)
{
	if (checkOverflow(input, CHAR))
		std::cout << "char: overflow\n";
	else if (std::isprint(c))
		std::cout << "char: '" << c << "'\n";
	else
		std::cout << "char: Non displayable\n";
}

void RPN::printInt(int num, const std::string &str)
{
	if (checkOverflow(str, INT))
		std::cout << "int: overflow\n";
	else
		std::cout << "int: " << num << "\n";
}

void RPN::printFloat(float num, const std::string &str)
{
	if (checkOverflow(str, FLOAT))
		std::cout << "float: overflow\n";
	else
	{
		std::cout << std::fixed;
		if (num - std::floor(num) == 0)
			std::cout << std::setprecision(1);
		else
			std::cout << std::setprecision(7) ;
		std::cout << "float: " << num << "f" << std::endl;
	}
}

void RPN::printDouble(double num, const std::string &str)
{
	if (checkOverflow(str, DOUBLE))
		std::cout << "double: overflow\n";
	else
	{
		std::cout << std::fixed;
		if (num - std::floor(num) == 0)
			std::cout << std::setprecision(1);
		else
			std::cout << std::setprecision(7);
		std::cout << "double: " << num << std::endl;

	}
}

void RPN::printPseudo(const std::string &str)
{
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";

	if (str.find("nan") != std::string::npos)
	{
		std::cout << "float: nanf\n";
		std::cout << "double: nan\n";
	}
	else
	{
		std::cout << "float: " << str[0] << "inff" << "\n";
		std::cout << "double: " << str[0] << "inf" << "\n";
	}
}

bool RPN::checkOverflow(const std::string &str, t_type type)
{
	long double d;

	d = std::strtold(str.c_str(), NULL);
	switch (type)
	{
		case CHAR:
			return (d < std::numeric_limits<char>::min() \
				|| d > std::numeric_limits<char>::max());
		case INT:
			return (d < std::numeric_limits<int>::min() \
				|| d > std::numeric_limits<int>::max());
		case FLOAT:
			return (d < -std::numeric_limits<float>::max()  \
				|| d > std::numeric_limits<float>::max());
		case DOUBLE:
			return (d < -std::numeric_limits<double>::max() \
				|| d > std::numeric_limits<double>::max());
		default:
			return (false);
	}
}

bool RPN::isChar(const std::string &str)
{
	bool size = str.size() == 1;
	bool isprint = std::isprint(str[0]);
	bool notdigit = !std::isdigit(str[0]);

	return (size && isprint && notdigit);
}

bool RPN::isInt(const std::string &str)
{
	if (str.empty())
		return false;

	size_t signal = str.find_first_of("+-");
	if (signal != std::string::npos && signal != 0)
		return false;

	size_t startPos = (signal == 0) ? 1 : 0;
	size_t validNum = str.find_first_not_of(DIGITS, startPos);
	if (validNum != std::string::npos)
		return false;

	long double d = std::strtod(str.c_str(), NULL);
	bool of = (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max()) ? 1 : 0;
	return (startPos == 1 ? str.size() > 1 : str.size() > 0 && !of);
}

bool RPN::isFloat(const std::string &str)
{
	if (str.empty())
		return false;

	size_t signal = str.find_first_of("+-");
	if (signal != std::string::npos && signal != 0)
		return false;

	size_t startPos = (signal == 0) ? 1 : 0;
	size_t validNum = str.find_first_not_of(FLOATDIGITS, startPos);
	if (validNum != std::string::npos)
		return false;

	size_t f = str.find('f');
	size_t dot = str.find('.');
	if (dot == std::string::npos || f == std::string::npos || f != str.size() - 1)
		return (false);

	std::string decPart = str.substr(dot + 1, f - (dot + 1));
	if (decPart.find('.') != std::string::npos)
		return (false);

	std::string intPart = str.substr(startPos, dot - startPos);

	return (intPart.size() > 0 && decPart.size() > 0);
}

bool RPN::isDouble(const std::string &str)
{
	if (str.empty())
		return false;

	size_t signal = str.find_first_of("+-");
	if (signal != std::string::npos && signal != 0)
		return false;

	size_t startPos = (signal == 0) ? 1 : 0;
	size_t validNum = str.find_first_not_of(DOUBLEDIGITS, startPos);
	if (validNum != std::string::npos)
		return false;

	size_t dot = str.find('.');
	if (dot == std::string::npos)
		return (false);

	std::string decPart = str.substr(dot + 1, str.size() - (dot + 1));
	if (decPart.find('.') != std::string::npos)
		return (false);

	std::string intPart = str.substr(startPos, dot - startPos);

	return (intPart.size() > 0 && decPart.size() > 0);
}

bool RPN::isPseudo(const std::string &str)
{
	return (str == "-inff" || str == "-inf"
		|| str == "nanf" || str == "nan"
		|| str == "+inff" || str == "+inf");
}