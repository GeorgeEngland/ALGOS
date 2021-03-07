#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums){
         vector<vector<int>> ans;
        if(nums.size()==0)return ans;
        sort(nums.begin(),nums.end());
        for(auto it: nums){
            std::cout<<it<<", ";
        }
        for(int i=0;i<nums.size();i++){
                    if(i==0 || nums[i]!=nums[i-1]){

            int j = i+1, k = nums.size()-1;
            while(j<k){
                int sumCurr = nums[i]+nums[j]+nums[k];
                if(sumCurr==0){
                    std::vector<int> v{nums[i],nums[j],nums[k]};
                    ans.push_back(v);
                    while(j<k&&nums[j]==nums[j+1])j++;
                    while(j<k&&nums[k]==nums[k-1])k--;
                    j++;k--;
                    

                }
                
                if(sumCurr>0)k--;
                if(sumCurr<0) j++;
            }

        }
        }
        return ans;
    }
};
int main(){
    Solution s;
    std::vector<int> v{-4,-4,-3,-2,-1,0,2};
    vector<vector<int>> a =s.threeSum(v ); 
    return 0;
}