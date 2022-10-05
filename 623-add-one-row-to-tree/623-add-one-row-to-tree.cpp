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
    void solve(TreeNode* root,int val,int depth,int curr){
        if(root == NULL)
            return ;
        if(curr+1 == depth){
            TreeNode* tempLeft = root->left;
            TreeNode* tempRight = root->right;
            TreeNode* currLeft = new TreeNode(val);
            TreeNode* currRight = new TreeNode(val);
            
            root->left = currLeft;
            currLeft->left = tempLeft;
            root->right = currRight;
            currRight->right = tempRight;
            return ;
        }
        solve(root->left,val,depth,curr+1);
        solve(root->right,val,depth,curr+1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* newroot = new TreeNode(val);
            newroot->left = root;
            return newroot;
        }
        int curr = 1;
        solve(root,val,depth,curr);
        return root;
    }
};