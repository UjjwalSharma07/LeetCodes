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
    void solve(TreeNode* root,vector<int>&temp,int& count){
        if(root == NULL)
            return;
        
        if(root->left == NULL && root->right == NULL){
            temp[root->val]++;
            int odd = 0;
            
            for(int i=0; i<10; i++){
                if((temp[i] & 1)== 1)
                    odd++;
            }
            if(odd <=1)
                count++;
            temp[root->val]--;
            return;
        }
        
        temp[root->val]++;
        
        if(root->left){
            solve(root->left,temp,count);
        }
        if(root->right){
            solve(root->right,temp,count);
        }
        temp[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>temp(10,0);
        int count=0;
        solve(root,temp,count);
        return count;
    }
};