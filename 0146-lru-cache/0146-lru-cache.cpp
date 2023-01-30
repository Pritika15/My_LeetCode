class LRUCache {
public:
    class node{
        public:
        int keyVal;
        int val;
        node* next;
        node* prev;
        node(int k, int v)
        {
            keyVal=k;
            val=v;
        }
    };
    unordered_map<int,node*>m;
    int cap;
    node* head= new node(-1,-1);
    node* tail= new node(-1,-1);
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void addNode(node* newNode)
    {
        node* temp=head->next;
        head->next=newNode;
        newNode->next=temp;
        temp->prev=newNode;
        newNode->prev=head;
    }
    void deleteNode(node * delNode)
    {
        node* delprev=delNode->prev;
        node* delnext=delNode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
    }
    int get(int key) {
        if(m.find(key)!=m.end())
        {
            node* ResultNode=m[key];
            int result=ResultNode->val;
            m.erase(key);
            deleteNode(ResultNode);
            addNode(ResultNode);
            m[key]=head->next;
            return result;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end())
        {
            node* existingNode=m[key];
            m.erase(key);
            deleteNode(existingNode);
        }
        if(m.size()==cap)
        {
            node* LRU=tail->prev;
            m.erase(LRU->keyVal);
            deleteNode(LRU);
        }
        addNode(new node(key,value));
        m[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */