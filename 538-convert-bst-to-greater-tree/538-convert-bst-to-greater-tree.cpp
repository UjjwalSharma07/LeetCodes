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
    int sum2 = 0;
    void sum(TreeNode* root,vector<int>& ans){        
        if(root == NULL){
            return;
        }
       
        sum(root->right,ans);
        sum2 = sum2 + root->val;
        ans.push_back(sum2);
        sum(root->left,ans);   
        
    }

    void Convert(TreeNode* root,vector<int> &arr,int& i){
        if(root == NULL){
            return;
        }
        
        Convert(root->right,arr,i);
        root->val = arr[i++];
        Convert(root->left,arr,i);
    }
    TreeNode* convertBST(TreeNode* root) {
       
        vector<int>ans;
        sum(root,ans);
    
        int i=0;
        Convert(root,ans,i);
        
        return root;
    }
};