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
	//values will be get in reversed order so using another stack
	stack<int> values;
	
	
	//Logic:-
	//Push root in stack1 then removing top of stack1 value in stack2 and push that top left and right children to stack1 and keep doing it
	//in end in stack2 there will be postorder
	st.push(root);
	
	while(!st.empty())
	{
		Node* curr=st.top(); //taking top of stack
		st.pop(); //removing top of stack
		values.push(curr->key); //pushing ans
		
		if(curr->left!=NULL) //if left child exist
			st.push(curr->left);
		if(curr->right!=NULL) //if right child exist
			st.push(curr->right);
	}
	
	while(values.size()) 
	{
		cout<<values.top()<<" ";
		values.pop();
	}
}