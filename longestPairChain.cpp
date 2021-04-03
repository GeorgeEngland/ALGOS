#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        vector<int> chainLengths(pairs.size(),0);
        int maxLength = 1;
        chainLengths[0]=1;
   
        for(int i = 1; i<pairs.size();i++){
            //find max of previous chain lengths
            int localMax = 0;
            for(int j = 0;j<i;j++){
                if(chainLengths[j]>localMax && pairs[i][0]>pairs[j][1])localMax = chainLengths[j];
            }
            
            //length = 1+ max(chainlength of previous nodes where b<c)
            chainLengths[i] = 1 + localMax;
            if(chainLengths[i]>maxLength)maxLength = chainLengths[i];
        }
        
        
        return maxLength;
    }
};
int main(){
    return 0;
}