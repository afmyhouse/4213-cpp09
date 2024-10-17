/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:20:55 by crypto            #+#    #+#             */
/*   Updated: 2023/09/23 19:52:29 by ncarvalh         ###   ########.fr       */
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
		std::map<std::string, float> database;

	public:
		//! Constructors and destructor
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& copy);
		~BitcoinExchange();

		//! Operator overloading
		BitcoinExchange& operator=(const BitcoinExchange& right);

		//! Member functions
		bool convert(const char *filename);
	
	private:
		bool readExchangeRates(void);
		bool extract(const std::string &line, std::string &date, double &ammount);
		bool isValidDate(const std::string &date);
		double findClosestDate(const std::string &date);
};

#endif
