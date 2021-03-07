#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> a;
        int num = 1;
        std::vector<std::vector<int>> matrix;
        matrix.resize(n, std::vector<int>(n, 0));
        int direction = 0;
        int i=0,j=0;
        while(num<n*n){
             switch (direction%4)
                {
                case 0:
                    while(i<n&&i>=0&&matrix[i][j]==0){
                        cout<<"her";
                        matrix[i][j]=num;
                        num++;
                        i++;
                    }
                    i--;
                    j++;
                    break;
                case 1:
                 while(j<n&&j>=0&&matrix[i][j]==0){
                    matrix[i][j]=num;
                    num++;
                    j++;
                    }
                    j--;
                    i--;
                    break;
                     
                case 2:
                    while(i<n&&i>=0&&matrix[i][j]==0){
                    matrix[i][j]=num;
                    num++;
                    i--;
                    }
                    i++;
                    j--;
                    break;
                case 3:
                    while(j<n&&j>=0&&matrix[i][j]==0){
                    matrix[i][j]=num;
                    num++;
                    j--;
                    }
                    j++;
                    i++;
                    break;
             }
            direction++;            
        }
        return matrix;
    }
};
int main(){
    Solution s;
    s.generateMatrix(3);
}