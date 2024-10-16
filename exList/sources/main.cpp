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
	learnList();
	return 0;
}