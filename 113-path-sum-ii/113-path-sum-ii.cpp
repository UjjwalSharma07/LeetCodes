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
    void preorder(TreeNode* root, int target,vector<int>&res,vector<vector<int>>& ans){
        if(root==NULL)
            return;
        
        res.push_back(root->val);
        // leaf node condition true ho + root ki value = target then store result in ans.
        if(!root->left && !root->right && root->val == target)
            ans.push_back(res);
       
        preorder(root->left,target-root->val,res,ans);
        preorder(root->right,target-root->val,res,ans);
        res.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>res;
        preorder(root,targetSum,res,ans);
        return ans;
    }
};