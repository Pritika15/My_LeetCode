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
        
        map<Node*,Node*>m;
        Node *curr=head;
        while(curr){
            Node *temp = new Node(curr->val);
            m[curr]=temp;
            curr=curr->next;
        }
        Node *dummy=NULL;
        //curr=head;
        for(auto i:m){
            if(dummy==NULL) dummy=i.second;
            i.second->next=m[i.first->next];
            i.second->random=m[i.first->random];
            
            
        }
        return dummy;
        
    }
};