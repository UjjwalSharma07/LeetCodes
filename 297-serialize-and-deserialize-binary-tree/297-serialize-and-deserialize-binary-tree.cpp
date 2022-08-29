/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    int indx=0;
    // Encodes a tree to a single string.
    void helper1(TreeNode* root,string& s){
        if(root == NULL){
            s.append("# ");
            return;
        }
        s.append(to_string(root->val));
        s.append(" ");
        helper1(root->left,s);
        helper1(root->right,s);
    }
    string serialize(TreeNode* root) {
        string ans="";
        helper1(root,ans);
        return ans;
    }
    int str_to_int(string st){
        int k=indx;
        while(k <st.size() && st[k]!= ' '){
            k++;
        }
        int num = stoi(st.substr(indx,k-indx));
        indx = k+1;
        return num;
    }
    
    TreeNode* helper2(string s){
        if(indx>=s.size()){
           return NULL;
        }
        if(s[indx] == '#'){
            indx+=2;
            return NULL;
        }
        int val = str_to_int(s);
        TreeNode* root = new TreeNode(val);
        root->left = helper2(s);
        root->right = helper2(s);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        return helper2(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));