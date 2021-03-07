#include <iostream>
#include <string>



class Solution {
public:
    bool isPalindrome(int64_t x) {
        std::string s=std::to_string(x);
        int length = s.length();
        for (int i = 0; i < length/2; i++)
        {
            if(s[i]!=s[length-i-1])
            return false;
        }
        
        return true;
    }
};
int main(){
    Solution s;
    int64_t input;
    std::cin>>input;
    std::cout<<s.isPalindrome(input)<<std::endl;
    return 0;
}