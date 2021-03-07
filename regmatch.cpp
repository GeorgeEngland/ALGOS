#include <iostream>
#include <string>
#include <vector>

using namespace std;
class RegLetNode{
    public:
    string value;
    RegLetNode* previous;
    RegLetNode* next;
    
};


class Solution {
    private:
    
    public:
    bool isMatch(std::string s, std::string p,vector<int> &node) {
        int i = 0;
        
        for (int j = 0; j<p.length();j++)
        {
            
        }
        return true;
        
    }
    
};
int main(){
    Solution s;
    bool match;
    vector<int> v;

    std::string _one = "mississippi";
    std::string _two = "mis*is*p*i.";
/*    match = s.isMatch(_one,_two);
    std::cout<<match<<std::endl;

    _one = "ab";
    _two = "a*";
    match = s.isMatch(_one,_two);
    std::cout<<match<<std::endl;

    _one = "abc";
    _two = "ab*";
    match = s.isMatch(_one,_two);
    std::cout<<match<<std::endl;
*/
    _one = "ab";
    _two = "a*";
    RegLetNode *currNode;

    match = s.isMatch(_one,_two,v);
    std::cout<<match<<std::endl;
    return 0;
}