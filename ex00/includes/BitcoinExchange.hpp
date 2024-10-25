#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <iomanip>
# include <iostream>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <map>

#ifndef _CSV_
# define _CSV_ ','
#endif

#ifndef _WALLET_
# define _WALLET_ '|'
#endif
const std::string SRED = "\033[1;31m";
const std::string SGRN = "\033[1;32m";
const std::string SBLU = "\033[1;34m";
const std::string SRST = "\033[0m";
const std::string in_header = "date | amount";
const std::string db_header = "date,exchange_rate";

# define TESTNUM	2

# define E_MSG(err_msg) 		std::cout << SRED << err_msg << SRST << std::endl
# define E_USE_ARGS_EMPTY(e)	E_MSG("ERROR : How to use > " << e << " [file]")
# define E_USE_ARGS_NONUM		E_MSG("ERROR : test number > use a NUMBER!!!")
# define E_USE_ARGS_LIMITS		E_MSG("ERROR : test number > choose one between 0 and " << TESTNUM)

# define E_INPUT_FORMAT(e)		E_MSG("ERROR: file input : invalid input formating => '" << e << "'")
# define E_DATE_INVALID(e)		E_MSG("ERROR: file input : invalid date => '" << e << "'")
# define E_NUM_LIMITS(e)		E_MSG("ERROR: file input : invalid amount : out of range [0, 1000] => '" << std::fixed << std::setprecision(0) << e << "'")
# define E_NUM_NEGATIVE(e)		E_MSG("ERROR: file input : invalid amount : negative => '" << e << "'")

class BitcoinExchange
{
	private:
		std::map<std::string, float> _database;

		bool readInputAmount(const char *btcInput);
		bool readExchangeRates(const char* database);
		bool lineValidation(const std::string &line, std::string &date, double &rate, char delimiter);
		bool dateValidation(const std::string &date);
		bool fileValidation(const char *filename, const char* ext, const char* msg);
		double getRateAtNearestDate(const std::string &date);

	public:
		//! Constructors and destructor
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& copy);
		~BitcoinExchange();

		//! Operator overloading
		BitcoinExchange& operator=(const BitcoinExchange& right);

		//! Member functions
		bool btcXchange(const char *filename, const char* btcRatesDB);

};

class BitcoinExchangeException : public std::exception {
public:
	BitcoinExchangeException(const std::string& message, const std::string& parameter)
		: message_(message), parameter_(parameter) {}

	// Destructor with the correct exception specification
	virtual ~BitcoinExchangeException() throw() {}

	// Use the throw() exception specification instead of noexcept
	const char* what() const throw() {
		return message_.c_str();
	}

	// Custom method to retrieve the parameter (e.g., file name or specific info)
	const std::string& getParameter() const {
		return parameter_;
	}

private:
	std::string message_;
	std::string parameter_;
};

#endif
