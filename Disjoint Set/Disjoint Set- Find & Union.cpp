#include <iostream>
#define n 5
#define endl '\n'
using namespace std;

int parent[n]; //to know the parent of the element

void initialize()
{
    for(int i=0;i<n;++i) //initializing every element parent to itself
    {
        parent[i]=i;
    }
}

int find(int x) //used to find the representative of the tree (disjoint set) of x element
{
    if(parent[x]==x) //as root element parent will be itself so if this condition is true means root element it is! (representative of this disjoint set)
        return x;
    else //otherwise go to the parent element
        return find(parent[x]);
}

void DoUnion(int x,int y)
{
    int xRep=find(x);
    int yRep=find(y);
    if(xRep==yRep) return; //both x and y are of same tree (disjoint set)
    parent[yRep]=xRep; //changing y's tree root element parent to x's tree root element    
}

/*

Disjoint set:
Two types of operations:-
1) find(x) 2) union(x,y)

we create a parent array to represent different trees of array, each tree will represent a disjoint set
each tree will have its representative which will be the root element.
*/

int main() {
    int arr[n]={0,1,2,3,4};
    
    initialize();
    
    //parent = [0,1,2,3,4] each node is parent to itself initialially
    //disjoint set (trees) = [0] [1] [2] [3] [4] 
    
    cout<<find(4)<<endl;
    cout<<find(2)<<endl<<endl;
    
    DoUnion(2,4);
    //now disjoint set (trees) will become like
    // [0] [1] [2 4] [3]
    // parent = [0,1,2,3,2] 
    
    DoUnion(0,1);
    // disjoint set = [0 1] [2 4] [3]
    // parent = [0,0,2,3,2]
    
    DoUnion(0,3);
    // disjoint set = [0 1 3] [2 4]
    // parent = [0,0,2,0,2]
    
    cout<<find(4)<<endl;
    cout<<find(2)<<endl;
    cout<<find(3)<<endl;
	return 0;
}
