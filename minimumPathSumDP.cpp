#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    
    int dfs(int i, int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i<0 || j < 0)return 999999;
        if(i==0 && j ==0)return grid[0][0];
        int minimum = dp[j][i];
        if(dp[j][i]==grid[j][i]) {
            minimum = min(dfs(i-1, j, grid, dp) + grid[j][i],dfs(i, j-1,grid,dp) + grid[j][i]);
            dp[j][i]=minimum;              
            }     
        return minimum;  
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> pathLengths = grid;
        vector<vector<int>> dp = grid;
        int length = dfs(grid[0].size()-1,grid.size()-1,grid,dp);
        return length;
    }
};
int main(){
    Solution s;
    vector<vector<int>> input{{1,2,3},{4,5,6}};
    cout<<s.minPathSum(input);
}

