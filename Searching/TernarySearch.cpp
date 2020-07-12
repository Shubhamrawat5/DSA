#include<iostream>
using namespace std;

//Just like binary search but Dividing array into 3 parts here
int TernarySearch(int a[],int l,int r,int find)
{
	if(r<l) return -1;
	
	int mid1,mid2;
	mid1=l+(r-l)/3; 
	mid2=mid1+(r-l)/2;
//	cout<<mid1<<" "<<mid2<<endl;
	if(a[mid1]==find) return mid1;
	else if(a[mid2]==find) return mid2;
	
	else if(find<a[mid1]) 
	    return TernarySearch(a,l,mid1-1,find);
	else if(find>a[mid2]) 
		return TernarySearch(a,mid2+1,r,find); 
	else 
		return(TernarySearch(a,mid1+1,mid2-1,find));
}

int main()
{
	int a[]={1,3,5,7,8,9,14,99};
    //int a[]={};
	int n=sizeof(a)/sizeof(a[0]);
	int find=99;
	int index=TernarySearch(a,0,n,find);
	if(index==-1)
	cout<<"Element not found!";
	else
	cout<<"Element found at index "<<index;
	
}