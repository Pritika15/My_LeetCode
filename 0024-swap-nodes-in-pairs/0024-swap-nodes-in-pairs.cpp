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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* curr = head;
        ListNode* prev = dummy;
        

        while(curr && curr->next)
        {
            ListNode* nextNode = curr->next;
            ListNode* nextPair = nextNode->next;
            prev->next = nextNode;
            nextNode->next = curr;
            curr->next = nextPair;
            prev = curr;
            curr = nextPair;
        }
        return dummy->next;
        
    }
};