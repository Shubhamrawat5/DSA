#include<iostream>
using namespace std;

//swap function
void swap(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}

//taking 1st element as pivot then moving smaller value to left side of m1 and greater value to right side of m2 and equal element btw m1 & m2
int Partition(int a[],int l,int r,int &m1,int &m2)
{
	int pivot=l;
	m1=l,m2=l+1;
	while(m2<=r)
	{
		if(a[pivot]==a[m2]){
		++m2;
			}
		
		if(a[pivot]>a[j]) {
			swap(&a[m1],&a[m2]);
		}
		
		else{
			swap(&a[m2],&a[r]);
			--r;
		}
		
	}
}

//3 partition quick sort
int quicksort(int a[],int l,int r)
{
	if(l<r){
		int m1,m2;
	Partition(a,l,r,m1,m2);
	quicksort(a,l,m1-1);
	quicksort(a,m2+1,r); 
	}
	return 0;
}

int main()
{
	int a[]={2,7,2,9,2,1,8};
	int n=sizeof(a)/sizeof(a[0]);
	quicksort(a,0,n-1);
	for(int i=0;i<n;++i)
	cout<<a[i]<<" ";
}