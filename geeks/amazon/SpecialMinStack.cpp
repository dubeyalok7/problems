/*
 * SpecialStack.cpp
 *
 *  Created on: 16-Feb-2019
 *      Author: napster
 */

#if 0
#include <iostream>
#include <stack>

using namespace std;

class SStack
{
	stack<int> s;
	int minEle;
public:
	void getMin()
	{
		if(s.empty())
			cout << "Stack is empty" << endl;
		else
			cout << "Minimum element: " << minEle << endl;
	}

	void peek()
	{
		if(s.empty())
		{
			cout << "Stack is empty" << endl;
			return;
		}

		int t = s.top();

		cout << "Top element: " << endl;

		(t < minEle)? cout << minEle: cout << t;
	}

	void pop()
	{
		if(s.empty()){
			cout << "Stack is empty" << endl;
			return;
		}

		cout << "Top most element removed." << endl;
		int t = s.top();
		s.pop();

		if(t < minEle)
		{
			cout << minEle << endl;
			minEle = 2*minEle - t;
		}
		else
			cout << t << endl;
	}

	void push(int x)
	{
		if(s.empty()){
			minEle = x;
			s.push(x);
			cout << "Number inserted." << x << endl;
			return;
		}

		if(x < minEle)
		{
			s.push(2*x - minEle);
			minEle = x;
		}
		else
			s.push(x);

		cout << "Number inserted." << x << endl;
	}
};


// Driver Code
int SpecialMinStack()
{
	SStack s;
    s.push(3);
    s.push(5);
    s.getMin();
    s.push(2);
    s.push(1);
    s.getMin();
    s.pop();
    s.getMin();
    s.pop();
    s.peek();

    return 0;
}
#endif
