// level - medium
// https://leetcode.com/problems/min-stack/description/

// tc : O(1) for every function
// sc : O(2*n)

class MinStack {
public:
    stack<pair<int, int>> st;
    MinStack() {}

    void push(int val) {
        if (st.empty())
            st.push({val, val});
        else
            st.push({val, min(st.top().second, val)});
    }

    void pop() {
        if (st.empty())
            return;

        st.pop();
    }

    int top() {
        if (st.empty())
            return -1;

        return st.top().first;
    }

    int getMin() {
        if (st.empty())
            return -1;

        return st.top().second;
    }
};

// tc : O(1) for all function
// sc : O(n)

class MinStack {
public:
    stack<long long> st;
    long long mini;

    MinStack() { mini = LLONG_MAX; }

    void push(int val) {
        long long val_ = val;

        if (st.empty()) {
            st.push(val_);
            mini = val_;
        } 
        else {
            if (val_ > mini) {
                st.push(val_);
            } 
            else {
                st.push(2LL * val_ - mini);
                mini = val_;
            }
        }
    }

    void pop() {
        if (!st.empty()) {
            long long top = st.top();
            st.pop();

            if (top < mini) {
                mini = 2 * mini - top;
            }
        }
    }

    int top() {
        if (st.empty())
            return -1;

        long long top = st.top();

        if (top < mini)
            return mini;

        return (int)top;
    }

    int getMin() { return (int)mini; }
};