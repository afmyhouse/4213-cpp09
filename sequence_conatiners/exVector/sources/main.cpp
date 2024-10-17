#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <vector>
#include <stack>
#include <list>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <algorithm>

void learnVector(void) {
	std::vector<int> v;
	std::vector<int>::iterator it;

	std::cout << "vector.size()     : " << v.size() << std::endl;
	std::cout << "vector.capacity() : " << v.capacity() << std::endl;
	std::cout << "Fill V with 5 elements" << std::endl;
	std::cout << "vector.push_back(whatever)" << std::endl;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	std::cout << "V max element : " << *std::max_element(v.begin(), v.end()) << std::endl;


	for (it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "vector.insert() and vector.erase()" << std::endl;
	v.insert(v.begin() + 2, 35);
	for (it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	v.erase(v.begin() + 2);
	for (it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	v.resize(15);
	std::cout << "v.resize(15)      : " << std::endl;
	std::cout << "vector.size()     : " << v.size() << std::endl;
	std::cout << "vector.capacity() : " << v.capacity() << std::endl;


	v.reserve(20);
	std::cout << "vector.reserve(20): " << std::endl;
	std::cout << "vector.size()     : " << v.size() << std::endl;
	std::cout << "vector.capacity() : " << v.capacity() << std::endl;

	for (it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "vector[2]         : "<< v[2] << std::endl;

	try
	{
		std::cout << "Element v.at(8) :" << v.at(8) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Out of range error"<< e.what() << '\n';
	}


	v.resize(10);
	v.pop_back();
	v.pop_back();
	v.pop_back();
	std::cout << "vector.size()     : " << v.size() << std::endl;
	std::cout << "vector.capacity() : " << v.capacity() << std::endl;



	try
	{
		std::cout << "Element v.at(8) :" << v.at(8) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Out of range error : "<< e.what() << '\n';
	}

	v.clear();
	std::cout << "vector.clear()    : " << std::endl;
	for (it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "vector.size()     : " << v.size() << std::endl;
	std::cout << "vector.capacity() : " << v.capacity() << std::endl;

}

int main()
{
	learnVector();
	return 0;
}