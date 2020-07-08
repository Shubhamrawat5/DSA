#include<iostream>
using namespace std;

class Node
{
	public:
	int data;
	Node* next;
};

void PrintList(Node* &head)
{
	if(head==NULL)
	{
		cout<<"\nLL IS EMPTY !";
		return;
	}
	Node* iter=head;
	while(iter!=NULL)
	{
		cout<<iter->data<<" ";
		iter=iter->next;
	}
}


void PushNode(Node* &head,int ele)
{
	if(head==NULL)
		{
			head=new Node();
			head->data=ele;
			head->next=NULL;
		}
	else
		{
			Node* iter=head;
			while(iter->next!=NULL)
			iter=iter->next;
			
			Node* temp=new Node();
			temp->data=ele;
			temp->next=NULL;
			iter->next=temp;
		}
}

void CreateLoop(Node* &head)
{
	Node* iter=head;
	while(iter->next!=NULL)
	iter=iter->next;
	
	iter->next=head->next->next->next;
}


//used Floyd's algo of hare & tortoise
bool CheckLoop(Node* &head)
{
	Node* slow=head; //take 1 step
	Node* fast=head; //take 2 step
	bool isLoop=0;
	
	while(fast->next!=NULL && fast->next->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
		
		if(fast==slow) //means we're back to a node
		{
			isLoop=1;
			break;
		}
	}
	if(isLoop==0) return 0;
	
	Node* iter=head;
	while(iter!=slow) //to get the element where the loop is starting
	{
		iter=iter->next;
		slow=slow->next;
	}
	cout<<"\nLOOP IS STARTING WITH "<<iter->data;
	return 1;
}



int main()
{
	Node* head=NULL;
	
	for(int i=1;i<12;++i)
	PushNode(head,i);
	
	PrintList(head);
	
	CreateLoop(head);
//	PrintList(head); //infinte loop

  CheckLoop(head)?		   cout<<"\nLOOP!!":cout<<"\nNO LOOP!!";
}