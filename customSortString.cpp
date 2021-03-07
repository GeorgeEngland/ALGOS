#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    string customSortString(string S, string T) {
        string ans = T;
        unordered_map<char,int> lets;
        for(auto it : T){
            if(lets.find(it)==lets.end())lets.insert({it,1});
            else lets[it]++;
        }
        int j = T.size()-1;
        for (int i = S.size()-1;i>=0;i--){
            if(lets.find(S[i])==lets.end()){
                }
            else{
                while(lets[S[i]]>0){
                    ans[j]=S[i];
                    lets[S[i]]--;
                    j--;
                }
            }
        }
        for(auto it : T){
            while(lets[it]>0)
            {
                ans[j]=it;
                lets[it]--;
                j--;
            }
        }


        if(T.size()==1)return T;
        
        
    return ans;
}};
int main(){
    Solution s;
    s.customSortString("cba","abcd");
    return 0;
}