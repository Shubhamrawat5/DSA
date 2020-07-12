#include<iostream>
using namespace std;

void merge(int a[],int l,int mid,int r)
{
//	cout<<a[l]<<" "<<a[mid]<<" "<<a[r]<<"\n";
	int n1=mid-l+1; //left part size
	int n2=r-mid; //right part size
	int t1[n1],t2[n2]; //created 2 temp array
	int i,j,k;
	
	for(i=0;i<n1;++i) //storing left side value in t1
	t1[i]=a[l+i];
	for(j=0;j<n2;++j) //storing right side value in t2
	t2[j]=a[mid+1+j];
	
	i=0; //starting index for t1
	j=0; //starting index for t2
	k=l; //starting index of main array a

	while(i<n1 && j<n2) //Filling values in main array a by comparing t1 and t2 array
	{
		if(t1[i]<t2[j])		{
			a[k]=t1[i];
			++i;
		}
		else		{
			a[k]=t2[j];
			++j;
		}
		++k;
	}
	
	//adding remaining elements
	while(i<n1)	{
		a[k]=t1[i];
		++i;
		++k;
	}
	
	while(j<n2)	{
		a[k]=t2[j];
		++j;
		++k;
	}
	
//	for(i=0;i<n;i++)
//	cout<<a[i]<<",";
//	cout<<endl;
	
}

int mergesort(int a[],int l,int r)
{
	if(l==r) return 0;
	int mid=(l+r)/2;
	mergesort(a,l,mid);
	mergesort(a,mid+1,r);
    merge(a,l,mid,r);
}


int main()
{
	int a[]={10,8,2,6,12,3};
	int n=sizeof(a)/sizeof(a[0]);
	mergesort(a,0,n-1);
	//printing sorted array
	for(int i=0;i<n;++i)
	cout<<a[i]<<" ";
}