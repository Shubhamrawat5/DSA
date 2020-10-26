#include <iostream>
#include<vector>
using namespace std;

void DFSRec(vector<int> adjList[],bool visited[],int V,int source)
{
    cout<<source<<" ";
    visited[source]=true;
    for(int i=0;i<adjList[source].size();++i) //checking each adjacent vertex
        if(visited[adjList[source][i]]==false) //if vertex is not visited then call DFS for it
            DFSRec(adjList,visited,V,adjList[source][i]);
}


void DFS(vector<int> adjList[],int V) 
{
    bool visited[V];
    int i;
    for(i=0;i<V;++i) visited[i]=false;
    
    cout<<"\nDFS of graph is: \n";
    for(i=0;i<V;++i) //graph can be disconnected so calling for every vertex which is not visited
    {
        if(visited[i]==false) DFSRec(adjList,visited,V,i);
    }
    
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
	int V=8;
	vector<int> adjList[V]={{1,4},{0,2},{1,3},{2},{0,5,6},{4,6,7},{4,5,7},{5}};
	/*
	           0
	         /   \ 
	        1      4
	        |     / \
	        2    5 - 7
	        |    |
	        3    6
	*/
    printList(adjList,V);	
	DFS(adjList,V);
	return 0;
}
