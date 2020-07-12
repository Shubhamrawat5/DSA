#include<iostream>
using namespace std;

//swap function
void swap(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}

//taking 1st element as pivot then moving smaller value to left side and greater value to right side
int Partition(int a[],int l,int r)
{
	int pivot=l;
	int i=l,j=l+1;
	while(j<=r)
	{
		if(a[pivot]>a[j]) {
			++i;
			swap(&a[i],&a[j]);
		}
		++j;
	}
	swap(&a[pivot],&a[i]);
	return i;
}

//getting pivot value then divide array into 2 parts and apply both side quicksort and so on
int quicksort(int a[],int l,int r)
{
	if(l<r){
	int m=Partition(a,l,r);
	quicksort(a,l,m-1);
	quicksort(a,m+1,r); 
	}
	return 0;
}

int main()
{
	int a[]={6,3,1,10,8};
	int n=sizeof(a)/sizeof(a[0]);
	quicksort(a,0,n-1);
	for(int i=0;i<n;++i)
	cout<<a[i]<<" ";
}