class MyStack {
public:
    queue<int>q;
    MyStack() {

    }
    
    void push(int x) {
        int sz = q.size();
        q.push(x);
        for(int i=1; i<=sz; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int el = q.front();
        q.pop();
        return el;
    }
    
    int top() {
        int el = q.front();
        return el;
    }
    
    bool empty() {
        return !q.size();
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