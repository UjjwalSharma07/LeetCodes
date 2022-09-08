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
    pair<TreeNode*,int>lcaDeepest(TreeNode* root){
        if(root == NULL){
            return {NULL,0} ;
        }
        
        auto left = lcaDeepest(root->left);
        auto right =lcaDeepest(root->right);
        
        if(left.second == right.second){
            return {root,left.second+1};
        }
        if(left.second>right.second){
            return {left.first,left.second+1};
        }
        else{
            return {right.first,right.second+1};
        }
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return lcaDeepest(root).first;
    }
};