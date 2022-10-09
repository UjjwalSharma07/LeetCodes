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
    vector<int>v;
    int solve(TreeNode* root,int k){
        if(root == NULL)
            return 0;
        
        int count=0;
        if(find(v.begin(),v.end(),root->val)!=v.end()){
            count=1;
        }
        else{
            v.push_back(k-root->val);
            int left = solve(root->left,k);
            int right = solve(root->right,k);
        
            count = max(left,right);
        }
        return count;
    }
    bool findTarget(TreeNode* root, int k) {
        return solve(root,k);
    }
};