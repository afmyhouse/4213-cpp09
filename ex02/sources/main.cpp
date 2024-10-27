#include "../includes/PmergeMe.hpp"
#include <iomanip>

bool isInteger(const std::string& str) {
	if (str.empty()) {
		return false;
	}

	std::string::const_iterator it = str.begin();

	if (*it == '-' || *it == '+') {
		++it;
	}

	while (it != str.end() && (std::isdigit(*it) || std::isspace(*it) || *it == '-' || *it == '+')) {
		++it;
	}

	return it == str.end();
}

std::string joinStrings(int argc, char **argv) {
	std::string result;
	for (int i = 1; i < argc; ++i) {
		std::string currentString = argv[i];

		if (!isInteger(currentString)) {
			std::cerr << "Error: The string \"" << currentString << "\" is not a valid integer." << std::endl;
			return "";
		}

		result += currentString;
		if (i < argc - 1) {
			result += " ";
		}
	}
	return result;
}

template <typename Container>
bool parser(const std::string dataSet, Container &theContainer)
{
	int number;
	std::stringstream stream;

	stream << dataSet;

	while (stream >> number) {
		if (number < 0) {
			std::cerr << "Error: Negative number encountered: " << number << std::endl;
			return false;
		}
		if (std::find(theContainer.begin(), theContainer.end(), number) != theContainer.end()) {
			std::cerr << "Error: Duplicate number encountered: " << number << std::endl;
			return false;
		}
		theContainer.push_back(number);
	}
	if (!stream.eof() && !stream.good()) {
		std::cerr << "Error: Invalid input detected in dataset: \"" << dataSet << "\"" << std::endl;
		return false;
	}
	return true;
}

template <typename Container>
void print(Container &container)
{
	typename Container::iterator it;

	for (it = container.begin(); it != container.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	std::vector<int> vec;
	std::deque<int> deq;
	double vecTime, deqTime;
	struct timeval start, end;

	if (argc < 2)
		return (EXIT_FAILURE);
	std::string joinedString = joinStrings(argc, argv);
	if (joinedString.empty())
		return (EXIT_FAILURE);
	gettimeofday(&start, NULL);
	if (!parser(joinedString, vec))
		return (EXIT_FAILURE);
	gettimeofday(&end, NULL);
	vecTime = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
	gettimeofday(&start, NULL);
	if (!parser(joinedString, deq))
		return (EXIT_FAILURE);
	gettimeofday(&end, NULL);
	deqTime = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);

	std::cout << "Before: ";
	print(vec);

	PmergeMe sorter;

	vecTime += sorter.mergeInsertionSort(vec);
	deqTime += sorter.mergeInsertionSort(deq);

	std::cout << "After : ";
	print(vec);

	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " \
		<< std::right << std::setw(7) << std::fixed << std::setprecision(3) \
		<< vecTime / 1000000.0 << " s | " \
		<< std::right << std::setw(7) \
		<< vecTime / 1000.0 << " ms | " \
		<< std::right << std::setw(7) << std::fixed << std::setprecision(0) \
		<< vecTime << " µs \n";

	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque  : " \
		<< std::right << std::setw(7) << std::fixed << std::setprecision(3) \
		<< deqTime / 1000000.0 << " s | " \
		<< std::right << std::setw(7) \
		<< deqTime / 1000.0 << " ms | " \
		<< std::right << std::setw(7) << std::fixed << std::setprecision(0) \
		<< deqTime << " µs \n";

	return (EXIT_SUCCESS);
}