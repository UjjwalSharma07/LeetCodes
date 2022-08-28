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
    void inorder(TreeNode* root ,vector<int>& ans){
        
    if(root == NULL){
        return ;
    }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>res;
       inorder(root,res);
      
        int size = res.size()-1;
        
        int largest = 0;
        int i = 0;
        while(k--){
            largest  = res[i];
            i++;
        }
        return largest;
    }
};