// easy
// https://leetcode.com/problems/implement-queue-using-stacks/description/

// tc : 
// push  : O(1)
// pop   : O(n)
// peek  : O(n)
// empty : O(1)

class MyQueue {
public:

    stack<int> s1;
    stack<int> s2;

    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s1.empty()) {
            return -1;
        }

        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        
        int val = s2.top();
        s2.pop();

        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }

        return val;
    }
    
    int peek() {
        if(s1.empty()) {
            return -1;
        }

        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        
        int val = s2.top();

        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }

        return val;
    }
    
    bool empty() {
        return s1.empty();
    }
};