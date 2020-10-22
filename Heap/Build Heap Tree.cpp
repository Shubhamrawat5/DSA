#include<iostream>
#include<vector>
using namespace std;

void Heapify(vector<int>& v,int parent) //for max heap
{
	int lc=parent*2+1; //left child
	int rc=parent*2+2; //right child
	
	int largest=parent; //assuming root value is maximum
	
	//finding largest in both the children and parent value
	if(lc < v.size() && v[largest] < v[lc]) largest=lc;
	if(rc < v.size() && v[largest] < v[rc]) largest=rc;
	
	if(parent!=largest) //if largest is not the parent value then do some operations of swapping parent value with largest value
	{
		swap(v[largest],v[parent]);
		Heapify(v,largest); //now there can be change in that child subtree by which we swapped the value, so checking for that swapped index subtree
	}
}

void buildHeap(vector<int>& v) //build Heap is used when we already have a array and we want to make a max/min heap of it !
{
    for(int i=(v.size()-2)/2;i>=0;--i) // (n-2)/2 will give the index of the last parent node [  to get parent node=(i-1)/2 , now last index is n-1 so (n-1-1)/2 is (n-2)/2   ]
    {
        Heapify(v,i); //call for each parent node from last to first
    }
}

void displayHeap(vector<int>& v)
{
    cout<<"Displaying heap tree level wise (max-heap):-\n";
    for(int i=0;i<v.size();++i) 
        cout<<v[i]<<" ";
}

int main()
{
    vector<int> v={3,5,1,4,6,7,2,9,8};
    buildHeap(v);
    displayHeap(v);
    
    //This above buildHeap function TC is O(n)
    //To make a sorted array, heap sort can be applied to this heap tree which TC will be O(n logn) as logn is for deletion and performing n times 
    //root will have always the largest value which we can swap with last index and descrease size of array by 1 and perform this n times
}