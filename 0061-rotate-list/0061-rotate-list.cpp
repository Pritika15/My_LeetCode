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
    ListNode* reverse(ListNode* temp)
{
     ListNode* prev=NULL;
     ListNode* cur=temp;
     ListNode* nextt=temp->next;
     while(nextt!=NULL)
     {
          cur->next=prev;
          prev=cur;
          cur=nextt;
          nextt=nextt->next;
     }
     cur->next=prev;
     prev=cur;
     return prev;
}
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
         if(!head->next) return head;
         ListNode*curr=head;
        ListNode* ttt=head;
        int len=0;
        while(ttt!=NULL)
        {
            len++;
            ttt=ttt->next;
        }
        if(k>=len) k=k%len;
         while(k--)
         {
             ListNode*c= reverse(curr);
             ListNode* t=reverse(c->next);
             curr=c;
             curr->next=t;

         }
         return curr;
        
    }
};

