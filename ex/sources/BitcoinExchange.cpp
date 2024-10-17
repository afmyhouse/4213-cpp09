#include "BitcoinExchange.hpp"

//! ________________________ CONSTRUCTORS ________________________

BitcoinExchange::BitcoinExchange()
{
	
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
	*this = copy;
}

BitcoinExchange::~BitcoinExchange()
{
	
}

//! ____________________ OPERATOR OVERLOADING ____________________

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& right)
{
	if (this == &right)
		return (*this);
	this->database = right.database;
	return (*this);
}

//! _____________________ MEMBER FUNCTIONS _______________________

bool BitcoinExchange::convert(const char *filename)
{
	std::ifstream	infile;
	std::string		line, date;
	double			ammount, worth;

	if (!this->readExchangeRates())
		return (false);

	infile.open(filename, std::ios::in);
	if (infile.fail())
		return (false);

	std::getline(infile, date);
	while (!infile.eof())
	{
		std::getline(infile, line);
		if (line == "" || !extract(line, date, ammount))
			continue;
		if (database.find(date) == database.end())
			worth = findClosestDate(date);
		else
			worth = database[date];
		std::cout << date << " => " << ammount << " = " << ammount * worth << std::endl;
	}
	infile.close();
	return (true);
}

bool BitcoinExchange::readExchangeRates(void)
{
	std::ifstream		infile;
	std::string			key, value;

	infile.open("data.csv", std::ios::in);
	if (infile.fail())
		return (ERROR_BAD_FILE("data.csv"), false);

	std::getline(infile, key);
	while (1)
	{
		std::getline(infile, key, ',');
		std::getline(infile, value);
		if (infile.eof())
			break;
		database[key] = std::atof(value.c_str());
	}
	infile.close();
	return (true);
}

bool BitcoinExchange::extract(const std::string &line, std::string &date, double &ammount)
{
	std::istringstream	stream(line);
	char				delimiter;

	if (!(stream >> date >> delimiter >> ammount))
		return (ERROR_BAD_INPUT(line), false);
	if (!isValidDate(date))
		return (ERROR_BAD_DATE(line), false);
	if (ammount < 0)
		return (ERROR_BAD_NUM(line), false);
	if (ammount > 1000)
		return (ERROR_NOT_INT(line), false);
	return (true);
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
	char 				hifen;
	std::stringstream	stream(date);
	struct tm 			old = {}, normalized = {};

	if (date.size() != 10)
		return (false);

	if (!(stream >> old.tm_year >> hifen >> old.tm_mon >> hifen >> old.tm_mday))
		return (false);

	old.tm_mon -= 1;
	old.tm_year -= 1900;
	normalized = old;
	mktime(&normalized);

	return (normalized.tm_year == old.tm_year \
			&& normalized.tm_mon == old.tm_mon \
			&& normalized.tm_mday == old.tm_mday);
}

double BitcoinExchange::findClosestDate(const std::string &date)
{
	std::map<std::string, float>::iterator current;
	std::map<std::string, float>::iterator previous;

	if (date < database.begin()->first)
		return (0);
	if (date > database.rbegin()->first)
		return (database.rbegin()->second);

	previous = database.begin();
	current = database.begin();
	current++;
	while (current != database.end())
	{
		if (current->first > date)
			return (previous->second);
		previous = current;
		++current;
	}
	return (0);	
}
