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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return NULL;
        if(head!=NULL && head->next==NULL) return head;
        ListNode* nextNode=head->next;
        head->next=NULL;
        ListNode* temp=nextNode->next;
        while(temp!=NULL)
        {
            nextNode->next=head;
            head=nextNode;

            nextNode=temp;
            temp=temp->next;
        }
        nextNode->next=head;
        return nextNode;
        
        
    }
};