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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return NULL;
        ListNode*curr=head->next;
        ListNode*prev=head;
        while(curr!=NULL)
        {
            if(curr->val==val)
            {
                ListNode*temp=curr->next;
                prev->next=temp;
                
            }
            else
            {
                 prev=curr;
            }
           
            curr=curr->next;
            
        }
        if(head->val==val) return head->next;
        return head;
        
    }
};