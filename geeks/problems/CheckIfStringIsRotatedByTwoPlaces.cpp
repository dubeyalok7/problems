/*
 * CheckIfStringIsRotatedByTwoPlaces.cpp
 *
 *  Created on: 11-Feb-2019
 *      Author: napster
 */
#if 0
#include <iostream>

using namespace std;

string leftRotate(string str)
{
	string nstr;
	for(unsigned int i =2; i< str.length(); i++)
		nstr.push_back(str[i]);
	nstr.push_back(str[0]);
	nstr.push_back(str[1]);
	return nstr;
}

string rightRotate(string str)
{
	string nstr;
	nstr.push_back(str[str.length()-2]);
	nstr.push_back(str[str.length()-1]);
	for(unsigned int i = 0; i < str.length() - 2; i++)
		nstr.push_back(str[i]);
	return nstr;
}

int CheckIfStringIsRotatedByTwoPlaces()
{
	int T;
	cin >> T;
	while(T--){
		string str1, str2;
		string lstr, rstr;
		cin >> str1 >> str2;
		lstr = leftRotate(str1);
		rstr = rightRotate(str1);
		cout << ((!str2.compare(lstr)) || (!str2.compare(rstr))) << endl;
	}
	return 0;
}
#endif
