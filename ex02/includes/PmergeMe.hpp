#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <sys/time.h>
# include <vector>
# include <deque>
# include <algorithm>

# define ODDSET -1
# define MIN(a, b) ((a) < (b) ? (a) : (b))
# define MAX(a, b) ((a) > (b) ? (a) : (b))

// Trait to deduce the corresponding pair container type
template <typename Container>
struct PairContainerType;

// Specialize for std::vector<int>
template <>
struct PairContainerType<std::vector<int> > {
	typedef std::vector<std::pair<int, int> > type;
};

// Specialize for std::deque<int>
template <>
struct PairContainerType<std::deque<int> > {
	typedef std::deque<std::pair<int, int> > type;
};

class PmergeMe {
private:
	const std::string type;
	struct timeval _start, _end;
	double _elapsedTime;

public:
	PmergeMe();
	PmergeMe(const PmergeMe& copy);
	~PmergeMe();

	PmergeMe& operator=(const PmergeMe& right);

	template <typename Container>
	double mergeInsertionSort(Container& nums);

private:
	template <class Container, class PairContainer>
	void createPairs(const Container& nums, PairContainer& pairs);

	template <typename Container>
	void merge(Container& left, Container& right, Container& result);

	template <typename PairContainer>
	void mergeSort(PairContainer& pairs);

	template <typename Container>
	void generateJacobsthalNumbers(Container& jacobsthal, int max);

	template <typename Container>
	void jacobsthalInsert(Container& S, int element, size_t k);

	template <class Container, class PairContainer>
	void insertionSort(Container& S, size_t n, const PairContainer& pairs);
};

#endif // PMERGEME_HPP
