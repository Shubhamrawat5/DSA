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

void DeleteNodeAtBeg(Node* &head,int& size)
{
	if(head==NULL)
	{
		cout<<"\nNo element in list !\n";
		return;
	}
	else
	{
		Node* temp=head;
		head=head->next;
		free(temp);
	}
	--size;
}

void DeleteNodeAtEnd(Node* &head,int& size)
{
	if(head==NULL)
	{
		cout<<"\No element in list !\n";
		return;
	}
	
	if(size==1) // 1 element
	{
		Node* temp=head;
		head=NULL;
		free(temp);
	}
	else
	{
		Node* iter=head;
		while(iter->next->next!=NULL)
		iter=iter->next;
		
		Node* temp=iter->next;
		iter->next=NULL;
		free(temp);		
	}
	--size;
}

void DeleteNodeAtPos(Node* &head,int& size)
{
	if(head==NULL)
	{
		cout<<"\No element in list !\n";
		return;
	}
	else
	{
		cout<<"\nEnter element position 1 to "<<size<<" to delete : ";
		int pos;
		cin>>pos;
		
		if(pos<1 || pos>size)
		{
			cout<<"\nINVALID POSITION!";
			return;
		}
		
		if(pos==1)
		DeleteNodeAtBeg(head,size);
		else if(pos==size)
		DeleteNodeAtEnd(head,size);
		
		else{
		Node* iter=head;
		pos=pos-2;
		
		while(pos--)
		iter=iter->next;
		
		Node* temp=iter->next;
		iter->next=temp->next;
		free(temp);
		--size;
	}
	}
}

int main()
{
	Node* head=NULL;
	int size=0;
	int choice=1;
	for(int i=0;i<50;i=i+10)
	InsertNodeAtEnd(head,size,i);
	
	
	cout<<"------LINKED LIST------\n";
	cout<<"1 for deletion at beginning\n2 for deletion at end\n3 for deletion at position\n0 for exit!\n\n";
	printList(head);
	while(choice)
	{
		cout<<"\n\nEnter Choice : ";
		cin>>choice;
		if(choice==1)
   	DeleteNodeAtBeg(head,size);	
   	
   	else if(choice==2)
   	DeleteNodeAtEnd(head,size);
  
   	
   	else if(choice==3)
   	DeleteNodeAtPos(head,size);
   
   	printList(head);
}}