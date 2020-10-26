#include<iostream>
#include<vector>
#include<queue>

using namespace std;

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

void BFS(vector<int> adjList[],int v,int s) //s is starting vertex
{
    //using a boolean array so that no vertex is printed again, also graph can be cyclic so without this array, we can go into a loop
    bool visited[v];
    for(int i=0;i<v;++i) visited[i]=false;
    
    queue<int> q;
    q.push(s);
    visited[s]=true;
    
    cout<<"\nBFS of vertex "<<s<<" is:-\n";
    while(q.size())
    {
        int currentVert=q.front();
        q.pop();
        cout<<currentVert<<" ";
        
        for(int x: adjList[currentVert])
            if(visited[x]==false)
            {
                visited[x]=true;   
                q.push(x);
            }
    }
    
}

int main() {
 	int v=5;
 	//using array of vector to show graph edges
 	vector<int> adjList[v]={{1,2},{0,2,3},{0,1,3,4},{1,2,4},{2,3}}; //adjList[i] shows all the vertex connected to the vertex i
	printList(adjList,v);
	
	/*Graph is like:
	
	    / 1 ---- 3 
	   0  |      |
	    \ 2----- 4
	
	*/
	
	BFS(adjList,v,0);
	return 0;
}
