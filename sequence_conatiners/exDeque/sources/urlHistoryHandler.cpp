#include "urlHistoryHandler.hpp"

urlHistoryHandler :: urlHistoryHandler() {}

urlHistoryHandler :: urlHistoryHandler(const urlHistoryHandler& srcClass) {
	*this = srcClass;
}

urlHistoryHandler :: ~urlHistoryHandler() {}

urlHistoryHandler& urlHistoryHandler :: operator=(const urlHistoryHandler& srcClass) {
	if (this != &srcClass)
		this->_history = srcClass._history;
	return (*this);
}

void urlHistoryHandler :: addUrl(std::string& urlAddress) {
	this->_forwardHistory.clear();
	this->_history.push_back(urlAddress);
	std::cout << urlAddress << " added to history" << std::endl;
}

void urlHistoryHandler :: removeUrl(std::string& urlAddress) {
	std::deque<std::string>::iterator it = std::find(this->_history.begin(), this->_history.end(), urlAddress);
	if (it != this->_history.end())
		this->_history.erase(it);
}

void urlHistoryHandler :: removeUrl(size_t index) {
	if (index >= this->_history.size())
		throw urlHistoryIndexException();
	if (this->_history.size() == 0)
		throw urlHistoryEmptyException();
	if (index == 0)
		this->_history.pop_front();
	else if (index == this->_history.size() - 1)
		this->_history.pop_back();
	else {
		std::deque<std::string>::iterator it = this->_history.begin();
		std::advance(it, index);
		this->_history.erase(it);
	}
}

void urlHistoryHandler :: navigateBack(void) {
	if (this->_history.size() < 2)
		throw urlHistoryBackException();
	else {
		this->_forwardHistory.push_back(this->_history.back());
		this->_history.pop_back();
		std::cout << "Navigating back to " << this->_history.back() << std::endl;
	}
}

void urlHistoryHandler :: navigateForward(void) {
	if (this->_forwardHistory.size() == 0)
		throw urlHistoryForwardException();
	else {
		this->_history.push_back(this->_forwardHistory.back());
		this->_forwardHistory.pop_back();
		std::cout << "Navigating forward to " << this->_history.back() << std::endl;
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
	this->_history.clear();
	this->_forwardHistory.clear();
	std::cout << "History cleared" << std::endl;
}

void urlHistoryHandler :: sortHistory(void) {
	std::sort(this->_history.begin(), this->_history.end());
	std::cout << "History sorted :" << std::endl;
	for (size_t i = 0; i < this->_history.size(); i++)
		std::cout << this->_history[i] << std::endl;
}

void urlHistoryHandler :: copyHistory(const std::deque<std::string>& history) {
	if (this->_history.size() == 0)
		throw urlHistoryEmptyException();
	std::deque<std::string>::const_iterator it = history.begin();
	while (it != history.end()) {
		this->_history.push_back(*it);
		it++;
	}
	std::cout << "History copied" << std::endl;
}

void urlHistoryHandler :: showCurrent(void) {
	if (this->_history.size() == 0)
		throw urlHistoryEmptyException();
	std::cout << "Current url : " << this->_history.back() << std::endl;
}

const char* urlHistoryHandler::urlHistoryEmptyException :: what() const throw() {
	return ("\nurlHistory Exception: list is empty\n");
}

const char* urlHistoryHandler::urlHistoryBackException :: what() const throw() {
	return ("\nurlHistory Exception: list hasn't enough url to navigate back\n");
}

const char* urlHistoryHandler::urlHistoryForwardException :: what() const throw() {
	return ("\nurlHistory Exception: list hasn't enough url to navigate forward\n");
}

const char* urlHistoryHandler::urlHistoryIndexException :: what() const throw() {
	return ("\nurlHistory Exception: index out of range\n");
}
