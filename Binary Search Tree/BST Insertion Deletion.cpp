#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node* left,*right;
    Node(int x)
    {
        key=x;
        left=right=nullptr;
    }
};

Node* insert(Node* root,int x) //insertion in BST is always in leaf node
{
    if(root==NULL) //time to craete the node as we have reached a leaf end
    {
        root=new Node(x);
        return root;
    }
    if(root->key < x)   //value is larger so it has to go in right subtree
        root->right=insert(root->right,x);
    else if(root->key > x) //value is smaller so it has to go in left subtree
        root->left=insert(root->left,x);
    return root;
}

Node* getPredecessor(Node* curr) //left child and its rightest diagonal,needed for delete operation
{
    curr=curr->left;
    while(curr && curr->right) curr=curr->right; 
            
    return curr;
}
    
Node* remove(Node* root, int val) 
{
    if(root==NULL) return root;
        
    if(root->key < val) root->right=remove(root->right,val);
    else if(root->key > val) root->left=remove(root->left,val);
    else //found.. 3 possibilities.. left child doesnt exist. right child doesnt exist, both exist
    {
        if(root->left==NULL) //left doesnt exist (also if both dont exist)
        {
            Node* temp=root->right;
            delete(root);
            return temp;
        }
        else if(root->right==NULL) //right child doesnt exist
        {
            Node* temp=root->left;
            delete(root);
            return temp;
        }
        else //both child exist 
        {
            Node* pre=getPredecessor(root); //find the predecessor of current element as if we swap with it then whole BST will remain a BST but just that last leaf node we have to delete now
            swap(root->key,pre->key);
            root->left=remove(root->left,val);
        }
    }
    return root;
}
    
void displayInorder(Node* root)
{
    if(root==NULL) return;
    //doing inorder travsersal of binary tree, in BST inorder is always in sorted form
    displayInorder(root->left);
    cout<<root->key<<" ";
    displayInorder(root->right);
}

int main() {
	Node *root=NULL;
	root=insert(root,5);
	root=insert(root,10);
	root=insert(root,7);
	root=insert(root,1);
	root=insert(root,3);
	root=insert(root,9);
	cout<<"Current BST is\n";
	
	displayInorder(root);
	
	root=remove(root,5);
	root=remove(root,0); //doesnt exist
	root=remove(root,10);
	
	cout<<"\nCurrent BST is\n";
	displayInorder(root);
	return 0;
}
