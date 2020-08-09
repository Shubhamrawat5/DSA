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
	st.push(root);
	
	//using breadth first technique with stack
	//pushing root then right then left
	while(!st.empty())
	{
		Node* curr=st.top();
		st.pop();
		cout<<curr->key<<" ";
		
		if(curr->right) st.push(curr->right);
		if(curr->left) st.push(curr->left);		
	}
}