#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
unordered_map<char,string> direc = {
    {'2',"abc"},
    {'3',"def"},
    {'4', "ghi"},
    {'5',"jkl"},
    {'6',"mno"},
    {'7',"pqrs"},
    {'8',"tuv"},
    {'9',"wxyz"}
};


class Solution {
private:
vector<string> solve(vector<string> &str1,string str2){
    vector<string> ans;
    
    for (auto it : str1){
        for(auto it2 : str2){
            ans.push_back(it+it2);
        }
    }
    return ans;
}
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        if(digits.length()<1)return ans;
        int n = digits.size();
        char beg = digits[0];
        for(auto it: direc[beg]){
            ans.push_back(string(1,it));
        }
        for (int i=0;i<n;i++){
            ans=solve(ans,direc[digits[i]]);
        }
        return ans;
    }
};
int main(){
    Solution s;
    s.letterCombinations("23234231237129334245");
    cout<<"done";
    return 0;
}



/*
[2,3]
       2
    /  |  \
   [a   b   c]
   |     |      | 
  3     3       3
 /|\   /|\     /|\
 [def] [def] [def]




*/