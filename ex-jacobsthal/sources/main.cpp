#include <iostream>
#include <vector>

// Function to generate Jacobsthal numbers up to a given limit
std::vector<int> generateJacobsthalNumbers(int max) {
	std::vector<int> jacobsthal;
	int j0 = 0, j1 = 1;
	jacobsthal.push_back(j0);
	jacobsthal.push_back(j1);

	while (true) {
		int j_next = j1 + 2 * j0; // Jacobsthal recurrence relation
		if (j_next > max) break;
		jacobsthal.push_back(j_next);
		j0 = j1;
		j1 = j_next;
	}

	return jacobsthal;
}

// Function to insert an element into the sorted list using the Jacobsthal sequence
void jacobsthalInsert(std::vector<int>& sortedList, int element) {
	std::vector<int> jacobsthal = generateJacobsthalNumbers(static_cast<int>(sortedList.size() - 1));
	int left = 0;
	int right = static_cast<int>(sortedList.size() - 1);

	// Using Jacobsthal numbers to guide the comparisons
	for (size_t i = 0; i < jacobsthal.size(); ++i) {
		int pos = (left + jacobsthal[i] < right) ? left + jacobsthal[i] : right; // Prevent out-of-range errors

		if (sortedList[pos] == element) {
			// Element already exists, no need to insert
			std::cout << "Element " << element << " already in the list.\n";
			return;
		} else if (sortedList[pos] < element) {
			left = pos + 1; // Move to the right half
		} else {
			right = pos - 1; // Move to the left half
		}
	}

	// Insert the element at the found position
	sortedList.insert(sortedList.begin() + left, element);
}

int main() {
	std::vector<int> sortedList;
	sortedList.push_back(1);
	sortedList.push_back(2);
	sortedList.push_back(3);
	sortedList.push_back(4);
	sortedList.push_back(6);
	sortedList.push_back(7);
	sortedList.push_back(8);
	sortedList.push_back(9);

	int elementToInsert = 5;

	std::cout << "Original List: ";
	for (size_t i = 0; i < sortedList.size(); ++i) {
		std::cout << sortedList[i] << " ";
	}
	std::cout << "\n";

	jacobsthalInsert(sortedList, elementToInsert);

	std::cout << "List after insertion: ";
	for (size_t i = 0; i < sortedList.size(); ++i) {
		std::cout << sortedList[i] << " ";
	}
	std::cout << "\n";

	return 0;
}
