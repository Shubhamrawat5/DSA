//Count sort is non-comparing sorting technique
//It's for limited range & repeated numbers
//This is a example for n range repeated elements sorting

#include<iostream>
using namespace std;
#define n 10 // range 0 to 9 

void CountSort(int a[],int size)
{
	//counting number of repetition
	int count[n]={0}; 
	int i;
	for(i=0;i<size;++i)
	++count[a[i]];
	
	//range from which the value starts and end in sorted array
	int range[n]={0};
	for(i=1;i<n;++i)
	range[i]=range[i-1]+count[i-1];
	
	//sorting the array and storing in sorted named array
	int sorted[size];
	for(i=0;i<size;++i)
	{
		sorted[range[a[i]]]=a[i];
		++range[a[i]];
	}
	
	//printing sorted array
	for(int i:sorted)
	cout<<i<<" ";
}


//ALTERNATE FUNCTION FOR SORTING
void AlternateSort(int a[],int size)
{
	int count[n]={0};
	int i;
	for(i=0;i<size;++i)
	++count[a[i]];
	
	cout<<"\n";
	i=0;
	while(i<n)
	{
		if(count[i]>0) {
		cout<<i<<" ";
		--count[i]; 
		}
		
		else
		++i;
	}	
}


int main()
{
	int a[]={7,1,4,7,9,9,6,4,3,2,3,1,1,1,7,6,9,0};
	int size=sizeof(a)/sizeof(a[0]);
	CountSort(a,size);	
	AlternateSort(a,size);
}