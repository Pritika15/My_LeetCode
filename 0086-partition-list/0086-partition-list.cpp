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
        if(!head || !head->next) return head;
        
        vector<int>v;
        ListNode* temp=head;
        while(temp)
        {
            v.push_back(temp->val);
            
            temp=temp->next;
        }
        
        vector<int>v1;
        vector<int>v2;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]<x)v1.push_back(v[i]);
            else v2.push_back(v[i]);
        }
        ListNode*ans=new ListNode(-1);
        ListNode*a=ans;
        for(int i=0;i<v1.size();i++)
        {
            ListNode*t=new ListNode(v1[i]);
            ans->next=t;
            ans=ans->next;
        }
        for(int i=0;i<v2.size();i++)
        {
            ListNode*t=new ListNode(v2[i]);
            ans->next=t;
            ans=ans->next;
        }
        return a->next;
    }
};