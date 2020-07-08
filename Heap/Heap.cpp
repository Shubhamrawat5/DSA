#include<iostream>
#include<vector>
using namespace std;

void Heapify(vector<int>& v,int root,char c)
{
	int lc=root*2+1; //left child
	int rc=root*2+2; //right child
	int min=root; //assuming root value is minimum
	if(lc<v.size() && v[lc]<v[min]) min=lc;
	if(rc<v.size() && v[rc]<v[min]) min=rc;
	
	if(root!=min) //min changed
	{
		swap(v[min],v[root]);
		if(c=='i') //insertion
		{
		Heapify(v,(root-1)/2,'i'); //there will be change in parent node
		}
		else if(c=='d') //deletion
		{
		Heapify(v,min,'d');
		}
	}
}

void Insertion(vector<int>& v)
{
	int ele;
	cout<<"Enter element :";
	cin>>ele;
	cout<<"\nInserting in heap : "<<ele<<"\n";
	if(v.size()==0) //heap is empty
	{
		v.push_back(ele);
		return;
	}
	else
	{
		v.push_back(ele);
		Heapify(v,(v.size()-1-1)/2,'i'); 
		//root node=(i-1)/2 where i is the new inserted node index i.e. v.size()-1
	}
	
}

void Deletion(vector<int>& v)
{
	if(v.size()==0)
	{
		cout<<"\nHeap is empty!\n";
		return;
	}
	//for root not delete
	cout<<"Deleting Root node : "<<v[0]<<"\n";
	swap(v[0],v[v.size()-1]); //swap with last index
	v.pop_back(); 
	
	Heapify(v,0,'d');
}

void PrintHeap(vector<int>& v)
{
	cout<<"Printing Heap :- \n";
	for(auto i:v)
	cout<<i<<" ";
	cout<<"\n\n";
}

void SortHeap(vector<int>&v)
{
	cout<<"\nSorting the heap !!!!\n";
	vector<int> s;
	int n=v.size();
	for(int i=0;i<n;++i)
	{
	s.push_back(v[0]);
	Deletion(v);
	}
	v=s;
}

int main()
{
	vector<int> v;
	int choice=1;
	cout<<"--------H E A P---------\nType 1 for insertion !\nTypr 2 for deletion !\nType 3 for sort the heap !\nType 0 for exit\n";
	while(choice)
	{
		cout<<"\nEnter choice : ";
		cin>>choice;
		if(choice==1)
		{
			Insertion(v);
			PrintHeap(v);
		}
		
		else if(choice==2)
		{
			Deletion(v);
			PrintHeap(v);
		}
		
		else if(choice==3)
		{
			SortHeap(v);
			PrintHeap(v);
		}
	}
	
}