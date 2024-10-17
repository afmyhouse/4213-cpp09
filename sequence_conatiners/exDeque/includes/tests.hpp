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
# define SGREEN	"\033[1;32m"
# define SBLUE	"\033[1;34m"
# define SRESET	"\033[0m"

# define TESTNUM	4

# define E_MSG(x) 		std::cout << x << std::endl
# define E_USE(e)	E_MSG("How to use: " << e << " test_number (0 .. " << TESTNUM << ")")
# define E_NO_INT	E_MSG("Error: test number > use a NUMBER!!!")
# define E_LIMITS	E_MSG("Error: test number > choose one between 0 and " << TESTNUM)

#endif