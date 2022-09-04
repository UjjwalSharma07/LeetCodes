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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
         // number line bna kr approach assume ki
        
        // <--|---------|---------|--------|------|------|-------|--------->
        //   -3        -2        -1        0      1      2       3
        //             <4>       <2>    <1,5,6> <3,8>   <7>     <9>
        
        // 4,2,1,5,6,3,8,7,9 -> output it is.
        
        // 1st map bnaya horrizental distance and lvlwise nodes k liye
        // map< HD, lvl Wise <vector k ander nodes store> >
        vector<vector<int>>ans;
        map<int,map<int,vector<int>>>node;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            TreeNode* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;
            
            node[hd][lvl].push_back(frontNode->val);
            
            if(frontNode->left){
                q.push({frontNode->left,{hd-1,lvl+1}});
            }
            if(frontNode->right){
                q.push({frontNode->right,{hd+1,lvl+1}});
            }
        }
        for(auto i:node){
            vector<int>res;
            for(auto j:i.second){
               sort(j.second.begin(),j.second.end());
               for(auto k:j.second){
                   res.push_back(k);
               }     
            }
            ans.push_back(res);
        }
        return ans;
    }
};