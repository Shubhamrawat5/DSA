#include<iostream>
using namespace std;

//FOR BUILD HEAP METHOD:-
//APPLYING HEAPIFY ON A ALREADY CREATED TREE
//STARTING FROM LAST TRIANGLE THEN MOVING UP

//inbuilt func of swap available already 
/*void swap(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;	
}*/

//i is parent node, lc & rc are child nodes
void Heapify(int a[],int i,int n)
{
	int largest=i; //assume parent is largest
	int lc=i*2+1;
	int rc=i*2+2;
	
	if(lc<n && a[lc]>a[largest]) //check if lc is largest or not
	largest=lc;
	
	if(rc<n && a[rc]>a[largest]) //check if rc is largest or not
	largest=rc;
	
	if(i!=largest) //if largest changed
	{
		swap(a[i],a[largest]); 
		Heapify(a,largest,n); //recursively calling heapify with the swapped index where the changes may happen
	}
}

void HeapSort(int a[],int n)
{
	int i;
	for(i=n/2-1;i>=0;--i)
	Heapify(a,i,n);
	
	for(i=n-1;i>=0;--i)
	{
		swap(a[0],a[i]);
		Heapify(a,0,i);		
	}
}


int main()
{
	int a[]={5,8,1,6,9,3,7,4};
	int n=sizeof(a)/sizeof(a[0]);
	HeapSort(a,n);
	for(size_t i=0;i<n;++i)
	cout<<a[i]<<" ";
}