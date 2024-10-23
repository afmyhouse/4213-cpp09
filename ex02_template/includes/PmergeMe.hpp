#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <sstream>
# include <ctime>
# include <sys/time.h>
# include <string>
# include <limits>
# include <chrono>
# include <cmath>
# include <vector>
# include <deque>
# include <algorithm>

# define UNUSED -1
# define A 0
# define B 1
# define MIN(a, b) ((a) < (b) ? (a) : (b))
# define MAX(a, b) ((a) > (b) ? (a) : (b))

class PmergeMe
{
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
		double mergeInsertionSort(Container &nums);

	private:
		template <typename Container>
		void createPairs(const Container &nums, Container &pairs);

		template <typename Container>
		void merge(Container &left, Container &right, Container &result);

		template <typename Container>
		void mergeSort(Container &pairs);

		template <typename Container>
		void generateJacobsthalNumbers(Container &jacobsthal, int max);

		template <typename Container>
		void jacobsthalInsert(Container& S, int element);

		template <typename Container>
		void insertionSort(Container &S, size_t n, const Container &pairs);
};

#endif