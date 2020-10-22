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

Node* search(Node* root,int val)
{
    //using BST property, left child is smaller value and right side is bigger
    while(root)
    {
        if(root->key==val) 
        {
            //cout<<val<<" is found in BST!\n";
            return root;
        }
        if(root->key < val) root=root->right; //value is bigger so it might be in right subtree
        else root=root->left;
    }
    return NULL;
    //cout<<val<<" is not found in BST!\n";
}

void findPreSuc(Node* root,int val,int& pre,int& suc)
{
    if(root==NULL) return;
    
    if(root->key==val)
    {
        //for predecessor
        Node* temp=root->left;
        while(temp && temp->right) temp=temp->right;
        if(temp!=NULL) pre=temp->key;
        
        //for successor
        temp=root->right;
        while(temp && temp->left) temp=temp->left;
        if(temp!=NULL) suc=temp->key;
    }
    else if(root->key < val)
    {
        pre=root->key;
        findPreSuc(root->right,val,pre,suc);
    }
    else
    {
        suc=root->key;
        findPreSuc(root->left,val,pre,suc);
    }
}

Node* preOfRoot(Node* root) //left child rightest node is the predecessor of root
{
    if(root->left==NULL) return NULL; //no smaller value in tree than root value
    root=root->left;
    while(root!=NULL && root->right!=NULL) root=root->right;
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
    cout<<"\n";
    
    int suc,pre,n;
    n=5;
    findPreSuc(root,n,pre,suc);
    cout<<n<<" predecessor is "<<pre<<" and successor is "<<suc;
    
    cout<<"\n";
    
    n=9;
    findPreSuc(root,n,pre,suc);
    cout<<n<<" predecessor is "<<pre<<" and successor is "<<suc;
    
    cout<<"\n";
    
    Node* predecessorOfRoot=preOfRoot(root);
    if(predecessorOfRoot!=NULL) cout<<"Predecessor of Root is "<<predecessorOfRoot->key;
	return 0;
}
