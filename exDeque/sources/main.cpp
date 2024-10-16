#include <iostream>
#include <sstream>
#include <deque>
#include <algorithm>
#include <exception>

class urlHistoryHandler
{
	private:
		std::deque<std::string> _history;
	public:
		// Constructors & Destructors
		urlHistoryHandler();
		~urlHistoryHandler();
		urlHistoryHandler(const urlHistoryHandler &srcClass);
		// Operators overloading
		urlHistoryHandler& operator=(const urlHistoryHandler &srcClass);

		// Member functions
		void addUrl(std::string& urlAddress);
		void removeUrl(std::string& urlAddress);
		void removeUrl(size_t index);
		void navigateBack(void);
		void navigateForward(void);
		void printHistory(void);
		void clearHistory(void);
		void sortHistory(void);
		void copyHistory(const std::deque<std::string>& history);
		void showCurrent(void) const;

	class urlHistoryEmptyException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class urlHistoryIndexException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

urlHistoryHandler :: urlHistoryHandler() {}

urlHistoryHandler :: urlHistoryHandler(const urlHistoryHandler& srcClass) {
	*this = srcClass;
}

urlHistoryHandler :: ~urlHistoryHandler() {}

urlHistoryHandler& urlHistoryHandler :: operator=(const urlHistoryHandler& srcClass) {
	if (this != &srcClass) {
		this->_history = srcClass._history;
	}
	return *this;
}

void urlHistoryHandler :: addUrl(std::string& urlAddress) {
	this->_history.push_front(urlAddress);
	std::cout << "Added <" << urlAddress << "> to history" << std::endl;
}

void urlHistoryHandler :: removeUrl(std::string& urlAddress) {
	if (this->_history.size() == 0)
		throw urlHistoryEmptyException();
	std::deque<std::string>::iterator it = std::find(this->_history.begin(), this->_history.end(), urlAddress);
	if (it != this->_history.end()) {
		std::cout << "Removed " << *it << " from history" << std::endl;
		this->_history.erase(it);
	}
	else
		std::cout << urlAddress << " : URL not found in history" << std::endl;

}

void urlHistoryHandler :: removeUrl(size_t index) {
	if (index >= this->_history.size())
		throw urlHistoryIndexException();
	std::deque<std::string>::iterator it = this->_history.begin();
	std::advance(it, index);
	if (it != this->_history.end()) {
		std::cout << "Removed " << *it << " from history" << std::endl;
		this->_history.erase(it);
	}
	else
		std::cout << index << " : Index URL not found in history" << std::endl;
}

void urlHistoryHandler :: navigateForward(void) {
	if (this->_history.size() == 0)
		throw urlHistoryEmptyException();
	else if (this->_history.size() > 0) {
		std::cout << "Navigating back to " << this->_history.front() << std::endl;
		this->_history.push_back(this->_history.front());
		this->_history.pop_front();
	}
}

void urlHistoryHandler :: navigateBack(void) {
	if (this->_history.size() == 0)
		throw urlHistoryEmptyException();
	else if (this->_history.size() > 0) {
		std::cout << "Navigating forward to " << this->_history.back() << std::endl;
		this->_history.push_front(this->_history.back());
		this->_history.pop_back();
	}
}

void urlHistoryHandler :: printHistory(void) {
	if (this->_history.size() == 0)
		throw urlHistoryEmptyException();
	std::deque<std::string>::iterator it = this->_history.begin();
	while (it != this->_history.end()) {
		std::cout << *it << std::endl;
		it++;
	}
}

void urlHistoryHandler :: clearHistory(void) {
	if (this->_history.size() == 0)
		throw urlHistoryEmptyException();
	this->_history.clear();
}

void urlHistoryHandler :: sortHistory(void) {
	if (this->_history.size() == 0)
		throw urlHistoryEmptyException();
	std::sort(this->_history.begin(), this->_history.end());
}

void urlHistoryHandler :: copyHistory(const std::deque<std::string>& history) {
	if (this->_history.size() == 0)
		throw urlHistoryEmptyException();
	std::deque<std::string>::const_iterator it = history.begin();
	while (it != history.end()) {
		this->_history.push_back(*it);
		it++;
	}
}

void urlHistoryHandler :: showCurrent(void) const {
	if (this->_history.size() == 0)
		throw urlHistoryEmptyException();
	std::cout << "Current URL: " << this->_history.front() << std::endl;
}

const char* urlHistoryHandler::urlHistoryEmptyException :: what() const throw() {
	return ("\nurlHistory Exception: list is empty\n");
}


const char* urlHistoryHandler::urlHistoryIndexException :: what() const throw() {
	return ("\nurlHistory Exception: Index out of bounds\n");
}
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
