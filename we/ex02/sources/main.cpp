/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:22:07 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/09/23 19:34:51 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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
	PmergeMe sorter;
		
	if (argc < 2)
		return (-1);
	if (!sorter.parse(argv + 1, vec, deque))
		return (std::cout << "Error\n", 1);
	
	std::cout << "Before: ";
	print(vec);
	
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