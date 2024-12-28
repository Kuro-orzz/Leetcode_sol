class MyQueue {
public:
    stack<int> fifo;
    stack<int> lifo;
    MyQueue() { 
    }
    
    void push(int x) {
        while(!fifo.empty()){
            lifo.push(fifo.top());
            fifo.pop();
        }
        lifo.push(x);
    }
    
    int pop() {
        while(!lifo.empty()){
            fifo.push(lifo.top());
            lifo.pop();
        }
        int x = fifo.top();
        fifo.pop();
        while(!fifo.empty()){
            lifo.push(fifo.top());
            fifo.pop();
        }
        return x;
    }
    
    int peek() {
        while(!lifo.empty()){
            fifo.push(lifo.top());
            lifo.pop();
        }
        int x = fifo.top();
        while(!fifo.empty()){
            lifo.push(fifo.top());
            fifo.pop();
        }
        return x;
    }
    
    bool empty() {
        return lifo.empty();
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