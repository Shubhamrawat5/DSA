#include<iostream>
using namespace std;

int LinearSearch(int a[],int i,int n,int x)
{
	if(i==n) return -1;
	if(a[i]==x) return i;
	return(LinearSearch(a,i+1,n,x));
}

int main()
{
	int a[]={6,3,8,4,2,1,10,9};
	int n=sizeof(a)/sizeof(a[0]);
	int numbSearch=13;
	int check=LinearSearch(a,0,n,numbSearch);
	if(check==-1) cout<<numbSearch<<" is not found!!";
	else cout<<numbSearch<<" is found at index "<<check;
}