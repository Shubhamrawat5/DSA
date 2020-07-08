#include<iostream>
using namespace std;

class Node
{
	public:
	int data;
	Node* next;
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

void MergeList(Node* h1,Node* h2,int& s1,int& s2) //2 sorted list
{
	cout<<"\n\n-----Merge Sorted List :- ";
	
	if(h1==NULL) //if list 1 empty
	{
	printList(h2);
	return;
	}
	
	if(h2==NULL) //if list 2 empty
	{
	printList(h2);
	return;
	}
	
	Node* head=NULL; //head for merge list
	Node* iter=NULL; //to iterate in merge list
	while(h1!=NULL || h2!=NULL)
	{
		if(head==NULL) //for 1st time only to get value in head & storing min value btw two list
		{
			if(h1->data < h2->data)
			{
				iter=head=h1;
				h1=h1->next;
			}
			else
			{
				iter=head=h2;
			    h2=h2->next;
			}
		}
		else
		{
			if(h1==NULL) //list 1 becomes empty
			{
				iter->next=h2;
				break;
			}
			else if(h2==NULL) //list 2 become empty
			{
				iter->next=h1;
				break;
			}
			else if(h1->data < h2->data) //getting min value
			{
				iter->next=h1;
				h1=h1->next;
				iter=iter->next;
			}
			else
			{
				iter->next=h2;
				h2=h2->next;
				iter=iter->next;
			}
		}
		}
	printList(head);
}

int main()
{
	Node* h1=NULL;
	Node* h2=NULL;
	int s1=0,s2=0;
	int i=0;
	for(i=1;i<2221;i=i*3)
		InsertNodeAtEnd(h1,s1,i);
	
	for(i=1;i<11111;i=i*7)
		InsertNodeAtEnd(h2,s2,i);
	
	printList(h1);
	printList(h2);
	MergeList(h1,h2,s1,s2);
}

