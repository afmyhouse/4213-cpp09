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

# define SRED	"\033[1;31m"
# define SGRN	"\033[1;32m"
# define SBLU	"\033[1;34m"
# define SRST	"\033[0m"

# define TESTNUM	2

# define E_MSG(err_msg) 	std::cout << SRED << err_msg << SRST << std::endl
# define E_USE_ARGS_EMPTY(e)	E_MSG("ERROR : How to use > " << e << " [file]")
# define E_USE_ARGS_NONUM		E_MSG("ERROR : test number > use a NUMBER!!!")
# define E_USE_ARGS_LIMITS		E_MSG("ERROR : test number > choose one between 0 and " << TESTNUM)

# define E_DATA_OPEN(e)			E_MSG("ERROR: file database : couldn't open file '" << e << "'")
# define E_DATA_FORMAT(e)		E_MSG("ERROR: file database : bad database formating => '" << e << "'")
# define E_DATA_HEADER(e)		E_MSG("ERROR: file database : bad header => '" << e << "'")
# define E_INPUT_OPEN(e)		E_MSG("ERROR: file input : couldn't open file '" << e << "'")
# define E_INPUT_FORMAT(e)		E_MSG("ERROR: file input : bad input formating => '" << e << "'")
# define E_INPUT_NAME(e)		E_MSG("ERROR: file input : bad name => '" << e << "'. Use : <filename.txt>")
# define E_INPUT_EXT(e)			E_MSG("ERROR: file input : bad name => '" << e << "'. Use : <filename.txt>")

# define E_DATE_INVALID(e)		E_MSG("ERROR: file input : invalid date value => '" << e << "'")
# define E_NUM_LIMITS(e)		E_MSG("ERROR: file input : amount value out of range [0, 1000] => '" << e << "'")
# define E_NUM_POSITIV(e)		E_MSG("ERROR: file input : amount value is negative => '" << e << "'")



#endif