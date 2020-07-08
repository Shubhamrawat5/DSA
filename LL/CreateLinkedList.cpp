#include<iostream>
using namespace std;

class Node
{
	public:
	int data;
	Node *next;
};

void printList(Node* n)
{
	cout<<"\nPRINTING LIST :-\n";
	while(n!=NULL)
	{
		cout<<n->data<<" ";
		n=n->next;
	}
}

void InsertNodeAtEnd(Node* &head,int& size)
{
	int ele;
	cout<<"Enter element to insert at end: ";
	cin>>ele;
	if(head==NULL) //no element
	{
		head=new Node();
		head->data=ele;
		head->next=NULL;
	}
	else
	{
		Node* temp=new Node();
		Node* iter=head;
		while(iter->next!=NULL)
		iter=iter->next;
		
		iter->next=temp;
		temp->data=ele;
		temp->next=NULL;
	}
	++size;
}

void InsertNodeAtPos(Node* &head,int& size)
{
	int pos,ele;
	cout<<"\nEnter Postion(1 to "<<size+1<<") and element :";
	cin>>pos>>ele;
	if(pos<1 || pos-1>size)
	{
		cout<<"\nINVALID POS !\n";
		return;
	}
	Node* iter=head;
	Node* temp=new Node();
	temp->data=ele;
	if(pos==1)
	{
		temp->next=head;
		head=temp;
	}
	else
	{
	pos=pos-2;
	while(pos--)
	iter=iter->next;

	temp->next=iter->next;
	iter->next=temp;
	}
	++size;
}

void InsertNodeAtBeg(Node* &head,int& size)
{
	int ele;
	cout<<"\nEnter element to insert at Beginning: ";
	cin>>ele;
	if(head==NULL)
	{
		head=new Node();
		head->data=ele;
		head->next=NULL;
	}
	else
	{
		Node* temp=new Node();
		temp->data=ele;
		temp->next=head;
		head=temp;
	}
	++size;
}


int main()
{
	Node* head=NULL;
	int size=0;
	int choice=1;
	cout<<"------LINKED LIST------\n";
	cout<<"1 for insertion at beginning\n2 for insertion at end\n3 for insertion at position\n0 for exit!\n";
	while(choice)
	{
		cout<<"\n\nEnter Choice : ";
		cin>>choice;
		if(choice==1)
   	InsertNodeAtBeg(head,size);	
   	
   	else if(choice==2)
   	InsertNodeAtEnd(head,size);
   	
   	else if(choice==3)
   	InsertNodeAtPos(head,size);
   	
   	printList(head);
}}