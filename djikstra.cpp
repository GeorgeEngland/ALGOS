#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
#define MAX_SIZE 7


void display(int dist[MAX_SIZE],int parent[MAX_SIZE],int V, int src,int cost[MAX_SIZE][MAX_SIZE]){

    for (size_t i = 0; i < V; i++)
    {
        int d = dist[i];
        int currNode = i;
        cout<<"Distance: "<<d<<". ";
        while(parent[currNode]!=-1){
            cout<<currNode<<" <- ("<<cost[currNode][parent[currNode]]<<") <- ";
            currNode=parent[currNode];
        }
        cout<<currNode<<endl;
    }
}

void initialiseCostMatrix(int (&cost)[MAX_SIZE][MAX_SIZE],int V){
for (size_t i = 0; i < V; i++)
    {
        for (size_t j = 0; j < V; j++)
        {
            cin>>cost[i][j];
        }  
    }
}

int getNextNode(int cost[MAX_SIZE][MAX_SIZE],bool (&visited)[MAX_SIZE],int currNode,int V,int (&dist)[MAX_SIZE]){
    int minDist = 999;
    int nextNode = currNode;
    for (size_t i = 0; i < V; i++)
    {
        if(dist[i]<minDist && !visited[i]){
            minDist = dist[i];
            nextNode=i;
        }
    }
    return nextNode;
    
}

void djikstra(int src,int V,int (&cost)[MAX_SIZE][MAX_SIZE]){
    //total dist travelled, parent matrix
    int dist[MAX_SIZE],parent[MAX_SIZE];
    // visited matrix
    bool visited[MAX_SIZE]={0};
    int nodeCount=0;
    int nextNode = src;
    

    fill(dist,dist+V,999);

    //initialise at soruce point
    parent[src]=-1;
    dist[src]=0;
    visited[src]=true;
    while(nodeCount<V){
        //Find unvisited point with the smallest distance
        nextNode = getNextNode(cost,visited,nextNode,V,dist);
        cout<<"Next Node: "<<nextNode<<endl;
        //mark as visited
        visited[nextNode]=true;
        for (size_t i = 0; i < V; i++)
        {
            //if edges from this path reduce dists of other nodes && node is reachable
            if( (dist[nextNode]+cost[nextNode][i])<dist[i] &&cost[nextNode][i]!=999)
            {
                //update the parent of the node and the node distance 
                parent[i]=nextNode;
                dist[i]=dist[nextNode]+cost[nextNode][i];
                
            }
        } 
        nodeCount++;  
    }
    display(dist,parent,V,src,cost);
    


}

int main(){
    // nodes, start node, adj matrix, best parent of nodes
    int V, src,cost[MAX_SIZE][MAX_SIZE];
    
    cout<<"Number of Nodes:"<<endl;
    cin>>V;
    cout<<"Thanks. Graph:"<<endl;;
    initialiseCostMatrix(cost,V);
    cout<<"Thanks. start Node:"<<endl;
    cin>>src;

    djikstra(src,V,cost);
    
    return 0;
}
/*
0   1   2   3   4   5   6   */
/*
0   4   2   999 999 999 999
4   0   1   1   3   999 999
2   1   0   999 2   1   999
999 1   999 0   2   999 2
999 3   2   2   0   1   7
999 999 1   999 1   0   9
999 999 999 2   7   9   0
*/ 