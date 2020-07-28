#include<iostream>
using namespace std;

struct Node //doubly linked list
{
	int data;
	Node *prev,*next;
	Node(int x)
	{
		data=x;
		prev=next=NULL;
	}
};
		
struct Deque
{
	Node *head,*tail;
	Deque()
	{
		head=tail=NULL;
	}
	
	int getFront()
	{
		if(head==NULL) return -1;
		return head->data;
	}
	
	int getLast()
	{
		if(head==NULL) return -1;
		return tail->data;
	}
	
	void insertFront(int x)
	{
		if(head==NULL) //if deque empty
		{
			head=new Node(x);
			tail=head;
			return;
		}
		Node *temp=new Node(x);
		temp->next=head;
		head->prev=temp;
		head=temp;
	}
	
	void insertLast(int x)
	{
		if(tail==NULL) //if deque empty
		{
			tail=new Node(x);
			head=tail;
			return;
		}
		Node *temp=new Node(x);
		tail->next=temp;
		temp->prev=tail;
		tail=temp;		
	}
	
	void deleteFront()
	{
		if(head==NULL) //deque empty
			return;
		Node *temp=head;
		head=head->next;
		delete(temp);
		
		if(head==NULL)//deque become empty
	   	 tail=NULL;
		else
			head->prev=NULL;
	}
	
	void deleteLast()
	{
		if(tail==NULL) //deque empty
			return;
		Node *temp=tail;
		tail=tail->prev;
		delete(temp);
		if(tail==NULL) //deque become empty
			head=NULL;
		else
			tail->next=NULL;
	}
	
	
	void Display()
	{
		if(head==NULL) 
		{
			cout<<"\nDeque is empty!\n";
			return;
		}
		Node *iter=head;
		cout<<"\nPrinting Deque: \n";
		while(iter)
		{
			cout<<iter->data<<" ";
			iter=iter->next;
		}
		
	}
};

int main()
{
	Deque d;
	d.insertLast(6);
	d.insertLast(10);
	d.Display();
	d.insertFront(2);
	d.insertFront(1);
	d.insertLast(20);
	d.Display();
//	cout<<"\nLast is :"<<d.getLast();
//	cout<<"\nFirst is :"<<d.getFront();
	d.deleteFront();
	d.deleteLast();
	d.deleteLast();
	d.Display();
	d.deleteFront();
	d.Display();
	d.deleteFront();
	d.Display();
}