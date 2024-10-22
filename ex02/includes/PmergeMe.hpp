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

		double mergeInsertionSort(std::vector<int> &nums);
		double mergeInsertionSort(std::deque<int> &nums);

		template <typename Container>
		double mergeInsertionSort(Container &nums);

		bool parser(char **argv, std::vector<int> &vec, std::deque<int> &deque);
		std::string joinStrings(const std::vector<std::string>& strings);

	private:
		// common operations

		// // vector container operations
		// void createPairs(const std::vector<int> &nums, std::vector<std::vector<int> > &pairs);
		// void generateJacobsthalSequence(std::vector<size_t> &vec);
		// void mergeSort(std::vector<std::vector<int> > &pairs);
		// void merge(std::vector<std::vector<int> > &left, std::vector<std::vector<int> > &right, \
		// 	std::vector<std::vector<int> > &result);
		// void insertionSort(std::vector<int> &S, size_t n, const std::vector<std::vector<int> > &pairs);
		// void binarySearch(std::vector<int> &S, int number);

		// // deque container operations
		// void createPairs(const std::deque<int> &nums, std::deque<std::deque<int> > &pairs);
		// void generateJacobsthalSequence(std::deque<size_t> &vec);
		// void mergeSort(std::deque<std::deque<int> > &pairs);
		// void merge(std::deque<std::deque<int> > &left, std::deque<std::deque<int> > &right, \
		// 	std::deque<std::deque<int> > &result);
		// void insertionSort(std::deque<int> &S, size_t n, const std::deque<std::deque<int> > &pairs);
		// void binarySearch(std::deque<int> &S, int number);

		// template container operations
		template <typename Container>
		void createPairs(const Container &nums, Container &pairs);

		template <typename Container>
		void generateJacobsthalSequence(Container &vec);

		template <typename Container>
		void mergeSort(Container &pairs);

		template <typename Container>
		void merge(Container &left, Container &right, Container &result);

		template <typename Container>
		void insertionSort(Container &S, size_t n, const Container &pairs);

		template <typename Container>
		void binarySearch(Container &S, int number);

		double elapsedTime(const timeval &end, const timeval &start);

};

#endif