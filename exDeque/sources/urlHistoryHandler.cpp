#include "urlHistoryHandler.hpp"

urlHistoryHandler :: urlHistoryHandler() {}

urlHistoryHandler :: urlHistoryHandler(const urlHistoryHandler& srcClass) {
	*this = srcClass;
}

urlHistoryHandler :: ~urlHistoryHandler() {}

urlHistoryHandler& urlHistoryHandler :: operator=(const urlHistoryHandler& srcClass) {
	if (this != &srcClass)
		*this = srcClass;
	this->copyHistory(srcClass._history);
	return (*this);
}

void urlHistoryHandler :: addUrl(std::string& urlAddress) {
	this->_history.push_front(urlAddress);
}

void urlHistoryHandler :: removeUrl(std::string& urlAddress) {
	std::deque<std::string>::iterator it = std::find(this->_history.begin(), this->_history.end(), urlAddress);
	if (it != this->_history.end())
		this->_history.erase(it);
}

void urlHistoryHandler :: removeUrl(size_t index) {
	if (index >= this->_history.size())
		return ;
	std::deque<std::string>::iterator it = this->_history.begin();
	std::advance(it, index);
	this->_history.erase(it);
}

void urlHistoryHandler :: navigateBack(void) {
	if (this->_history.size() == 0)
		throw urlHistoryEmptyException();
	else if (this->_history.size() > 0) {
		std::cout << "Navigating back to " << this->_history.front() << std::endl;
		this->_history.push_back(this->_history.front());
		this->_history.pop_front();
	}
}

void urlHistoryHandler :: navigateForward(void) {
	if (this->_history.size() == 0)
		throw std::runtime_error("Aqui tem um erro!!");
		// throw urlHistoryEmptyException();
	else if (this->_history.size() > 0) {
		std::cout << "Navigating forward to " << this->_history.back() << std::endl;
		this->_history.push_front(this->_history.back());
		this->_history.pop_back();
	}
}

void urlHistoryHandler :: printHistory(void) {
	std::deque<std::string>::iterator it = this->_history.begin();
	while (it != this->_history.end()) {
		std::cout << *it << std::endl;
		it++;
	}
}

void urlHistoryHandler :: clearHistory(void) {
	this->_history.clear();
}

void urlHistoryHandler :: sortHistory(void) {
	std::sort(this->_history.begin(), this->_history.end());
}

void urlHistoryHandler :: copyHistory(const std::deque<std::string>& history) {
	std::deque<std::string>::const_iterator it = history.begin();
	while (it != history.end()) {
		this->_history.push_back(*it);
		it++;
	}
}

const char* urlHistoryHandler::urlHistoryEmptyException :: what() const throw() {
	return ("\nurlHistory Exception: list is empty\n");
}

