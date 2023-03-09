//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(char x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList() {
    int n; // length of link list
    scanf("%d ", &n);

    char data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i) {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
/*

Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution {
    bool isAnagram(string a, string b) {
        if(a.length()!=b.length()){  //length is not equal so not anangram
            return false;
        }
        int alpha[26]={0};
        for(int p=0;p<a.length();p++){
            alpha[a[p]-'a']++;   //every alphabet occourance ++
            alpha[b[p]-'a']--;  //every alphabet occourance --
        }
        for(int p=0;p<26;p++){
            if(alpha[p]!=0){   //will be 0 all occourance it it is a anagram
                return false;
            }
        }
        return true;
    }
  public:
    vector<Node*> findAnagrams(struct Node* head, string s) {
        //base case 
        if(head==NULL){
            return {};
        }
        
        vector<Node*>ans;
        
        Node* first=head;
        Node* last=NULL;
        
        while(head!=NULL){
            
            string temp="";
            for(int p=0;p<s.length();p++){
                if(first==NULL){
                    return ans;
                }
                temp=temp+first->data;  //adding current alphabet
                last=first;             //moving forward
                first=first->next;
            }
            
            if(isAnagram(s,temp)){
                ans.push_back(head);  //pushing the starting node in the answer
                last->next=NULL;      //the last should be NULL for the answer
            }else{
                first=head->next;     //if not valid anagram then move forward
            }
            head=first;  //reseting both head and first to the same spot as no overlapping is allowed
            
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        struct Node *head = inputList();

        string s;
        cin >> s;

        Solution obj;
        vector<Node *> res = obj.findAnagrams(head, s);

        for (int i = 0; i < res.size(); i++) {
            printList(res[i]);
        }

        if (res.size() == 0) cout << "-1\n";
    }
}

// } Driver Code Ends