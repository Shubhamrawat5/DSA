#include <iostream>
#define n 5
#define endl '\n'
using namespace std;

int parent[n]; //to know the parent of the element
int rankk[n]; //to know the maximum height of a tree //rank named present already for something so using rankk
//Note: rank of a element in a disjoint set is considered the rank value for root element
void initialize()
{
    for(int i=0;i<n;++i) //initializing every element parent to itself
    {
        parent[i]=i;
        rankk[i]=0;
    }
}

/* orginal function:-
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
*/

int find(int x)
{
    if(x==parent[x]) //root element
        return x;
        
    parent[x]=find(parent[x]); //setting each element parent = root element ,of all the element coming in the path
    return parent[x];
}

void DoUnion(int x,int y)
{
    int xRep=find(x);
    int yRep=find(y);
    
    if(xRep==yRep) return; //both x and y belongs to same disjoint set
    
    //put the smaller tree into bigger tree
    if(rankk[xRep] < rankk[yRep]) //x element tree is smaller
        parent[xRep]=yRep;
    else if(rankk[xRep] > rankk[yRep])
        parent[yRep]=xRep;
    else //both have equal heights
    {
        parent[yRep]=xRep; //changing y's tree root element parent to x's tree root element    
        rankk[xRep]++; //as y is attached to x tree so rank of x will be considered for this new tree, also height will be increase by 1 
    }
}

/* 2 optimization
1) Union by rank:-
As in previous method worst TC can be O(n) as the tree can be formed linear fashion like a chain because we were always puttinh 2nd tree on 1st tree 
(was making 2nd element representative to 1st element representative)
But now to get a uniform fashion tree we will calulate height and based on the height of both disjoint set, we will put smaller tree into bigger tree
Now TC will be O(logn)

2) Path compression:-
instead of following a long path to get the representative from find(x) function, we will set each element's parent = root element, so that parent can be found very fast
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
