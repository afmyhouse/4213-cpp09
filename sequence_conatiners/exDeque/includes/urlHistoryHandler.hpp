#ifndef URL_HISTORY_HANDLER_HPP
# define URL_HISTORY_HANDLER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <deque>
# include <algorithm>
# include <exception>

class urlHistoryHandler
{
	private:
		std::deque<std::string> _history;
		std::deque<std::string> _forwardHistory;
	public:
		// Constructors & Destructors
		urlHistoryHandler();
		~urlHistoryHandler();
		urlHistoryHandler(std::string& what);
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
		void showCurrent(void);

	class urlHistoryEmptyException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class urlHistoryBackException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class urlHistoryForwardException : public std::exception
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
#endif
