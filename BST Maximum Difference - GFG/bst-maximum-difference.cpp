//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    Node* find(Node* root,int target){

        if(root==NULL)return NULL;
        if(root->data==target)return root;
        if(root->data>target)
        find(root->left,target);
        else 
        find(root->right,target);
    }

    void root_TO_target(Node* root,int target,int &ans){
         if(root->data==target)return;
        ans=ans+root->data;
        if(root->data>target)
        root_TO_target(root->left,target,ans);
        else 
        root_TO_target(root->right,target,ans);
    }
    void target_to_child(Node* root){
        if(root==NULL)return;
        if(root->left){
            root->left->data+=root->data;
            target_to_child(root->left);

        }
        if(root->right){
            root->right->data+=root->data;
            target_to_child(root->right);
        }
    }
    void max_mini(Node* root,int &a,int &b){
        if(root==NULL)return;
        if(!root->left and !root->right){
            a=min(a,root->data);
            b=max(b,root->data);
        }
        else if(!root->left){
            max_mini(root->right,a,b);
        }else if(!root->right){

            max_mini(root->left,a,b);
        }else{
            max_mini(root->left,a,b);
            max_mini(root->right,a,b);
        }
    }
    int maxDifferenceBST(Node *root,int target){

        Node* temp = find(root,target);
        if(!temp)return -1;
        int ans = 0;
        root_TO_target(root,target,ans);
        int a = INT_MAX,b=INT_MIN;
        target_to_child(temp->left);
        target_to_child(temp->right);
        max_mini(temp->left,a,b);
        max_mini(temp->right,a,b);
        if(a==INT_MAX)a=0;
        if(b==INT_MIN)b=0;
        return max(ans-a,ans-b);
    }
};

 

 

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends