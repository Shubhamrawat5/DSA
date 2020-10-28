#include <iostream>
using namespace std;

//a tree like structure but for every characters there is a child
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


int main() 
{
	TrieNode* root=new TrieNode(); //root is never NULL in Trie DS, so initializing root with a TrieNode with all values NULL and false
	return 0;
}
