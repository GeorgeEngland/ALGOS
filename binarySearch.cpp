#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
    int dfs(vector<int> &nums, int start,int end,int target){
        int ans = -1;
        int mid = (start+end)/2;
        
        if(end<start)return -1;
        
        if(nums[mid]==target)return mid;
        
        if(nums[mid]<target){
            auto first = nums.begin();
            auto last = nums.begin() + end;
            ans= dfs(nums,mid+1,end,target);
        }
        
        if(nums[mid]>target){
            auto first = nums.begin();
            auto last = nums.begin() + end;
            ans= dfs(nums,start,mid-1,target);
        }
        
        return ans;
        
    }
public:
    int search(vector<int>& nums, int target) {
        return dfs(nums,0,nums.size()-1,target);
    }
};