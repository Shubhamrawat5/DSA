#include <iostream>
#include<vector>
using namespace std;

bool DFSRec(vector<int> adjList[],bool visited[],int V,int source,int parent)
{
    visited[source]=true;
    for(int i=0;i<adjList[source].size();++i)
    {//checking each adjacent vertex
        if(visited[adjList[source][i]]==false)//if vertex is not visited then call DFS for it
        {    
            if(DFSRec(adjList,visited,V,adjList[source][i],source)) return true;
        }
        
        else if(adjList[source][i] != parent) return true; //if vertex was visited and this visited vertex is not the parent vertex then cycle is there
    }
    return false;
}

bool isCyclic(vector<int> adjList[],int V)
{
    bool visited[V]; 
    int i;
    for(i=0;i<V;++i) 
    {
        visited[i]=false;
    }
    
    for(i=0;i<V;++i) //graph can be disconnected so calling for every vertex which is not visited
    {
        if(visited[i]==false) if(DFSRec(adjList,visited,V,i,-1)) return true; //if cycle found return true
    }
    return false;
}

void printList(vector<int> adjList[],int v)
{
    cout<<"Printing Adjacency List:-\n";
    for(int i=0;i<v;++i)
    {
        for(int j=0;j<adjList[i].size();++j)
        {
            cout<<adjList[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main() {
	int V=6;
	vector<int> adjList[V]={{1},{0,2,3},{1,4},{1,4,5},{2,3},{3}};
	/*
	           0
	         /  
	        1 - - -3
	        |     / \
	        2 - -4   5
	*/
    printList(adjList,V);
	if(isCyclic(adjList,V)) 
	    cout<<"\nCycle is present!";
	else
	    cout<<"\nCycle is not present!";
	return 0;
}
