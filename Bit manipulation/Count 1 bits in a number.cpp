#include<iostream>
using namespace std;

//calculate number of 1 in a number
int main()
{
	int n=26;
	int count=0;
	
	while(n>0)
	{
		if((n & 1)==1) //checking if bit is 1
			++count;
		n=n>>1;	//right shift by 1 (removing last bit)
	}
	cout<<count<<endl;
	
	
/* BY BRIAN KARNIGHAN TECHNIQUE*/
	n=26;
	count=0;
	while(n>0)
	{
		n=n&(n-1); //eliminating leftest 1 bit
		++count;
	}
	cout<<count;
}