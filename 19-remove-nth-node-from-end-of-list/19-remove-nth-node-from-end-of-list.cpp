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
    ListNode* reverse(ListNode* head){
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* newhead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return newhead;  
    }
    ListNode* deleteNode(ListNode* head,int index){
        if(index == 1){
            ListNode* head2 = head;
            ListNode* newhead = head2->next;
            head2->next = NULL;
            return newhead;
        }
        else{
            int pos = index-1;
            ListNode* prev = NULL;
            ListNode* curr= head;
            while(pos--){
                prev= curr;
                curr = curr->next;
            }
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
            
            return head;
        }   
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
       ListNode* head1 = reverse(head);
       ListNode* ans = deleteNode(head1,n);
       return reverse(ans);
    }
};