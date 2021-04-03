
// * Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
    
public:
    string res = "";
    void dfs(TreeNode* root,string s){
        if(!root)return ;
        string cur = (char)(root->val +'a')+s;
        if(root->right)dfs(root->right,cur);
        if(root->left)dfs(root->left,cur);
        
        if(!root->left && !root->right){
            string temp = (char)(root->val +'a')+s;
            if(res.length()==0)res = temp;
            if(temp<res)res=temp;
        }
        
    }
    string smallestFromLeaf(TreeNode* root) {
        dfs(root,res);
        return res;
    }
};
int main(){
    Solution s;

    return 0;
}