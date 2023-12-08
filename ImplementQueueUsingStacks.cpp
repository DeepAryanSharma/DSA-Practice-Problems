class MyQueue {
public:
    stack<int> s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
        
        
    }
    
    int pop() {
        int pop=-1;
        if(!s2.empty()){
            pop=s2.top();
        }
        else{
            while(!s1.empty()){
                int temp=s1.top();
                s1.pop();
                s2.push(temp);
            }
            pop=s2.top();
        }
        s2.pop();
        return pop;
        
        
    }
    
    int peek() {
        if(!s2.empty()){
            return s2.top();
        }
        else{
            while(!s1.empty()){
                int temp=s1.top();
                s1.pop();
                s2.push(temp);
            }
            return s2.top();
        }
        
    }
    
    bool empty() {
        if(s1.empty() && s2.empty()){
            return true;
        }
        else{
            return false;
        }
        
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
