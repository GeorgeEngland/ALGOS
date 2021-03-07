#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
    
    int dfs(int node,vector<vector<int>>& Nodes, vector<bool>& hasApple,vector<bool> &visited){
        int res = 0;
        visited[node]=true;
        for(auto to : Nodes[node]){
            if(!visited[to])
            res += dfs(to,Nodes,hasApple,visited);
        }
        
        
        return res>0 ? (res+2) : (hasApple[node]?2:0);
        
        
        
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> Nodes(n);
        vector<bool> visited(n,false);
        for(int i = 0; i<edges.size();i++){
            Nodes[edges[i][0]].push_back(edges[i][1]);
            Nodes[edges[i][1]].push_back(edges[i][0]);
        }
        
        
        int ans = dfs(0,Nodes,hasApple,visited);
        return ans-2 < 0 ? 0:ans-2;
    }
};
int main(){
    Solution s;
    vector<vector<int>> edges{{0,2},{0,3},{1,2}};
    vector<bool> hasApple{false,true,false,false};
    cout<<s.minTime(7,edges,hasApple);
}