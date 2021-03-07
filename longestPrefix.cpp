#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pref = "";
        char testpref;
        for (int i = 0;i<200;i++){
            if(strs.size()==0)return pref;

            testpref = strs[0][i];
         for (int j = 0;j<strs.size();j++){
                if(i==strs[j].size()){
                    return pref;
                }
                if(testpref!=strs[j][i]){
                    return pref;
                }
            }
            pref=pref+testpref;
        }
        return pref;
        
    }
};
int main(){
    Solution s;
    string str = "helo";
    string str2 = "hello123";
    vector<string> v{};
    cout<<s.longestCommonPrefix(v);
    return 0;
}