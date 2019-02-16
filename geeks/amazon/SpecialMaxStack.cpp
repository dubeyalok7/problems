/*
 * SpecialMaxStack.cpp
 *
 *  Created on: 16-Feb-2019
 *      Author: napster
 */
#if 0
#include <iostream>
#include <stack>

using namespace std;

class SMaxStack{
	stack<int> s;
	int MaxEle;
public:

	void getMax()
	{
		if(s.empty()){
			cout << "Stack is empty." <<endl;
		}
		else
			cout << "Max element: " << MaxEle <<endl;
	}

	void pop()
	{
		if(s.empty()){
			cout << "Stack is empty." << endl;
			return;
		}

		cout << "Top element is removed." << endl;
		int t = s.top();
		s.pop();
		if(t > MaxEle){
			cout << "Stack pop. " << MaxEle << endl;
			MaxEle = 2*MaxEle -t;
		} else
			cout << "Stack pop. " << t << endl;
	}

	void push(int x)
	{
		if(s.empty()){
			MaxEle = x;
			s.push(x);
			cout << "Element inserted: " << x <<endl;
			return;
		}

		if(x > MaxEle){
			s.push(2*x - MaxEle);
			MaxEle = x;
		}
		else
			s.push(x);

		cout << "Element inserted: " << x << endl;
	}

	void peek()
	{
		if(s.empty()){
			cout << "Stack empty." <<endl;
			return;
		}

		int t = s.top();
		cout << "Top most element: " << t;

		(t > MaxEle)? (cout << MaxEle) : (cout << t);
		cout << endl;
	}
};



int SpecialMaxStack()
{
	SMaxStack s;
    s.push(3);
    s.push(5);
    s.getMax();
    s.push(7);
    s.push(19);
    s.getMax();
    s.pop();
    s.getMax();
    s.pop();
    s.peek();
    s.getMax();

    return 0;
}
#endif
