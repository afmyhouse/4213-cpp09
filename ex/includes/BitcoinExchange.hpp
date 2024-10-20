#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <limits>
# include <sstream>
# include <string>
# include <cstring>
# include <cstdlib>
# include <ctime>
# include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _database;

		bool readExchangeRates(const char* database);
		bool inputReadLine(const std::string &line, std::string &date, double &ammount);
		bool isValidDate(const std::string &date);
		bool inputValidation(const char *btcInput);
		bool dataValidation(const char *btcRatesDB);
		double findClosestDate(const std::string &date);

	public:
		//! Constructors and destructor
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& copy);
		~BitcoinExchange();

		//! Operator overloading
		BitcoinExchange& operator=(const BitcoinExchange& right);

		//! Member functions
		bool btcXchange(const char *filename, const char* btcRatesDB);

	class InvalidDateException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class InvalidInputException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class InvalidNumberException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class InvalidIntException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class InvalidFileException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class InvalidDatabaseException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

#endif
