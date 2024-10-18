#include "../includes/BitcoinExchange.hpp"
#include "../includes/tests.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) {
	*this = copy;
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& right)
{
	if (this == &right)
		return (*this);
	this->_database = right._database;
	return (*this);
}

bool BitcoinExchange::inputValidation(const char *btcInput)
{
	std::string		fileName(btcInput);
	std::string		extension;

	if (fileName.size() < 5)
		return (E_INPUT_NAME(btcInput), false);
	extension = fileName.substr(fileName.size() - 4, 4);
	if (extension != ".csv")
		return (E_INPUT_EXT(btcInput), false);
	return (true);
}

bool BitcoinExchange::btcXchange(const char *btcInput, const char* btcRatesDB)
{
	std::ifstream	inputFile;
	std::string		line, date;
	double			ammount, worth;

	if (!this->readExchangeRates(btcRatesDB))
		return (false);

	if (!this->inputValidation(btcInput))
		return (false);



	while (!inputFile.eof())
	{
		std::getline(inputFile, line);
		if (line == "" || !extract(line, date, ammount))
			continue;
		if (_database.find(date) == _database.end())
			worth = findClosestDate(date);
		else
			worth = _database[date];
		std::cout << date << " => " << ammount << " = " << ammount * worth << std::endl;
	}
	inputFile.close();
	return (true);
}

bool BitcoinExchange::readExchangeRates(const char *btcRatesDB)
{
	std::ifstream		xchRates;
	std::string			key, value;

	xchRates.open(btcRatesDB, std::ios::in);


	if (xchRates.fail())
		return (E_OPEN_FILE(btcRatesDB), false);

	std::getline(xchRates, key, ','); // drop header : date,exchange_rate
	std::getline(xchRates, value);
	if (key != "date" || value != "exchange_rate")
		return (E_OPEN_FILE(btcRatesDB), false);
	while (1)
	{
		std::getline(xchRates, key, ',');
		std::getline(xchRates, value);
		if (xchRates.eof())
			break;
		this->_database[key] = std::atof(value.c_str());
	}
	xchRates.close();
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

	if (date < _database.begin()->first)
		return (0);
	if (date > _database.rbegin()->first)
		return (_database.rbegin()->second);

	previous = _database.begin();
	current = _database.begin();
	current++;



	while (current != _database.end())
	{
		if (current->first > date)
			return (previous->second);
		previous = current;
		++current;
	}
	return (0);
}

const char* BitcoinExchange::InvalidDateException::what() const throw()
{
	return ("ERROR: weird date => '");
}

const char* BitcoinExchange::InvalidInputException::what() const throw()
{
	return ("ERROR: bad input => '");
}

const char* BitcoinExchange::InvalidNumberException::what() const throw()
{
	return ("ERROR: value not between [0, 1000] => '");
}

const char* BitcoinExchange::InvalidIntException::what() const throw()
{
	return ("ERROR: value not between [0, 1000] => '");
}

const char* BitcoinExchange::InvalidFileException::what() const throw()
{
	return ("ERROR: couldn't open '");
}

const char* BitcoinExchange::InvalidDatabaseException::what() const throw()
{
	return ("ERROR: invalid database");
}
