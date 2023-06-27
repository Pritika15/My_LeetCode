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
    bool hasAcycle(ListNode *head, ListNode *&ans)
    {
        ListNode * curr=head;
        ListNode * slow=head;
        ListNode * fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast)
            {
                while(curr!=slow)
                {
                    curr=curr->next;
                    slow=slow->next;
                }
                ans=curr;
                return true;
            }
        }
        return false;
    }
    ListNode *detectCycle(ListNode *head) {
       if(!head || !head->next) return NULL;
        ListNode * ans;
        if(hasAcycle(head,ans)) return ans;
        else return NULL;
    }
};