class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int val =0;
        int sz=0;
        while(!q1.empty())
        {
            sz++;
            q2.push(q1.front());
            q1.pop();
        }
        sz-=1;
        while(sz--)
        {
            q1.push(q2.front());
            q2.pop();
        }
        val = q2.front();
        q2.pop();
        return val;
    }
    
    int top() {
        int val =0;
        int sz=0;
        while(!q1.empty())
        {
            sz++;
            q2.push(q1.front());
            q1.pop();
        }
        while(sz--)
        {
            val=q2.front();
            q1.push(q2.front());
            q2.pop();
            
        }
        
        return val;
        
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */