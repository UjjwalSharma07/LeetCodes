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
    int position(vector<int>in ,int element, int s , int e){
    for(int i =s; i<=e; i++){
        if(in[i] == element){
            return i;
        }
    }
    return -1;
}
TreeNode* BuildTreeFromPreoderInorder(vector<int>& preorder, vector<int>& inorder,int& PreIndex, int instart,int inEnd){
    
    if(PreIndex == preorder.size() || instart > inEnd){
        return NULL;
    }
    int element = preorder[PreIndex++];
    TreeNode* root = new TreeNode(element);
    int pos = position(inorder,element,instart,inEnd);
    
    root->left = BuildTreeFromPreoderInorder(preorder,inorder,PreIndex,instart,pos-1);
    root->right = BuildTreeFromPreoderInorder(preorder,inorder,PreIndex,pos+1,inEnd);
    
    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int PreIndex = 0;
        return BuildTreeFromPreoderInorder(preorder,inorder,PreIndex,0,inorder.size()-1);
    }
};