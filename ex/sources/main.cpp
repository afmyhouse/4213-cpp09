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

void learnList(void) {
	std::list<int> list;
	std::list<int>::iterator it;
	std::cout << "================== " << __func__ << " =================" << std::endl;
	std::cout << "\nlist.push_back() list.push_front()  =========================" << std::endl;
	for (int i = 0; i < 6; i++)
		list.push_back(i * 10);
	for (int i = 0; i < 6; i++)
		list.push_front((i * 10) + 5);

	for (it = list.begin(); it != list.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "\nlist.pop_front() and list.pop_back()  =======================" << std::endl;
	list.pop_front();
	list.pop_back();
	for (it = list.begin(); it != list.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "\nlist.sort()  ================================================" << std::endl;
	list.sort();
	for (it = list.begin(); it != list.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "\nlist.reverse()  ============================================= " << std::endl;
	list.reverse();
	for (it = list.begin(); it != list.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "\nlist.insert() and list.erase()  =============================" << std::endl;
	it = list.begin();
	std::advance(it, 4);
	list.insert(it, 100);
	list.insert(list.begin(), 200);
	for (it = list.begin(); it != list.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	it = list.begin();
	std::advance(it, 2);
	it = list.erase(it);
	list.erase(it);
	for (it = list.begin(); it != list.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "\nlist.remove() ===============================================" << std::endl;
	for (it = list.begin(); it != list.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	list.remove(20);
	for (it = list.begin(); it != list.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "\nlist.unique() ===============================================" << std::endl;
	list.push_back(100);
	list.sort();
	for (it = list.begin(); it != list.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	list.unique();
	for (it = list.begin(); it != list.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "\nlist.splice() ===============================================" << std::endl;
	std::cout << "New List ====================================================\n";
	std::list<int> newList;
	for (int i = 10; i < 15; i++)
		newList.push_back(i);
	for (it = newList.begin(); it != newList.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "Previous List ===============================================\n";
	for (it = list.begin(); it != list.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	list.splice(list.begin(), newList);
	std::cout << "Previous List splice with New List ===========================\n";
	for (it = list.begin(); it != list.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "\nlist.merge() ===============================================" << std::endl;
	std::cout << "New List ====================================================\n";
	for (int i = 10; i < 15; i++)
		newList.push_back(i+20);
	for (it = newList.begin(); it != newList.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "Previous List ===============================================\n";
	for (it = list.begin(); it != list.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	list.merge(newList);
	std::cout << "Previous List merge with New List ===========================\n";
	for (it = list.begin(); it != list.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "\nlist empty, size, front, back, clear ========================\n";
	std::cout << "list.empty() : " << list.empty() << std::endl;
	std::cout << "list.size() : " << list.size() << std::endl;
	std::cout << "list.front() : " << list.front() << std::endl;
	std::cout << "list.back() : " << list.back() << std::endl;
	std::cout << "list.clear() : " << std::endl;
	list.clear();
	std::cout << "list.empty() : " << list.empty() << std::endl;
	if (!list.empty())
		list.pop_back();
	else
		std::cout << "List is empty" << std::endl;
	std::cout << "\n======== end of list basic testing with " << __func__ << "() ========" << std::endl;
}

int main()
{
	// learnVector();
	learnList();
	// std::vector<int> v;

	// std::vector<int>::const_iterator it;

	// std::srand(time(NULL));
	// for (int i = 0; i < 10; i++)
	// 	v.push_back(std::rand() % 100);

	// std::cout << "V Size : " << v.size() << std::endl;
	// std::cout << "V Capacity : " << v.capacity() << std::endl;

	// v.resize(15);
	// std::cout << "V Size : " << v.size() << std::endl;
	// std::cout << "V Capacity : " << v.capacity() << std::endl;

	// v.reserve(20);
	// std::cout << "V Size : " << v.size() << std::endl;
	// std::cout << "V Capacity : " << v.capacity() << std::endl;

	// for (it = v.begin(); it != v.end(); it++)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
	// std::cout << v[2] << std::endl;

	// try
	// {
	// 	std::cout << "Element v.at(8) :" << v.at(8) << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << "Out of range error"<< e.what() << '\n';
	// }


	// v.resize(10);
	// v.pop_back();
	// v.pop_back();
	// v.pop_back();
	// std::cout << "V Size : " << v.size() << std::endl;
	// std::cout << "V Capacity : " << v.capacity() << std::endl;



	// try
	// {
	// 	std::cout << "Element v.at(8) :" << v.at(8) << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << "Out of range error : "<< e.what() << '\n';
	// }



	return 0;
}