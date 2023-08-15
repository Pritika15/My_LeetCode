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
    ListNode* partition(ListNode* head, int x) {
        ListNode*temp=head;
        vector<int>v1;
        vector<int>v2;
        while(temp!=NULL)
        {
            if(temp->val<x) v1.push_back(temp->val);
            else v2.push_back(temp->val);
            temp=temp->next;
            
        }
        ListNode* Node=new ListNode(-1);
         ListNode* N=Node;
        
        for(int i=0;i<v1.size();i++)
        {
            N->next=new ListNode(v1[i]);
            N=N->next;
        }
        for(int i=0;i<v2.size();i++)
        {
            N->next=new ListNode(v2[i]);
            N=N->next;
        }
        return Node->next;
        
    }
};