#include<iostream>
#include<queue>

using namespace std;

struct Node
{
	int key;
	Node *left,*right;
	Node(int key)
	{
		this->key=key;
		left=right=NULL;
	}
	
};

//recursively calling for both the children and counting parent as 1 (1 + left + right)
int sizeRec(Node *root)
{
	if(root==NULL)
		return 0;
		
	else 
		return 1+sizeRec(root->left)+sizeRec(root->right);
}

//using a queue, pushing firstly the root then children to the queue and also after pushing children poping the parent(parent at front of queue) and counting the children if available
int sizeIte(Node *root)
{
	if(root==NULL) return 0;
	
	queue<Node *> q;
	q.push(root);
	int size=1;
	while(!q.empty())
	{
		if(q.front()->left)
		{
			q.push(q.front()->left);
			++size;
		}
		if(q.front()->right)
		{
			q.push(q.front()->right);
			++size;
		}
		q.pop();
	}
	return size;
}

int main()
{
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);
	root->right->left=new Node(60);
	
	cout<<"Binary Tree size by recursion:-\n";
	cout<<sizeRec(root);
	
	cout<<"\n\nBinary Tree size by iterative-\n";
	cout<<sizeIte(root);
}