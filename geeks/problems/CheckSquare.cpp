/*
 * CheckSquare.cpp
 *
 *  Created on: 08-Feb-2019
 *      Author: napster
 */

#include <iostream>
#if 0
using namespace std;

struct Point{
	int x,y;
};

int sqDist(Point p1, Point p2){
	return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

bool isSquare(Point p1, Point p2, Point p3, Point p4)
{
	int xd1 = sqDist(p1,p2), xd2=sqDist(p1,p3), xd3= sqDist(p1,p4);
	int yd1 = sqDist(p2,p3), yd2=sqDist(p2,p4);
	int zd1 = sqDist(p3,p4);

	if(xd1 && (xd1 == xd2+xd3)){
		if(zd1 == xd1)
			return true;
	}
	else if(xd2 && (xd2 == xd1 + xd3)){
		if(xd2 == yd2)
			return true;
	} else if(xd3 && (xd3 == xd1 + xd2)){
		if(xd3 == yd1)
			return true;
	}
	return false;
}
// Driver program to test above function
int CheckSquare()
{
    int T;
    cin >> T;
    while(T--){
    	Point p1,p2,p3,p4;
    	cin >> p1.x >> p1.y >> p2.x >> p2.y;
    	cin >> p3.x >> p3.y >> p4.x >> p4.y;
    	if(isSquare(p1,p2,p3,p4))
    		cout << "Yes" << endl;
    	else
    		cout << "No" << endl;
    }
    return 0;
}

#endif
