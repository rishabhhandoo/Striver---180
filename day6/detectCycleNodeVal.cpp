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
    ListNode *detectCycle(ListNode *head) {
        if(!head)   return NULL;
        
        ListNode* fast = head;
        ListNode* slow = slow;
        
        while(fast->next && fast->next->next)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(fast == slow)
            {
                fast=head;
                break;
            }
        }
        if(fast->next == NULL || fast->next->next ==NULL)   return NULL;
        
        while(fast!=slow){
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
};