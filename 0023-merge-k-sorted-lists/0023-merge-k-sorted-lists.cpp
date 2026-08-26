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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>minHeap;

        for(int i =0;i<lists.size();i++)
        {
            if (lists[i] != nullptr) {
            minHeap.push({lists[i]->val, lists[i]});
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* dummy1 = dummy;
        

        while(minHeap.size()>0)
        {
            pair<int,ListNode*> topVal = minHeap.top();
            dummy1->next = topVal.second;
            dummy1= dummy1->next;
            minHeap.pop();
            if (topVal.second->next != nullptr) {
                minHeap.push({topVal.second->next->val, topVal.second->next});
            }
           
        }
        return dummy->next;

        
    }
};