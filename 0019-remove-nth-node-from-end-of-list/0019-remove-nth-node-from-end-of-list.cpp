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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        if(curr->next == nullptr) return prev;

        while(curr)
        {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        
        int cnt = 0;
        ListNode* dummy =  new ListNode(-1);
        dummy->next = prev;
        curr = dummy->next;
        prev = dummy;

        while(curr)
        {
            cnt++;
            if(cnt == n)
            {
                prev->next = curr->next!=nullptr ? curr->next : nullptr;
                break;
            }
            prev = curr;
            curr= curr->next;
        }

        ListNode* reversedHead = dummy->next;
        prev = nullptr;
        curr = reversedHead;

        while(curr)
        {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
        
    }
};