class MyQueue {
    private:
    stack<int>s;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        pushHelper(x);
    }
    void pushHelper(int x)
    {
        if(s.size()==0)
        {
            s.push(x);
            return;
        }
        int data=s.top();
        s.pop();
        pushHelper(x);
        s.push(data);
    }
    
    int pop() {
        int curr=s.top();
        s.pop();
        return curr;
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
        return s.empty();
    }
};
