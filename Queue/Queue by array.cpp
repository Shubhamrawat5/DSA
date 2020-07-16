//implementation of queue using array with O(n-1) in deque operation

#include<iostream>
using namespace std;

struct Queue
{
	int cap,size; //front is always 0 and rear is size-1
	int *arr;
	Queue(int cap)
	{
		this->cap=cap;
		size=0;
		arr=new int[cap];
	}
	
	int getFront() //return index of front
	{
		if(isEmpty()) return -1;
		return 0;
	}
	
	int getRear() //return index of rear
	{
		if(isEmpty()) return -1;
		return size-1;
	}
		
	
	bool isEmpty()  //check if queue is empty or not
	{
		return(size==0);
	}
	
	bool isFull() //check if queue is full or not
	{
		return(size==cap);
	}
	
	void enque(int x) //add element
	{
		if(size==cap) return;
		arr[size++]=x;
	}
	
	void deque() //remove element
	{
		if(isEmpty()) return;
		for(int i=0;i<size-1;++i)
		arr[i]=arr[i+1];
		--size;
	}
	
	void display()
	{
		if(isEmpty()) 
		{
			cout<<"\nQueue is empty!\n";
			return;
		}
		cout<<"\nPrinting queue:-\n";
		for(int i=0;i<size;++i)
		cout<<arr[i]<<" ";
	}
};

int main()
{
	Queue q(5);
	q.enque(1);
	q.enque(3);
	q.enque(6);
	q.enque(2);
	q.deque();
	cout<<q.arr[q.getFront()];
	q.display();
}