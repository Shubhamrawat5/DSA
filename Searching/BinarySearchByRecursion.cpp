#include<iostream>
using namespace std;

int BinarySearch(int a[],int l,int r,int x)
{
	if(l>r) return -1;
	int mid=(l+r)/2;
	if(a[mid]==x) return mid;
	else if(a[mid]>x)
		return(BinarySearch(a,l,mid-1,x));
	else
	    return(BinarySearch(a,mid+1,r,x));
}

int main()
{
    int a[]={2,4,6,7,8,10};

	int n=sizeof(a)/sizeof(a[0]);
	int numbSearch=6;
	int check=BinarySearch(a,0,n,numbSearch);
	if(check==-1) cout<<numbSearch<<" is not found!!";
	else cout<<numbSearch<<" is found at index "<<check;
}
