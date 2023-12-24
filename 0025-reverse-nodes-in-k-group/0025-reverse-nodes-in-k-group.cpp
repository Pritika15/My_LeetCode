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
    ListNode* FindKth(ListNode*head,int k)
    {
        ListNode* temp=head;
        k--;
        while(temp!=NULL && k--)
        {
            temp=temp->next;
        }
        return temp;
    }
    void reverse(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nextNode=head->next;
        while(nextNode)
        {
            curr->next=prev;
            prev=curr;
            curr=nextNode;
            nextNode=nextNode->next;
        }
        curr->next=prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevNode=NULL;
        while(temp)
        {
            ListNode* KthNode=FindKth(temp,k);
            if(!KthNode)
            {
                if(prevNode) prevNode->next=temp;
                break;
            }
            ListNode* nextNode=KthNode->next;
            KthNode->next=NULL;
            reverse(temp);
            if(temp==head)
            {
                head=KthNode;
            }
            else
            {
                prevNode->next=KthNode;
            }
            prevNode=temp;
            temp=nextNode;
            
        }
        return head;
    }
};