#include<iostream>
using namespace std;

void swap(int *x,int *y)
{
	int temp;
	temp=*y;
	*y=*x;
	*x=temp;
}

void InsertionSort(int a[],int n)
{
	int i,j;
	for(i=0;i<n-1;++i)
	{	
		for(j=i+1;j>0;--j)
		{
			if(a[j]>=a[j-1]) break;
			else swap(&a[j],&a[j-1]);
		}
	}

}

int main()
{
	int a[]={4,7,27,32,15,74,13,4,9,6,5};
	int n=sizeof(a)/sizeof(a[0]);
	InsertionSort(a,n);
	
	//Printing sorted array
	for(int k=0;k<n;++k)
	cout<<a[k]<<" ";
}