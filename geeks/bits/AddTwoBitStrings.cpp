/*
 * AddTwoBitStrings.cpp
 *
 *  Created on: 16-Aug-2018
 *      Author: dubeyalo
 */
#include <iostream>
using namespace std;

#if 0

void makeEqual(string &str1, string &str2){
	int diff = str2.length()-str1.length();
	while(diff--){
		str1 = "0" + str1;
	}
}

string addBitStrings(string str1, string str2)
{
	int c=0;
	string str;
	if(str1.length()>str2.length())
		makeEqual(str2,str1);
	else if(str1.length()<str2.length())
		makeEqual(str1,str2);
	for(int i=str1.length()-1;i>=0;--i){
		str1[i] = (str1[i]-'0')+(str2[i]-'0')+'0';
	}
	for(int i=str1.length()-1; i>=0;--i){
		if((str[i]-'0')>=2){
			str[i] = c + (str[i]-'0')%2;
			c = (str[i]-'0')/2;
			str[i]+='0';
		}
	}
	string res;
	while(c){
		res.push_back(c%2+'0');
		c/=2;
	}
	for(int i=0;i<res.length()/2;++i){
		char ch = res[i];
		res[i] = res[res.length()-1];
		res[res.length()-1]= ch;
	}
	return str1;
}


// Driver program to test above functions
int main()
{
    string str1 = "1100011";
    string str2 = "101110101";

    cout << "Sum is " << addBitStrings(str1, str2);
    return 0;
}
#endif
