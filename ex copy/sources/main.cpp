#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	BitcoinExchange	currency;

	if (argc < 2)
		return (ERROR_USAGE, 1);
	if (!currency.convert(argv[1]))
		return (E_OPEN_FILE(argv[1]), 1);
	return (0);
}
