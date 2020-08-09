#include<iostream>
#include<queue>
using namespace std;

typedef struct Node //typedef is automatic in c++
{
	int key;
	struct Node* left,*right;
	Node(int x)
	{
		key=x;
		left=right=NULL;
	}
}Node;

void findinsert(Node* root,int key)
{
	queue<Node *> q;
	q.push(root);  //using queue for breath first search
	
	while(!q.empty()) 
	{
		root=q.front();
		q.pop();
		if(root->left==NULL)
		{
			root->left=new Node(key);
			return;
		}
		else if(root->right==NULL)
		{
			root->right=new Node(key);
			return;
		}
		else //when both left right children are available
		{
			q.push(root->left);
			q.push(root->right);
		}
	}
}

void insert(Node* &root,int key) //inserting node
{
	if(root==NULL) //empty
		root=new Node(key);
	
	else 	
		findinsert(root,key);
}

void inorder(Node *root) //recursive inorder
{
	if(root)
	{
		inorder(root->left);
		cout<<root->key<<" ";
		inorder(root->right);
	}
}

Node* findPre(Node* node) //To find predecessor of current node
{
	Node *temp=node->left; //always on left side, this will never be NULL as in morrisInorder function first if statement is taking care of(node->left == NULL)
	
	for(;temp->right && temp->right!=node;temp=temp->right);
	//to get predecessor in both cases, when there was a chain(temp->right!=node, when no chain was there(temp->right==NULL)
	
	return temp;
}

void morrisInorder(Node *root) //morris inorder
{
	while(root)
	{
		if(root->left==NULL) //if left child not exist then root is printed in inorder
		{
			cout<<root->key<<" ";
			root=root->right;
		}
		else 
		{
			Node* predecessor=findPre(root); //get the predecessor 
			
			if(predecessor->right) //to break the chain
			{
				predecessor->right=NULL;
				cout<<root->key<<" ";
				root=root->right;
			}
			else //to make a chain from predecessor to root
			{
				predecessor->right=root;
				root=root->left;
			}
		}
	}
	
}


void main()
{
	Node* root=NULL;
	int a[]={8,5,6,23,96,24,99,14,53,3,2};
	int n=sizeof(a)/sizeof(a[0]);
	for(auto k:a) //inserting elements in a sequence (level wise)
		insert(root,k);
		
	cout<<"By Recursively inorder :-\n";
	inorder(root); 
	
	cout<<"\n\nBy Morris inorder :-\n";
	morrisInorder(root);
}