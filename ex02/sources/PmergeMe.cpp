#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe() : _elapsedTime(0) {}

PmergeMe::PmergeMe(const PmergeMe& copy) : _start(copy._start), _end(copy._end), _elapsedTime(copy._elapsedTime) {}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& src) {
	if (this != &src) {
		_elapsedTime = src._elapsedTime;
	}
	return *this;
}

// Template instantiation
template double PmergeMe::mergeInsertionSort<std::vector<int> >(std::vector<int>&);
template double PmergeMe::mergeInsertionSort<std::deque<int> >(std::deque<int>&);

template <typename Container>
double PmergeMe::mergeInsertionSort(Container& nums) {
	typename PairContainerType<Container>::type pairs;
	Container S;

	gettimeofday(&_start, NULL);

	createPairs(nums, pairs);

	mergeSort(pairs);

	for (size_t i = 0; i < pairs.size(); ++i) {
		if (i == 0 && pairs[i].first != ODDSET)
			S.push_back(pairs[i].first);
		S.push_back(pairs[i].second);
	}

	insertionSort(S, nums.size(), pairs);
	nums = S;

	gettimeofday(&_end, NULL);
	_elapsedTime = (_end.tv_sec - _start.tv_sec) * 1000000.0 + (_end.tv_usec - _start.tv_usec);
	return (_elapsedTime);
}

template <class Container, class PairContainer>
void PmergeMe::createPairs(const Container& nums, PairContainer& pairs) {
	size_t numPairs = nums.size() / 2;
	bool oddElement = nums.size() % 2 != 0;

	pairs.resize(numPairs + oddElement);

	for (size_t i = 0; i < numPairs; ++i) {
		pairs[i].first = std::min(nums[2 * i], nums[2 * i + 1]);
		pairs[i].second = std::max(nums[2 * i], nums[2 * i + 1]);
	}
	if (oddElement) {
		pairs[numPairs].first = ODDSET;
		pairs[numPairs].second = nums.back();
	}
}

template <typename Container>
void PmergeMe::merge(Container& left, Container& right, Container& result) {
	result.clear();

	while (!left.empty() && !right.empty()) {
		if (left.front().second < right.front().second) {
			result.push_back(left.front());
			left.erase(left.begin());
		} else {
			result.push_back(right.front());
			right.erase(right.begin());
		}
	}
	while (!left.empty()) {
		result.push_back(left.front());
		left.erase(left.begin());
	}
	while (!right.empty()) {
		result.push_back(right.front());
		right.erase(right.begin());
	}
}

template <typename PairContainer>
void PmergeMe::mergeSort(PairContainer& pairs) {
	typename PairContainer::iterator mid = pairs.begin() + pairs.size() / 2;

	PairContainer left(pairs.begin(), mid);
	PairContainer right(mid, pairs.end());

	if (pairs.size() == 1)
		return;

	mergeSort(left);
	mergeSort(right);
	merge(left, right, pairs);
}

template <typename Container>
void PmergeMe::generateJacobsthalNumbers(Container& jacobsthal, int max) {
	int j0 = 1, j1 = 1;

	jacobsthal.clear();
	jacobsthal.push_back(j1);
	while (true) {
		int j_next = j1 + 2 * j0;
		jacobsthal.push_back(j_next);
		if (j_next > max) break;
		j0 = j1;
		j1 = j_next;
	}
}

template <typename Container>
void PmergeMe::jacobsthalInsert(Container& S, int element, size_t k) {
	if (std::find(S.begin(), S.end(), element) != S.end()) return; // Avoid duplicates

	int left = 0;
	// int right = static_cast<int>(S.size()) - 1;
	int right = static_cast<int>(k);
	// static int compares = 0;
	(void) k;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (S[mid] < element)
			left = mid + 1;
		else if (S[mid] > element)
			right = mid - 1;
		//compares++;
	}
	S.insert(S.begin() + left, element);
	// std::cout << "Compares : " << compares << std::endl;
}

template <class Container, class PairContainer>
void PmergeMe::insertionSort(Container &S, size_t n, const PairContainer &pairs) {
	Container jacobsthal;
	size_t original_size = S.size();

	if (pairs.size() > 1 && pairs[1].first != ODDSET)
		jacobsthalInsert(S, pairs[1].first, 1);
	size_t jacobsthalLimit = S.empty() ? 0 : static_cast<int>(S.size() - 1);
	generateJacobsthalNumbers(jacobsthal, jacobsthalLimit);
	for (size_t i = 1; i < jacobsthal.size(); i++) {

		for (size_t k = jacobsthal[i]; k > static_cast<size_t>(jacobsthal[i - 1]); k--) {
			if (k >= pairs.size())
				continue;
			if (pairs[k].first != ODDSET)
				jacobsthalInsert(S, pairs[k].first, k + S.size() - original_size);
			if (S.size() == n)
				return;
		}
	}
}

