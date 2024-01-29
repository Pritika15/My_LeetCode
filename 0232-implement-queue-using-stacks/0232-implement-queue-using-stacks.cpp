class MyQueue {
public:
    stack<int>s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
// step 1: check if stack s1 is empty or not ---> put all eles in s2
        while(!s1.empty())
        {
            int y=s1.top();
            s1.pop();
            s2.push(y);
        }
        
        s2.push(x);
//         step 2: put everything from s2 --> s1
        while(!s2.empty())
        {
            int y=s2.top();
            s2.pop();
            s1.push(y);
        }
        
    }
    
    int pop() {
        int ans=s1.top();
        s1.pop();
        return ans;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */