// level - easy
// https://leetcode.com/problems/valid-parentheses/description/

// tc : O(n)
// sc : O(n)

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char ch : s) {
            if(st.size() == 0)
                st.push(ch);
            
            else if (ch == ')' && st.top() == '(')
                st.pop();
            else if (ch == ']' && st.top() == '[')
                st.pop();
            else if (ch == '}' && st.top() == '{')
                st.pop();

            else
                st.push(ch);
        }

        return (st.size() == 0);
    }
};