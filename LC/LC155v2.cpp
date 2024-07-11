typedef struct MIN
{
    int val;
    int count;
}Min;

class MinStack {
public:    
    void push(int val) {
        st.push(val);
        Min m;
        m.val = val;
        m.count = 1;
        if(min.empty())
        {
            min.push(m);
        }
        else
        {
            if(min.top().val > val)
            {
                min.push(m);
            }
            else{
                m = min.top();
                min.pop();
                m.count++;
                min.push(m);
            }
        }
    }  
    void pop() {
        st.pop();
        Min m = min.top();
        min.pop();
        m.count--;
        if(m.count > 0)
        {
            min.push(m);
        }
    }
    int top() {
        return st.top();
    }
    int getMin() {
        return min.top().val;
    }
private:
    stack<int> st;
    stack<Min> min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */