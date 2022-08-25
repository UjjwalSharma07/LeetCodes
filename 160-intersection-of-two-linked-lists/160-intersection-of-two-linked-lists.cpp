/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp = headA;
        ListNode* curr = headB;
        if(headA == NULL || headB == NULL){
            return NULL;
        }
        
        map<ListNode*,bool> visited;
        
        while(curr != NULL){
            visited[curr] = true;
            curr= curr->next; 
        }
        while(temp != NULL){
            
            if(visited[temp] == true){
                 break;
            }
            temp = temp->next;
        }
        if(curr == NULL && temp == NULL){
            return NULL;
        }
        return temp;
    }
};