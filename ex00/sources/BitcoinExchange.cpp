#include "../includes/BitcoinExchange.hpp"

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

bool BitcoinExchange :: btcXchange(const char *btcInput, const char* btcRatesDB)
{
	this->readExchangeRates(btcRatesDB);
	this->readInputAmount(btcInput);
	return (true);
}

bool BitcoinExchange::readExchangeRates(const char *btcRatesDB)
{
	std::ifstream		xchRates(btcRatesDB);
	std::string			date, header, line;
	double				rate;

	this->fileValidation(btcRatesDB, ".csv", "file database : invalid extension");

	if (!xchRates.is_open())
		throw BitcoinExchangeException("file database : couldn't open file ", btcRatesDB);

	std::getline(xchRates, header);
	if (header != db_header)
		throw BitcoinExchangeException("file database : invalid header formating ", header + " => " + db_header);

	while (std::getline(xchRates, line))
	{
		if (line.empty() || !lineValidation(line, date, rate, _CSV_))
			continue;
		this->_database[date] = rate;
	}
	return (true);
}

bool BitcoinExchange :: readInputAmount(const char *btcInput)
{
	std::ifstream	inputFile(btcInput);
	std::string		line, date, header;
	double			value, rate;

	this->fileValidation(btcInput, ".txt", "file input : invalid filename. Use : <filename>.<ext>");

	if (!inputFile.is_open())
		throw BitcoinExchangeException("file input : couldn't open file ", btcInput);

	std::getline(inputFile, header);
	if (header != in_header)
		throw BitcoinExchangeException("file input : invalid header formating ", header + " => " + in_header);

	while (std::getline(inputFile, line)) {
		if (line.empty() || !lineValidation(line, date, value, _WALLET_))
			continue;
 		rate = getRateAtNearestDate(date);
		// std::cout.unsetf(std::ios::fixed);
		std::cout  << date << " => " << value;
		std::cout << std::fixed << std::setprecision(3);
		std::cout  << " = " << (value * rate) << std::endl;
	}
	return (true);
}

bool BitcoinExchange::fileValidation(const char *filename, const std::string ext, const char* msg)
{
	std::string		fileName(filename);
	std::string		extension;

	if (fileName.size() < 5)
		throw BitcoinExchangeException(msg, filename);
	extension = fileName.substr(fileName.size() - 4, 4);
	if (extension != ext && ext != ".txt")
		throw BitcoinExchangeException(msg, filename);
	return (true);
}

bool BitcoinExchange::lineValidation(const std::string &line, std::string &date, double &rate, char delimiter)
{
	std::istringstream	stream(line);
	char				sep;
	std::string 		srate;

	if ((delimiter == _CSV_ && std::getline(stream, date, delimiter) && std::getline(stream, srate))
		|| (delimiter == _WALLET_ && (stream >> date >> sep >> rate)))
	{
		if( sep != _WALLET_ &&  delimiter == _WALLET_) {
			return (E_INPUT_LINE(line), false);
		} else {
			rate = delimiter == _CSV_ ? std::strtod(srate.c_str(), NULL) : rate;
			if (!dateValidation(date))
				return (E_DATE_INVALID(date), false);
			if (rate < 0)
				return (E_NUM_NEGATIVE(rate), false);
			if (delimiter == _WALLET_ && rate > 1000)
				return (E_NUM_LIMITS(rate), false);
		}
	}
	else
		return (E_INPUT_FORMAT(line), false);

	return (true);
}

bool BitcoinExchange::dateValidation(const std::string &date)
{
	char 				hifen;
	std::stringstream	stream(date);
	struct tm 			iDate = {}, nDate = {};

	if (date.size() != 10)
		return (false);

	if (!(stream >> iDate.tm_year >> hifen >> iDate.tm_mon >> hifen >> iDate.tm_mday))
		return (false);

	iDate.tm_mon -= 1;
	iDate.tm_year -= 1900;
	nDate = iDate;
	mktime(&nDate);

	return (nDate.tm_year == iDate.tm_year && nDate.tm_mon == iDate.tm_mon && nDate.tm_mday == iDate.tm_mday);
}

double BitcoinExchange::getRateAtNearestDate(const std::string &date)
{
	if (date < _database.begin()->first)
		return (0);
	if (date > _database.rbegin()->first)
		return (_database.rbegin()->second);
	std::map<std::string, float>::iterator wanted = _database.upper_bound(date);
	--wanted;
	return ((wanted->second));
}
