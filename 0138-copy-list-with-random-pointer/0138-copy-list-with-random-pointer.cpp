/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
         Node* curr=head;
        while(curr!=NULL)
        {
             Node* temp=curr->next;
             Node* newNode=new Node(curr->val);
            curr->next=newNode;
            newNode->next=temp;
            curr=curr->next->next;
        }
        curr=head;
        while(curr!=NULL)
        {
            if(curr->random!=NULL) curr->next->random=curr->random->next;
            curr=curr->next->next;
        }
        Node* ans=new Node(0);
         Node* ans1=ans;
        curr=head;
        while(curr!=NULL)
        {
            
             Node*front=curr->next->next;
            ans1->next=curr->next;
            curr->next=front;
            ans1=ans1->next;
            curr=front;
            
                
        }
        return ans->next;
    }
};