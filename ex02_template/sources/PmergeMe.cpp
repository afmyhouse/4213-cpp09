#include "../includes/PmergeMe.hpp"


PmergeMe::PmergeMe() : type("none") {}

PmergeMe::PmergeMe(const PmergeMe& copy) : type(copy.type) {*this = copy;}

PmergeMe::~PmergeMe() {}


PmergeMe& PmergeMe::operator=(const PmergeMe& src) {
	if (this != &src)
		this->_elapsedTime = src._elapsedTime;
	return (*this);
}

template <typename Container>
void PmergeMe::createPairs(const Container &nums, Container &pairs) {
	size_t numPairs = nums.size() / 2;
	bool hasOddElement = nums.size() % 2 != 0;

	pairs.resize(numPairs + hasOddElement);

	for (size_t i = 0; i < numPairs; ++i) {
		pairs[i].first = std::min(nums[2 * i], nums[2 * i + 1]);
		pairs[i].second = std::max(nums[2 * i], nums[2 * i + 1]);
	}

	if (hasOddElement) {
		pairs[numPairs].first = UNUSED;
		pairs[numPairs].second = nums.back();
	}
}

template <typename Container>
void PmergeMe::merge(Container &left, Container &right, Container &result) {
	result.clear();
	while (!left.empty() && !right.empty())
	{
		if (left[0][A] < right[0][A] || right[0][A] == UNUSED)
		{
			result.push_back(left.front());
			left.erase(left.begin());
		}
		else
		{
			result.push_back(right.front());
			right.erase(right.begin());
		}
	}
	while (!left.empty())
	{
		result.push_back(left.front());
		left.erase(left.begin());
	}
	while (!right.empty())
	{
		result.push_back(right.front());
		right.erase(right.begin());
	}
}

template <typename Container>
void PmergeMe::mergeSort(Container &pairs) {
	typename Container::iterator mid = pairs.begin() + pairs.size() / 2;

	Container left(pairs.begin(), mid);
	Container right(mid, pairs.end());

	if (pairs.size() == 1)
		return ;

	mergeSort(left);
	mergeSort(right);
	merge(left, right, pairs);
}


template <typename Container>
void PmergeMe::generateJacobsthalNumbers(Container &jacobsthal, int max) {
	int j0 = 0, j1 = 1;
	jacobsthal.push_back(j0);
	jacobsthal.push_back(j1);

	while (true) {
		int j_next = j1 + 2 * j0;
		if (j_next > max) break;
		jacobsthal.push_back(j_next);
		j0 = j1;
		j1 = j_next;
	}
}

template <typename Container>
void jacobsthalInsert(Container& S, int element) {
	int left = 0;
	int right = static_cast<int>(S.size() - 1);

	for (size_t i = 0; i < S.size(); ++i) {
		if (S[left] == element || S[right] == element)
			return;
		if (S[right] < element)
			S.insert(S.begin() + right + 1, element);
		else if (S[left] > element)
			S.insert(S.begin(), element);
		else
			S.insert(S.begin() + left, element);
	}
}

template <typename Container>
void PmergeMe::insertionSort(Container &S, size_t n, const Container &pairs) {
	Container jacobsthal;
	generateJacobsthalNumbers(jacobsthal, static_cast<int>(S.size() - 1));

	for (size_t i = 0; i < jacobsthal.size(); i++)
	{
		for (size_t k = jacobsthal[i]; k > jacobsthal[i - 1]; k--)
		{
			if (k >= pairs.size())
				continue;
			jacobsthalInsert(S, pairs[k][B]);
			if (S.size() == n)
				return;
		}
	}
}

template <typename Container>
double PmergeMe::mergeInsertionSort(Container &nums) {
	Container pairs;
	Container S;

	gettimeofday(&_start, NULL); // Capture start time

	createPairs(nums, pairs);
	mergeSort(pairs);

	for (size_t i = 0; i < pairs.size(); ++i)
	{
		if (pairs[i][A] != UNUSED)
			S.push_back(pairs[i][A]);
	}
	insertionSort(S, nums.size(), pairs);
	nums = S;

	gettimeofday(&_end, NULL); // Capture end time
	return (_end.tv_sec - _start.tv_sec) * 1000000.0 + (_end.tv_usec - _start.tv_usec);
}
