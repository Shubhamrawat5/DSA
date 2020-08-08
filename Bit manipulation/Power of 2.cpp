#include<iostream>
using namespace std;

//check if a number is power of 2 or not
int main()
{
	int n=256;

	if(n && (n & (n-1))==0)
		cout<<"Power of 2 !";
	else 
		cout<<"Not !";
}