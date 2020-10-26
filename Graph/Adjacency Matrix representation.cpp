#include <iostream>
#define v 4

using namespace std;

/*
Undirected Graph:

   0 ---- 1 ---- 3
    \   /
      2

*/

void addEdge(bool adjMatrix[v][v],int v1,int v2)
{
    //as this is a undirected graph so v1 to v2 is present so v2 to v1 also connection present
    adjMatrix[v1][v2]=true;
    adjMatrix[v2][v1]=true;
}

void printMatrix(bool adjMatrix[v][v])
{
    cout<<"Printing adjacency matrix:-\n";
    for(int i=0;i<v;++i)
    {
        for(int j=0;j<v;++j)
        {
            cout<<adjMatrix[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main() {
 	bool adjMatrix[v][v]; //adjMatrix[m][n] is true means vertex m to n is a connection
	
	for(int i=0;i<v;++i)
	    for(int j=0;j<v;++j)
	        adjMatrix[i][j]=false;
	        
	addEdge(adjMatrix,0,1);
	addEdge(adjMatrix,0,2);
	addEdge(adjMatrix,1,2);
	addEdge(adjMatrix,2,3);
	
	printMatrix(adjMatrix);
	return 0;
}
