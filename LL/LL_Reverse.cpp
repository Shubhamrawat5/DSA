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

void InsertNodeAtEnd(Node* &head,int& size,int ele)
{
//	int ele;
//	cout<<"Enter element to insert at end: ";
//	cin>>ele;
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

void ReverseList(Node* &head)
{
	if(head==NULL) return;
	
	Node* curr=head;
	Node* prev;
	Node* Next=head->next;
	
	while(Next!=NULL)
	{
		prev=curr;
		curr=Next;
		Next=Next->next;
		curr->next=prev;
	}
	head->next=NULL;
	head=curr;
}

int main()
{
	Node* head=NULL;
	int size=0;
	int choice=1;
	for(int i=0;i<10;i=i+10)
	InsertNodeAtEnd(head,size,i);
	
   printList(head);
   
   ReverseList(head);
   cout<<"\n\n----REVERSED LIST------ :-";
   printList(head);
   
}