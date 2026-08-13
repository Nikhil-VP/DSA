class MinStack {
public:
    stack<pair<int,int>> s ;
    
    MinStack() {
    }
    
    void push(int value) {
        if(s.empty())
            s.push({value,value});
        else
        {   
            int c_min = s.top().second;
            s.push({value, min(value,c_min)});
        }
        return ;
    }
    
    void pop() {
        if(!s.empty())
            s.pop();
        return ;    
    }
    
    int top() {
        if(!s.empty())
            return s.top().first;
        return -1;
    }
    
    int getMin() {
        if(!s.empty())
            return s.top().second;
        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */