#include "../includes/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    BitcoinExchange wallet;

	if (argc < 2)
		return (E_USE_ARGS_EMPTY(argv[0]), 1);

	try {
		wallet.btcXchange(argv[1], "data.csv");
		return 0;
	}
	catch (const BitcoinExchangeException &e) {
		std::cerr << SRED << "BTC Exception ERROR: " << e.what() << " => " << e.getParameter() << SRST << std::endl;
		return 1;
	}
	catch (const std::exception &e) {
		std::cerr << SBLU << "STD Exception caught: " << e.what() << std::endl;
		return 1;
	}
}