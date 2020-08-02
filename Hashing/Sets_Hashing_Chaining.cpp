/*Hashing collision techniques:
1) Chaining
2) open addressing
	2.1) Linear probing
	2.2) Quadratic probing
	2.3) Double Hashing
*/

#include<iostream>
#include<list>
using namespace std;

//Chaining method by list STL
struct MyHash
{
	int bucket; //size of hash table
	list<int> *table; //table pointer 
	MyHash(int bucket)
	{
		table=new list<int>[bucket]; //created an array of doubly linked list
		this->bucket=bucket;
	}
	
	int hash(int key) //hash function
	{
		return key%bucket;
	}
		
	bool searchKey(int key)
	{
		int i=hash(key); //getting index
		for(auto x:table[i]) //traversing linked list of i index
			if(x==key) return 1;
			
		return 0;		
	}
	
	void insertKey(int key)
	{
		int i=hash(key);
		table[i].push_back(key); //inserting in the end of linked list of index i with push_back function
	}
	
	void deleteKey(int key)
	{
		int i=hash(key);
		table[i].remove(key); //removing from linked list of index i with remove function
	}
};

int main()
{
	MyHash h(7);
	h.insertKey(50);
	h.insertKey(21);
	h.insertKey(58);
	h.insertKey(17);
	h.insertKey(15);
	h.deleteKey(17);
	h.insertKey(49);
	cout<<h.searchKey(17);
}