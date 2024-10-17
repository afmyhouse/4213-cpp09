#include "../includes/urlHistoryHandler.hpp"
#include <iostream>
#include <sstream>
#include <deque>
#include <algorithm>
#include <exception>
#include <cstdlib>

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

# define E_MSG(x) 	std::cout << x << std::endl
# define E_USE(e)	E_MSG("How to use: " << e << " test_number (0 .. " << TESTNUM << ")")
# define E_NO_INT	E_MSG("Error: test number > use a NUMBER!!!")
# define E_LIMITS	E_MSG("Error: test number > choose one between 0 and " << TESTNUM)

void showCommands(void)
{
	// Command-Line Interface list of commands
	std::cout << "Welcome to the URL History Handler!" << std::endl;
	std::cout << "Available commands:\n";
	std::cout << "<visit <url>> - vist http:://example.com , adds http:example.com to the history\n";
	std::cout << "<back>		- navigates backtime the history\n";
	std::cout << "<forward>	- navigates the history forward in time, stops at last visited site.\n";
	std::cout << "<remove <url>>	- remove last history displayed entry\n";
	std::cout << "<history>	- display all history\n";
	std::cout << "<clear>		- clear all history\n";
	std::cout << "<sort>		- sort history by url\n";
	std::cout << "<exit>		- exit the url history application\n" << std::endl;
	std::cout << "Please enter a command: ";

}

int main()
{
	//CLI
	std::string command;
	std::string url;
	urlHistoryHandler history;
	std::string input;
	showCommands();
	while (1)
	{
		std::getline(std::cin, input);
		std::istringstream iss(input);
		iss >> command;
		if (command == "visit")
		{
			iss >> url;
			if (url.empty())
			{
				std::cout << "Invalid URL. Please try again." << std::endl;
				continue ;
			}
			history.addUrl(url);
		}
		else if (command == "back")
		{
			try
			{
				history.navigateBack();
				history.showCurrent();
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		else if (command == "forward")
		{
			try
			{
				history.navigateForward();
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		else if (command == "remove")
		{
			iss >> url;
			history.removeUrl(url);
		}
		else if (command == "history")
		{
			history.printHistory();
		}
		else if (command == "clear")
		{
			history.clearHistory();
		}
		else if (command == "sort")
		{
			history.sortHistory();
		}
		else if (command == "exit")
		{
			std::cout << "Exiting the URL History Handler..." << std::endl;
			break ;
		}
		else if (command == "help")
		{
			showCommands();
		}
		else
		{
			std::cout << "Invalid command. Please try again." << std::endl;
		}

	}

}
