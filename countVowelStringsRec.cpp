class Solution {
public:
    int countVowelStrings(int n, int firstChar = 1) {
        if(n == 1)return 5 - firstChar +1;
        int ans = 0;
        for(int i = firstChar;i<=5;i++){
            ans +=countVowelStrings(n-1,i);
        }
        return ans;
        
    }
};
int main(){
    Solution s;
    s.countVowelStrings(3);
    return 0;
}