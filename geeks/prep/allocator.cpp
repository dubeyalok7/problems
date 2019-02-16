/*
 * allocator.cpp
 *
 *  Created on: 31-Jan-2019
 *      Author: dubeyalo
 */
#include <iostream>
#include <memory>
#include <string>
#include <array>

#if 0

using namespace std;

class Base{
	int a;
public:
	Base(int _a):a(_a){
		//this->a = _a;
		cout << "Contructor called: " << a << endl;
	}
	~Base(){
		cout << "Destructor called" << endl;
	}
};

int Allocator(){
	allocator<Base> alloc;
	Base *ptr = alloc.allocate(2);
	alloc.construct(ptr, 5);
	alloc.construct(ptr+1, 6);

	alloc.destroy(ptr);
	alloc.destroy(ptr+1);

	array<int, 3> arr;
	arr.
	return 0;
}


#endif
