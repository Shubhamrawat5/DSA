#include<iostream>
using namespace std;

/*
XOR ^ operator property
x ^ x = 0
x ^ 0 = x
*/

//Program to find missing number of consecutive numbers in unsorted array 
int main()
{
	int a[]={4,1,3,6,2,0};
	int n=sizeof(a)/sizeof(a[0]);
	int mis=0,i;

	for(i=1;i<n+1;++i)
	{
		mis=mis ^ i;
	}
	
	for(i=0;i<n;++i)
		mis=mis ^ a[i];
		
	cout<<mis;
	
}