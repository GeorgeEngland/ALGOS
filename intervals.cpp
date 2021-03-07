#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> res(intervals.size());
        
        vector<pair<int,int>> pos;
        //start, position
        for (int i = 0;i<intervals.size();i++){
            pos.push_back({intervals[i][0],i});
        }
        sort(pos.begin(),pos.end());
        for(int i = 0;i<intervals.size();i++){
            auto index = lower_bound(pos.begin(),pos.end(),intervals[i][1],
                                   [](auto it, auto val){
                                       return it.first<val;
                                   });
            res[i]=index == pos.end() ? -1 : index->second;
        }
        return res;
    }
};