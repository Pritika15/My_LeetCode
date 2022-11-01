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
#include<bits/stdc++.h>
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        stack<int> s1;
        stack<int> s2;
        vector<int>v1;
        vector<int>v2;
        ListNode* templ1=l1;
        ListNode* templ2=l2;
         
       for(templ1;templ1!=NULL;templ1=templ1->next)
       {
           s1.push(templ1->val);
       }
        for(templ2;templ2!=NULL;templ2=templ2->next)
       {
           s2.push(templ2->val);
       }
        while(!s1.empty())
        {
            int x=s1.top();
            v1.push_back(x);
            s1.pop();
        }
         while(!s2.empty())
        {
            int y=s2.top();
            v2.push_back(y);
            s2.pop();
        }
        
        if(v1.size()>v2.size())
        {
           int zeross= v1.size()-v2.size();
            int target=0;
            for(int i=0;i<zeross;i++)
            {
                v2.insert(v2.begin(),target);
            }
        }
         else if(v2.size()>v1.size())
        {
           int zeross= v2.size()-v1.size();
            int target=0;
            for(int i=0;i<zeross;i++)
            {
                v1.insert(v1.begin(),target);
            }
        }
        
       stack<int>s3;
        vector<int>v3;
        int sum=0,carry=0;
        int first=v1.size()-1,second=v2.size()-1;
        while(first>=0 && second>=0)
        {
            sum=v1[first--]+v2[second--]+carry;
            if(sum>9)
            {
                carry=sum/10;
                sum=sum%10;
                        
              }
            else
                carry=0;
            
            s3.push(sum);
        }
        while(!s3.empty())
        {
            int yy=s3.top();
            v3.push_back(yy);
            s3.pop();
        }
        if(carry!=0)
        {
            v3.insert(v3.begin(),carry);
        }
       // cout<<v3[v3.size()-1];
        ListNode* n1= new ListNode(v3[v3.size()-1]);
         ListNode* n3=n1;
       for(int i=v3.size()-2;i>=0;i--)
       {
          
           ListNode* n2= new ListNode(v3[i]);
           n3->next=n2;
           n3=n3->next;
       }
        
       
        
        return n1;
    }
};