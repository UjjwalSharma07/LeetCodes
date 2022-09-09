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
    TreeNode* prev = NULL;
    TreeNode* first = NULL;
    TreeNode* last = NULL;
    TreeNode* mid = NULL;
    void inorder(TreeNode* root){
        if(root == NULL){
            return;
        }
        inorder(root->left);
        int value;
        
        if(prev == NULL)
            value = INT_MIN;
        else 
            value = prev->val;
        if(first == NULL && root->val<value){
            mid = root;
            first = prev;
        }
        else if(root->val<value){
            last = root;
        }
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        if(last){
            swap(last->val,first->val);
        }
        else
            swap(mid->val,first->val);
    }
};