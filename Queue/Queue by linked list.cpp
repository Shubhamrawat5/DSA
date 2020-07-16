#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node(int x)
	{
		data=x;
		next=NULL;
	}
};

struct Queue
{
	Node* head,*rear; //front = head
	int size=0;
	Queue()
	{
		head=NULL;
		rear=NULL;
	}
	
	void enque(int x)
	{
		if(head==NULL)
		{
			head=new Node(x);
			rear=head;
		}
		else
		{
			Node* temp=new Node(x);
			rear->next=temp;
			rear=rear->next;
		}
		++size;
	}
	
	void deque()
	{
		if(head==NULL) return;
		Node* temp=head;
		head=head->next;
		if(head==NULL) rear=NULL; //queue gets empty so rear need to be updated
		delete(temp);
		--size;
	}
	
	int getSize()
	{
		return size;
	}
	
	int getFront()
	{
		if(head==NULL) return -1;
		return head->data;
	}
	
	int getRear()
	{
		if(rear==NULL) return -1;
		return rear->data;
	}
	
	bool isEmpty()
	{
		return(!head);
	}
	
	void display()
	{
		if(head==NULL) 
			cout<<"\nQueue is empty!\n";
		else
		{
			cout<<"\nPrinting Queue:-\n";
			Node* iter=head;
			while(iter!=NULL)
			{
				cout<<iter->data<<" ";
				iter=iter->next;
			}
		}
	}
};


int main()
{
	Queue q;
	q.enque(10);
	q.enque(20);
	q.enque(70);
	q.display();
	q.deque();
	q.display();
	q.deque();
	q.enque(90);
	q.display();
	cout<<"\n"<<q.getSize();
	cout<<"\n"<<q.getRear();
}