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
   
    ListNode* reverse(ListNode* &head2){
        ListNode* prev = NULL;
        ListNode* curr = head2;
        ListNode* next = NULL;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* MiddleEle(ListNode* &head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast != NULL &&fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;    
        }
        return slow;
    }
    void reorderList(ListNode* head) {
        if(head== NULL || head->next== NULL || head->next->next == NULL)
            return;
       
        ListNode* middle = MiddleEle(head);
        ListNode* head2 = reverse(middle->next);
        middle->next= NULL;
        ListNode* head1 = head;
        
        
        while(head2){
            ListNode* temp1 = head1->next;
            ListNode* temp2 = head2->next;
            head1->next = head2;
            head2->next = temp1;
            head1= temp1;
            head2= temp2;
        }
        
    }
};