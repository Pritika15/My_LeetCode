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
    bool isPalindrome(ListNode* head) {
        bool ans = true;
        ListNode* fast= head;
        ListNode* slow=head;
        ListNode* curr = nullptr;
        ListNode* prev = nullptr;

        while(fast && fast->next)
        {
            fast= fast->next->next;
            slow= slow->next;
        }
        curr = slow;

        while(curr)
        {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr =  nextNode;
        }

        ListNode* right = prev;
        ListNode* left = head;

        while(right)
        {
            if(left->val!=right->val) return false;
            left = left->next;
            right = right->next;
        }
        return ans;   
    }
};