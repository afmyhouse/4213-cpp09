#include <iostream>
#include <string>
#include <cctype> // For isdigit()

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


int main(int argc, char **argv) {
	std::string joinedString = joinStrings(argc, argv);
	if (!joinedString.empty()) {
		std::cout << joinedString << std::endl;
	}
	return 0;
}
