class MyQueue {
public:
    stack<int> input;
    stack<int> output;

    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        int val ;
        if(output.empty() == true)
        {
            while(input.empty()==false)
            {
                output.push(input.top());
                input.pop();
            }
            val = output.top();
            output.pop();
        }
        else{
            val = output.top();
            output.pop();
        }
        return val;
    }
    
    int peek() {
        int val;
        if(output.empty() == true)
        {
            while(input.empty()==false)
            {
                output.push(input.top());
                input.pop();
            }
            val = output.top();
        }
        else{
            val = output.top();
        }
        return val;
    
    }
    
    bool empty() {
        return input.empty() && output.empty();
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