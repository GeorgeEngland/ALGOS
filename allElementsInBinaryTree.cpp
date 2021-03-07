
 // Definition for a binary tree node.
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void getList(vector<int> &ret,TreeNode* root){
        if(root->right!=NULL)
         {
            ret.push_back(root->right->val);
            getList(ret,root->right);

        }

        if(root->left!=NULL)
         {
            ret.push_back(root->left->val);
            getList(ret,root->left);
        }
        return;
        
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ret;
        if(root1){
            ret.push_back(root1->val);
                    getList(ret,root1);

        }
        if(root2){
            ret.push_back(root2->val);
        getList(ret,root2);
            
        }
        std::sort(ret.begin(),ret.end());
        return ret;
        
    }
};