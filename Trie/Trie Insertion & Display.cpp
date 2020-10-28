#include <iostream>
using namespace std;

struct TrieNode
{
    bool isEnd;
    TrieNode* child[26]; //for 26 small alphabets only
    TrieNode()
    {
        isEnd=false;
        for(int i=0;i<26;++i)
            child[i]=NULL;
    }
};

void insert(TrieNode* root,string s)
{
    for(int i=0;i<s.length();++i)
    {
        int c=s[i]-'a'; //0 to 25
        if(root->child[c]==NULL) //node is not present
        {
            root->child[c]=new TrieNode();
        }
        root=root->child[c]; //moving to child node of current character
    }
    root->isEnd=true; //marking this end node as the end of a word
}


void helperDisplay(TrieNode* root,string curr)
{
    if(root->isEnd==true) cout<<curr<<" "; //if this node is a end of a word
    for(int i=0;i<26;++i) //checking for every character child
    {
        if(root->child[i]!=NULL) 
        {
            helperDisplay(root->child[i],curr+char(97+i));
        }
    }
}

void display(TrieNode* root)
{
    cout<<"Printing available words in Trie:-\n";
    helperDisplay(root,"");
}


int main() {
	TrieNode* root=new TrieNode(); //root is never NULL in Trie DS 
	insert(root,"bat");
	
	insert(root,"bad");
	
	insert(root,"ba");
	
	insert(root,"batsman");
	
	insert(root,"mat");
	
	insert(root,"matter");
	
	insert(root,"must");
	
	insert(root,"mud");

	display(root); //printing of trie content are always in lexicographical order
	
	return 0;
}
