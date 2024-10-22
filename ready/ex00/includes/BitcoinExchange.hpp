#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <iostream>
# include <iomanip>
# include <fstream>
# include <limits>
# include <sstream>
# include <string>
# include <cstring>
# include <cstdlib>
# include <ctime>
# include <map>

#ifndef _CSV_
# define _CSV_ ','
#endif

#ifndef _WALLET_
# define _WALLET_ '|'
#endif

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
