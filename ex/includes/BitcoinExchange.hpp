/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:20:55 by crypto            #+#    #+#             */
/*   Updated: 2024/10/17 15:50:02 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define RESET	"\033[0m"

# define ERROR(str)			std::cout << RED << str << RESET "\n"
# define ERROR_BAD_FILE(x)	ERROR("ERROR: couldn't open '" << x << "'")
# define ERROR_BAD_INPUT(x)	ERROR("ERROR: bad input => '" << x << "'")
# define ERROR_BAD_DATE(x)	ERROR("ERROR: weird date => '" << x << "'")
# define ERROR_NOT_INT(x)	ERROR("ERROR: value not between [0, 1000] => '" << x << "'")
# define ERROR_BAD_NUM(x)	ERROR("ERROR: not a positive number => '" << x << "'")
# define ERROR_USAGE		ERROR("ERROR: ./BitcoinExchange filename")

class BitcoinExchange
{
	private:
		std::map<std::string, float> _database;

	public:
		//! Constructors and destructor
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& copy);
		~BitcoinExchange();

		//! Operator overloading
		BitcoinExchange& operator=(const BitcoinExchange& right);

		//! Member functions
		bool btcXchange(const char *filename, const char* btcRatesDB);

	private:
		bool readExchangeRates(const char* database);
		bool extract(const std::string &line, std::string &date, double &ammount);
		bool isValidDate(const std::string &date);
		double findClosestDate(const std::string &date);

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
