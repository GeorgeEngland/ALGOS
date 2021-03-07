#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height){
        //[ 1, 2, 6, 2, 4, 5, 7, 8]
        int l = 0, r =height.size()-1, max_a = 0;
        while (l<r){
            int lh = height[l];
            int rh = height[r];
            max_a = std::max(max_a,(r-l)*min(lh,rh));
            if(lh<rh)++l;
            else --r;
        }
        
        return max_a;
    }
};
int main(){
    Solution s;
    std::vector<int> v{1,8,6,2,5,4,8,3,7};
    std::cout<<s.maxArea(v );
    return 0;
}