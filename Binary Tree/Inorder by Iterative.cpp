#include<iostream>
#include<stack>

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

int main()
{
	//creating a tree
	Node* root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(50);
	root->left->left=new Node(40);
	root->left->right=new Node(30);
	
	stack<Node *> st; //stack of Node pointers
	Node* curr=root; //curr pointer which will iterate
	
	while(curr!=NULL || !st.empty())
	{
		while(curr!=NULL) //going left until reached null, (this condition is also stopping infinite loop)
		{
			st.push(curr);
			curr=curr->left;		
		}
		
		curr=st.top(); //top of the stack will be a leaf node if printed nodes are ignored 
		cout<<(curr->key)<<" ";
		st.pop();
		curr=curr->right; //now moving to right sub tree
	}
}