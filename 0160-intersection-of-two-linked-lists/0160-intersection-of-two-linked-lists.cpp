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
        ListNode * temp1=headA;
        ListNode * temp2=headB;
        int len1=0;
        int len2=0;
        while(temp1)
        {
            len1++;
            temp1=temp1->next;
        }
        while(temp2)
        {
            len2++;
            temp2=temp2->next;
        }
        int diff=abs(len1-len2);
        temp1=headA;
        temp2=headB;
        if(len1>len2)
        {
            while(diff-- && temp1)
            {
                temp1=temp1->next;
                
            }
            
            while(temp1!=temp2)
            {
                temp1=temp1->next;
                temp2=temp2->next;
            }
            return temp1;
            
        }
        else
        {
            while(diff-- && temp2)
            {
                temp2=temp2->next;
                
            }
            while(temp1!=temp2)
            {
                temp1=temp1->next;
                temp2=temp2->next;
            }
            return temp2;
        }
    }
};