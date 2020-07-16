//circular queue using array with O(1) in all operations

#include<iostream>
using namespace std;

struct Queue
{
	int cap,size;
	int front; //rear is (front+size-1)%cap
	int *arr;
	Queue(int cap)
	{
		front=0;
		this->cap=cap;
		size=0;
		arr=new int[cap];
	}
	
	int getFront() //return index of front
	{
		if(isEmpty()) return -1;
		return front;
	}
	
	int getRear() //return index of rear
	{
		if(isEmpty()) return -1;
		return (front+size-1)%cap;
	}
		
	
	bool isEmpty()  //check if queue is empty or not
	{
		return(size==0);
	}
	
	bool isFull() //check if queue is full or not
	{
		return(size==cap);
	}
	
	void enque(int x) //add element to rear+1
	{
		if(size==cap) return;
		
		arr[(getRear()+1)%cap]=x;
		
		++size;
	}
	
	void deque() //remove element from rear
	{
		if(isEmpty()) return;
	
		front=(front+1)%cap;
		--size;
	}
	
	void display()
	{
		if(isEmpty()) 
		{ cout<<"\nQueue is empty!\n";
		return;}
		
		cout<<"\nPrinting circular queue:- \n";
		for(int i=0;i<size;++i)
		cout<<arr[(front+i)%cap]<<" ";
	}
};

int main()
{
	Queue q(5);
	q.enque(1);
	q.enque(3);
	q.enque(6);
	q.enque(4);
	q.display();
	q.deque();
	q.deque();
	q.enque(10);
	q.display();
	q.deque();
	q.deque();
	q.display();
	q.deque();
	q.display();
//	cout<<q.arr[q.getFront()];
}