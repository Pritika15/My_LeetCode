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
    void swapEle(int i,int j,vector<int>&v)
    {
        while(i<j)
        {
            swap(v[i],v[j]);
            i++;
            j--;
        }
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int>v;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            v.push_back(temp->val);
            temp=temp->next;
        }
        int n=v.size();
        for(int i=0;i<n;i++)
        {
            if(i==left-1)
            {
                
                for(int j=i+1;j<n;j++)
                {
                    if(j==right-1)
                    {
                        //cout<<i<<" "<<j;
                        swapEle(i,j,v);
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
            cout<<v[i]<<" ";
        ListNode*ll =new ListNode(v[0]);
        ListNode*temp2=ll;
        for(int i=1;i<n;i++)
        {
            ListNode* lll=new ListNode(v[i]);
            temp2->next=lll;
            temp2=temp2->next;
        }
        return ll;
    }
};