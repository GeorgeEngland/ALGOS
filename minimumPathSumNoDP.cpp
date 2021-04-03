#include <vector>
using namespace std;
class Solution {
public:
    
    int dfs(int i, int j,vector<vector<int>>& grid){
        if(i<0 || j < 0)return 999999;
        if(i==0 && j ==0)return grid[0][0];
        
        int leftPath = dfs(i-1, j, grid) + grid[j][i];
        int topPath = dfs(i, j-1,grid) + grid[j][i];
        return topPath < leftPath ? topPath : leftPath;
        
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> pathLengths = grid;
        
        int length = dfs(grid[0].size()-1,grid.size()-1,grid);
        return length;
    }
};

