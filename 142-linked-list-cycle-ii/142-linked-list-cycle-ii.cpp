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
    ListNode* FloydsDetectLoop(ListNode* &head){
    if(head==NULL){
        return NULL;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    while(slow != NULL && fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;
        if(slow==fast){
        return slow;
        }
    }
    return NULL;
}

public:
    ListNode *detectCycle(ListNode *head) {
    if(head==NULL){
        return NULL;
    }
     
    ListNode* InterectionPoint = FloydsDetectLoop(head);
     
    if(InterectionPoint == NULL){
        return NULL;
    }
    ListNode* slow = head;
    while(slow != InterectionPoint){
        slow = slow->next;
        InterectionPoint = InterectionPoint->next;
    } 
    return slow;
    }
};