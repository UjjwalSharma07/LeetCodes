//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class TrieNode{
    public:
        TrieNode* children[26];
        bool isTerminal;
    
        TrieNode(){
            for(int i=0; i<26; i++){
                children[i] = NULL;
            }
            isTerminal = false;
        }
};
class Trie{
    public:
        TrieNode* root;
        
        Trie(){
            root = new TrieNode();
        }
        
        void insert(string s){
            TrieNode* child = root;
            for(int i=0; i<s.length(); i++){
                if(child->children[s[i]-'a'] == NULL){
                    child->children[s[i]-'a'] = new TrieNode();
                }
                child = child->children[s[i]-'a'];
            }
            child->isTerminal = true;
        }
        void find(TrieNode* child,string& res,vector<string>& ans){
            if(child->isTerminal)
                ans.push_back(res);
                
            for(int i=0; i<26; i++){
                if(child->children[i]){
                    res.push_back('a'+i);
                    find(child->children[i],res,ans);
                    res.pop_back();
                }
            }
        }
        vector<vector<string>> display_Contacts(string &s){
            string temp="";
            vector<vector<string>> ans;
            
            TrieNode* child = root;
            
            for(int i=0; i<s.size(); i++){
                vector<string>res;
                
                if(child == NULL){
                    res.push_back("0");
                    ans.push_back(res);
                    continue;
                }
                temp.push_back(s[i]);
                child = child->children[s[i]-'a'];
                
                if(child){
                    find(child,temp,res);
                    ans.push_back(res);
                }
                else{
                    res.push_back("0");
                    ans.push_back(res);
                }
            }
            return ans;
        }
};
class Solution{
public:
    
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        Trie *t = new Trie();
        for(int i=0; i<n; i++){
            t->insert(contact[i]);
        }
        return t->display_Contacts(s);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends