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
    void solve(TreeNode* root,int& num,int& sum){
        if(root == NULL){
            return;
        }
       
        num = num*10+root->val;
        solve(root->left,num,sum);
        solve(root->right,num,sum);
        if(root->left == NULL && root->right == NULL){
            sum+=num;
        }
        num=num/10;
    }
    int sumNumbers(TreeNode* root) {
        int sum=0;
        int n=0;
        solve(root,n,sum);
        return sum;
    }
};