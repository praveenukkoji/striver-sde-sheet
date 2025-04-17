// level - medium
// https://leetcode.com/problems/online-stock-span/description/

// tc : Total for n calls = O(n²)
// sc : O(n)

class StockSpanner {
public:
    stack<int> st;

    StockSpanner() {
        
    }
    
    int next(int price) {
        st.push(price);

        stack<int> copy(st);

        copy.pop();
        int span = 1;

        while(!copy.empty() && copy.top() <= price) {
            copy.pop();
            span += 1;
        }

        return span;
    }
};


// tc : Total Time for n calls = O(n * n)
// sc : O(n)

class StockSpanner {
public:
    vector<int> arr;

    StockSpanner() {
        
    }
    
    int next(int price) {
        arr.push_back(price);

        int span = 1;
        for(int i = arr.size() - 2;i>=0;i--) {
            if(arr[i] <= price) {
                span++;
            }
            else {
                break;
            }
        }

        return span;
    }
};

// tc : Time Complexity per call = O(n)
// sc : O(n)

class StockSpanner {
public:
    stack<pair<int, int>> st;
    int ind;

    StockSpanner() {
        ind = 0;
    }
    
    int next(int price) {
        while(!st.empty() && st.top().first <= price) {
            st.pop();
        }

        if(st.empty()) {
            st.push({price, ind});
            ind++;

            return ind;
        }
        
        int span = ind - st.top().second;

        st.push({price, ind});
        ind++;

        return span;
    }
};
