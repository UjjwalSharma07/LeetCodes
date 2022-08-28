/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   void PreOrderModify(TreeNode* root , int lvl,vector<int>& ans){
        if(root == NULL){
            return;
        }
        if(ans.size()<lvl){
           ans.push_back(root->val);
        }
        PreOrderModify(root->right,lvl+1,ans);
        PreOrderModify(root->left,lvl+1,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        PreOrderModify(root,1,ans);
        return ans;
    }
};