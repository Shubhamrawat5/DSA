#include<iostream>
using namespace std;

//Just a swap function
void swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

void BubbleSort(int a[],int n)
{
	int i,j;
	for(i=0;i<n-1;++i)   //1 to n-1 pass
	{
		for(j=0;j<n-i-1;++j)  //reducing 1 index from end everytime as biggest number will get in the end after every pass
		{
			if(a[j]>a[j+1]) 	//comparing 2 adjacent values
			swap(&a[j],&a[j+1]);
		}
	}
}

int main()
{
	int a[]={6,97,8,98,52,23,54,2,5,8,1};
	int n=sizeof(a)/sizeof(a[0]);
	BubbleSort(a,n);
	//Printing sorted list
	for(int k=0;k<n;++k)
	cout<<a[k]<<" ";
}