/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void lvlorder(Node* root,vector<vector<int>>& ans){
        queue<Node*>q;
        q.push(root);
        
        
        while(!q.empty()){
            
            vector<int>temp;
            int size = q.size();
            for(int i=0; i<size; i++){
                temp.push_back(q.front()->val);
                               
                Node* front= q.front();
                q.pop();
                
                for(auto it:front->children){
                    q.push(it);
                }
            }
            ans.push_back(temp);
        }
    }
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>ans;
        if(root == NULL){
            return ans;
        }
        lvlorder(root,ans);
        return ans;
    }
};