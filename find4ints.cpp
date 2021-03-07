#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if (nums.size()==0)return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i==0||nums[i]!=nums[i-1]){
            for(int j=i+1;j<nums.size()-1;j++){
                if(nums[j]!=nums[j-2]){
                int h=j+1,k=nums.size()-1;
                int sumCurr;
                while(h<k&&j<h){
                    sumCurr = nums[i]+nums[j]+nums[h]+nums[k];
                    if(sumCurr==target){
                        vector<int>v{nums[i],nums[j],nums[h],nums[k]};
                        ans.push_back(v);
                        while(j<h&&nums[j]==nums[j+1])j++;
                        while(h<k&&nums[h]==nums[h+1])h++;
                        while(h<k&&nums[k]==nums[k-1])k--;
                        
                        h++;k--;
                    }
                    if(sumCurr>target)k--;
                    if(sumCurr<target)h++;
                
                }}
            }}
        }
    return ans;}
};
int main(){
    Solution s;
    std::vector<int> v{0,2,2,2,2,2 };
    vector<vector<int>> a =s.fourSum(v,6); 
    return 0;
}