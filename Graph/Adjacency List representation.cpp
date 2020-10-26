#include<iostream>
#include<vector>
using namespace std;

/*
Undirected Graph:

   0 ---- 1 ---- 3
    \   /
      2

*/

void addEdge(vector<int> adjList[],int v1,int v2)
{
    //as this is a undirected graph so v1 to v2 is present so v2 to v1 also connection present
    adjList[v1].push_back(v2);
    adjList[v2].push_back(v1);
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
 	int v=4;
 	//using array of vector to show graph edges
 	vector<int> adjList[v]; //adjList[i] shows all the vertex connected to the vertex i
	        
	addEdge(adjList,0,1);
	addEdge(adjList,0,2);
	addEdge(adjList,1,2);
	addEdge(adjList,1,3);
	
	printList(adjList,v);
	return 0;
}
