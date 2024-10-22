#ifndef TESTS_HPP
# define TESTS_HPP

# include <iostream>
# include <cstdlib>
# include <sstream>

# define MYDEBUG

# ifdef MYDEBUG
#  define SHOW(str) std::cout << str << std::endl;
# else
#  define SHOW(str)
# endif

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
# define E_NUM_LIMITS(e)		E_MSG("ERROR: file input : invalid amount : out of range [0, 1000] => '" << e << "'")
# define E_NUM_NEGATIVE(e)		E_MSG("ERROR: file input : invalid amount : negative => '" << e << "'")

#endif