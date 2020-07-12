#include<iostream>
#include<math.h>
using namespace std;

//For sorted array only
int JumpSearch(int a[],int n,int find)
{
	int jump=sqrt(n);
	int last=0;
	int curr=0;
	if(find<a[0] || find>a[n-1]) return -1;
	
	while(a[curr]<=find)
	{
		last=curr;
		curr+=jump;
		if(curr>=n) break;
	}
//	cout<<curr<<" "<<last<<endl;
	curr=min(curr,n);
	for(int i=last;i<curr;++i)
	{
		if(find==a[i]) return i;
	}
	return -1;

}

int main()
{
	int a[]={1,2,3,4,5,6,8,9,10,32,54,55,77,88};
 //   int a[]={};
	int n=sizeof(a)/sizeof(a[0]);
	int find=88;
	int index=JumpSearch(a,n,find);
	if(index==-1)
	cout<<"Element not found!";
	else
	cout<<"Element found at index "<<index;
}