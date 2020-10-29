#include <iostream>
#define n 5
using namespace std;

int segTree[4*n]; //segment tree size is 2*(2 power ceil(logbase2 n)) . this is complex so we can use 4*n size [some index will get wasted]

int constructST(int arr[],int start,int end,int si)
{
    if(start==end) //for leaf node
    {
        segTree[si]=arr[start];
        return arr[start];
    }
    int mid=(start+end)/2;
    
    //dividing the array arr into 2 on the basis of range(start to end) !
    //if range is of even element length then n/2 both side but if range is of odd element length then n/2+1 on left and n/2 on right side
    //left child = 2*i+1 and right child = 2*i+2
    segTree[si]=constructST(arr,start,mid,si*2+1) + constructST(arr,mid+1,end,si*2+2);
    return segTree[si];
}

void printST()
{
    cout<<"Printing Segment Tree:-\n";
    for(int i=0;i<4*n;++i)
        cout<<segTree[i]<<" ";
}

int getSum(int qs,int qe,int start,int end,int si)
{
    if(qs>end || qe<start) //if the query is out of range of current node range, so no need to check further as child node range will always be within this current node range
        return 0;
    
    if(qs<=start && qe>=end) //if the current node range it totally inside the query range then return node value as all child be under this query range    
        return segTree[si];
        
    int mid=(start+end)/2;
    return getSum(qs,qe,start,mid,si*2+1) + getSum(qs,qe,mid+1,end,si*2+2);
}

int sumRange(int qs,int qe) //query start and query end
{
    return getSum(qs,qe,0,n-1,0);
}

int main() {
	int arr[n]={10,20,30,40,50};
	//constructST(array,startIndex,LastIndex,first index of segment tree)
	constructST(arr,0,n-1,0);
	printST();
	
	cout<<"\n";
	cout<<sumRange(0,2); //to get sum from index 0 to index 2 
	cout<<"\n";
	cout<<sumRange(1,3);
	cout<<"\n";
	cout<<sumRange(4,4);
	return 0;
}
