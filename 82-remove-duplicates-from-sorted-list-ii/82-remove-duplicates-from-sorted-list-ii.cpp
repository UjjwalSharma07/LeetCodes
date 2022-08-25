/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* DeleteNodeShortedLL(ListNode* &head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    ListNode* curr = head;
    ListNode*prev=NULL;
        
    while(curr != NULL){
        
        ListNode* temp = curr->next;
        bool flag = false;
        
        while(temp != NULL && temp->val == curr->val){
            flag = true;
            temp = temp->next;   
        }
        if(flag){
            if(prev==NULL)
                head = temp;
            else
                prev->next = temp;
        }
        else{
            prev = curr;
        }
        curr=temp;
    }
    return head;
    }
    
    ListNode* deleteDuplicates(ListNode* head) {
        return DeleteNodeShortedLL(head);
    }
};