#include <iostream>
#include<vector>
using namespace std;

bool DFSRec(vector<int> adjList[],bool visited[],bool currPath[],int V,int source)
{
    //marking current vertex in both boolean array
    visited[source]=true;
    currPath[source]=true;
    
    for(int i=0;i<adjList[source].size();++i)
    {//checking each adjacent vertex
        if(currPath[adjList[source][i]]==false)//if vertex is not visited then call DFS for it
        {    
            if(DFSRec(adjList,visited,currPath,V,adjList[source][i])) return true;
        }
        
        else return true; //if vertex is in current path then cycle is there
    }
    
    currPath[source]=false; //removing current vertex from path as ahead of this path is already processed in above loop
    return false;
}

bool isCyclic(int V,vector<int> adjList[])
{
    bool visited[V],currPath[V]; //using 2nd bool array to know the current path and if a vertex come which was already earlier in the path then cycle is there
    int i;
    for(i=0;i<V;++i) 
    {
        currPath[i]=false;
        visited[i]=false;
    }
    
    for(i=0;i<V;++i) //graph can be disconnected so calling for every vertex which is not visited
    {
        if(visited[i]==false) if(DFSRec(adjList,visited,currPath,V,i)) return true; //if cycle found return true
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
	int V=4;
	vector<int> adjList[V]={{1},{},{3},{2}; //directed graph
	/* 
	        0 - > 1             2 < - > 3
	*/
    printList(adjList,V);
	if(isCyclic(adjList,V)) 
	    cout<<"\nCycle is present!";
	else
	    cout<<"\nCycle is not present!";
	return 0;
}
