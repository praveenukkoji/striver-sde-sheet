// easy
// https://leetcode.com/problems/implement-stack-using-queues/description/

// USING TWO QUEUE'S

// tc : 
// push  : O(1)
// pop   : O(n)
// top   : O(1)
// empty : O(1)

// sc : O(2*n)

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
        if(q1.empty()) {
            return -1;
        }

        while(q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int val = q1.front();
        q1.pop();

        swap(q1, q2);

        return val;
    }
    
    int top() {
        if(q1.empty()) {
            return -1;
        }

        return q1.back();
    }
    
    bool empty() {
        return q1.empty();
    }
};

// USING SINGLE QUEUE

// tc : 
// push  : O(1)
// pop   : O(n)
// top   : O(1)
// empty : O(1)

// sc : O(n)

class MyStack {
public:
    queue<int> q1;

    MyStack() {
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        if(q1.empty()) {
            return -1;
        }

        int size = q1.size();
        size--;

        while(size--) {
            q1.push(q1.front());
            q1.pop();
        }

        int val = q1.front();
        q1.pop();

        return val;
    }
    
    int top() {
        if(q1.empty()) {
            return -1;
        }

        return q1.back();
    }
    
    bool empty() {
        return q1.empty();
    }
};