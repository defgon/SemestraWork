// Work.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "List.h"

int main() {
	List list;
	list.pushFront(5);
	list.pushBack(4);
	list.print();


	//std::cout << list.contains(8);
	//std::cout << list.indexOf(8) << std::endl;
	//std::cout << list.getValue(0);
}
