#include "../includes/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	BitcoinExchange	currency;

	if (argc < 2)
		return (ERROR_USAGE, 1);
	if (!currency.btcXchange(argv[1], "data.csv"))
		return (ERROR_BAD_FILE(argv[1]), 1);
	return (0);
}
