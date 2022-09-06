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
    TreeNode* helper(vector<int>& nums,int l,int r){
        if(l>r)
           return NULL;
        
        int maxi = INT_MIN;
        int maxIndx = -1;
        for(int i=l; i<=r; i++){
            if(nums[i]>maxi){
                maxi = nums[i];
                maxIndx = i;
            }
        }
        TreeNode* root = new TreeNode(maxi);
        root->left = helper(nums,l,maxIndx-1);
        root->right = helper(nums,maxIndx+1,r);
        
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int maxi = INT_MIN;
        int maxIndx = -1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>maxi){
                maxi = nums[i];
                maxIndx = i;
            }
        }
        TreeNode* root = new TreeNode(maxi);
        root->left = helper(nums,0,maxIndx-1);
        root->right = helper(nums,maxIndx+1,nums.size()-1);
        
        return root;
    }
};