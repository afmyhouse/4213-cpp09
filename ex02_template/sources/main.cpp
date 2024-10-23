#include "../includes/PmergeMe.hpp"


// check this functions

bool isInteger(const std::string& str) {
	if (str.empty()) {
		return false; // An empty string is not an integer
	}

	std::string::const_iterator it = str.begin();

	// Check for a leading sign (optional)
	if (*it == '-' || *it == '+') {
		++it;
	}

	// Ensure the rest of the characters are digits
	while (it != str.end() && std::isdigit(*it)) {
		++it;
	}

	return it == str.end(); // Return true if we reached the end of the string
}

std::string joinStrings(int argc, char **argv) {
	std::string result;
	for (int i = 1; i < argc; ++i) { // Start from 1 to skip the program name (argv[0])
		std::string currentString = argv[i];

		if (!isInteger(currentString)) {
			std::cerr << "Error: The string \"" << currentString << "\" is not a valid integer." << std::endl;
			return ""; // Return an empty string if any string is not an integer
		}

		result += currentString;
		if (i < argc - 1) {
			result += " "; // Add a space if it's not the last element
		}
	}
	return result;
}

template <typename Container>
bool parser(const std::string dataSet, Container &vec)
{
	int					number;
	std::stringstream	stream;

	total = std::string(argv[0]);
	stream << dataSet;
	while (!stream.eof())
	{
		if (!(stream >> number))
			return (false);
		if (number < 0)
			return (false);
		if (std::find(Container.begin(), Containervec.end(), number) != Container.end())
			return (false);
		Container.push_back(number);
	}
	return (true);
}

template <class T>
void print(T &container)
{
	typename T::iterator it;

	for (it = container.begin(); it != container.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	std::vector<int> vec;
	std::deque<int> deque;

	if (argc < 2)
		return (-1);
	std::string joinedString = joinStrings(argc, argv + 1);
	if (joinedString.empty()) {
		return (1);
	} else {
		std::cout << joinedString << std::endl;
	}

	if (!parser(joinedString, vec) || !parser(joinedString, deque))
		return (std::cout << "Error\n", 1);
	std::cout << "Before: ";
	print(vec);

	PmergeMe sorter;

	double vecTime = sorter.mergeInsertionSort(vec);
	double dequeTime = sorter.mergeInsertionSort(deque);

	std::cout << "After: ";
	print(vec);

	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " \
		<< vecTime << " s /" \
		<< vecTime * 1000 << " ms /" \
		<< vecTime * 1000 * 1000 << " µs \n";
	std::cout << "Time to process a range of " << deque.size() << " elements with std::deque : " \
		<< dequeTime << " s /" \
		<< dequeTime * 1000 << " ms /" \
		<< dequeTime * 1000 * 1000 << " µs \n";

	return (0);
}