/*
 * LexicographicallyFirstPalindromicString.cpp
 *
 *  Created on: 28-Jan-2019
 *      Author: dubeyalo
 */
#if 0
#include <bits/stdc++.h>

using namespace std;

const char MAX_CHAR = 26;

void countFreq(string str, int freq[], int len)
{
	for(int i=0;i<len; ++i)
		freq[str.at(i)-'a']++;
}

bool canMakePalindrome(int freq[], int len)
{
	int count_odd = 0;
	for(int i=0;i<MAX_CHAR;i++)
		if(freq[i]%2 != 0)
			count_odd++;
	if(len%2 == 0)
	{
		if(count_odd > 0)
			return false;
		else
			return true;
	}

	if(count_odd !=1)
		return false;
	return true;
}

string findOddAndRemoveItsFreq(int freq[])
{
	string odd_str = "";
	for(int i=0;i<MAX_CHAR;++i)
	{
		if(freq[i]%2 != 0)
		{
			freq[i]--;
			odd_str = odd_str+ (char)(i+'a');
			return odd_str;
		}
	}
	return odd_str;
}

string findPalindromicString(string str)
{
	int len = str.length();

	int freq[MAX_CHAR]={0};
	countFreq(str,freq, len);

	if(!canMakePalindrome(freq, len))
		return "No Palindrome string";

	string odd_str = findOddAndRemoveItsFreq(freq);
	string front_str = "", rear_str = " ";

	for(int i=0;i<MAX_CHAR; ++i)
	{
		string temp = "";
		if(freq[i] != 0)
		{
			char ch = (char)(i+'a');

			for(int j=1; j<=freq[i]/2;j++)
				temp = temp+ch;
			front_str = front_str + temp;
			rear_str = temp + rear_str;
		}
	}
	return (front_str + odd_str+ rear_str);
}

// Driver program
int main()
{
    string str = "appeea";
    cout << findPalindromicString(str);
    return 0;
}


#endif
