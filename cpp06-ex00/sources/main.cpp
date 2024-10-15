#include "../includes/ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << argv[0] << " input anything (preferably a char, an int, a float or a double)" << std::endl;
	else
		ScalarConverter::convert(argv[1]);
}


