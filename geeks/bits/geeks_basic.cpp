/*
 * geeks_basic.cpp
 *
 *  Created on: 14-Aug-2018
 *      Author: dubeyalok
 */

#include <bits/stdc++.h>
#define INT_SIZE 32
using namespace std;
#if 0
int getSingle(int arr[], int n)
{
    int result = 0;
    int x, sum;
    for (int i = 0; i < INT_MAX; i++)
    {
      sum = 0;
      x = (1 << i);
      for (int j=0; j< n; j++ ) {
          if (arr[j] & x)
            sum++;
      }
      if (sum % 3)
        result |= x;
    }
    return result;
}

int addOne(int x)
{
	int m = 1;
	while(x&m){
		x ^=m;
		m<<=1;
	}
	x ^=m;
	return x;
}

bool isPowerOfFour(unsigned int x)
{
	unsigned int a=4;
	while(x^a){
		if((a>x)||(!a))
			return false;
		a<<=1;
	}
	return true;
}

float multiplyWith3Point5(int x)
{
	return (x<<1) + x + (x>>1);
}

unsigned int leftShift(unsigned int x, int d){
	return (x<<d)|(x>>(INT_MAX-d));
}

int rightShift(int x, int d) {
	return (x>>d)|(x<<(INT_MAX-d));
}


int addOvf(int x, int y)
{
	cout << INT_MAX << endl;
	if((x>INT_MAX-y)||(y>INT_MAX-x))
		return 0;
	else
		return x+y;
}

int countBitsSet(int a, int b)
{
	int t = a^b;
	int cnt =0;
	while(t){
		t&=(t-1);
		cnt++;
	}
	return cnt;
}

int mul7(int a){
	return (a<<3)-a;
}

int numPower(int a){
	int cnt =0;
	int t = 1;
	while(a^t){
		cnt++;
		t<<=1;
		if(t>a)
			return 0;
	}
	return cnt;
}

bool isPowerOfTwo (int x)
{
  return x && (!(x&(x-1)));
}


void bin(int a)
{
	if(a>1)
		bin(a/2);
	printf("%d ", a%2);
}

int printPos(int a)
{
	int n = a&&(!(a&(a-1)));
	if(!n)
		return -1;
	int cnt = 0;
	while(a){
		a>>=1;
		cnt++;
	}
	return cnt;
}

char swapNibbles(char x){
	return ((x&0x0F)<<4 | (x&0xF0)>>4);
}


int turnOfK(int n, int k){
	int b = 1<<(k-1);
	return b^n;
}

int russianPeasant(int a, int b)
{
	int res =0;
	while(b>0){
		if(b&1)
			res = res+a;
		a<<=1;
		b>>=1;
	}
	return res;
}

int main()
{
    //int arr[] = {3, 3, 2, 3};
    //int n = sizeof(arr) / sizeof(arr[0]);
    //printf("The element with single occurrence is %d \n",
    //        getSingle(arr, n));
    printf("%d \n",addOne(12));
    printf("%0.2f\n", multiplyWith3Point5(2));
    printf("%d\n", isPowerOfFour(INT_MAX+1));
    printf("l-> %d, r->%d\n", leftShift(3840,3), rightShift(3840,3) );
    printf("%d\n", addOvf(INT_MAX+34,13));
    printf("%d\n", countBitsSet(7,10));
    cout << mul7(7)<< endl;
    cout << numPower(255) << endl;
    cout << isPowerOfTwo(255) << endl;
    bin(177); cout << endl;
    cout << printPos(16) << endl;
    printf("%d\n",swapNibbles(65));
    cout << turnOfK(15,4) << endl;
    cout << russianPeasant(5,7)<< endl;
    return 0;
}



#endif
