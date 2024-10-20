#include "../includes/BitcoinExchange.hpp"
#include "../includes/tests.hpp"

int main(int argc, char **argv)
{
	BitcoinExchange	currency;

	if (argc < 2)
		return (E_USE_ARGS_EMPTY(argv[0]), 1);

	if (!currency.btcXchange(argv[1], "data.csv"))
		return (E_INPUT_OPEN(argv[1]), 1);

	return (0);
}
