/*
 * OverlappingRectangles.cpp
 *
 *  Created on: 11-Feb-2019
 *      Author: napster
 */
#if 0
#include <iostream>

using namespace std;

struct Cord{
	int x, y;
};

bool isOverlap(Cord l1, Cord r1, Cord l2, Cord r2)
{
	if ((l1.x <= l2.x) && (l2.x <= r1.x))
	{
		if ((l1.y >= l2.y) && (l2.y >= r1.y))
			return true;
	}

	if ((l2.x <= l1.x) && (l1.x <= r2.x))
	{
		if ((l2.y >= l1.y) && (l1.y >= r2.y))
			return true;
	}

	return false;
}

int OverlappingRectangles()
{
	int T;
	cin >> T;
	while(T--)
	{
		Cord l1, r1;
		Cord l2, r2;
		Cord rec;
		cin >> l1.x >> l1.y >> r1.x >> r1.y;
		cin >> l2.x >> l2.y >> r2.x >> l2.y;
		cout << isOverlap(l1, r1, l2, r2) << endl;
	}
	return 0;
}

/*
3
37 92 28 70
9 76 61 37
0 10 10 0
5 5 15 0
0 2 1 1
-2 -3 0 2
 */
#endif
