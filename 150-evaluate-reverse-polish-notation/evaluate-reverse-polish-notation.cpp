class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        
        for (const string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                // Pop second operand first, then first operand
                long long b = st.top(); st.pop();
                long long a = st.top(); st.pop();
                
                if (token == "+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                else if (token == "/") st.push(a / b);
            } else {
                // Convert number string to integer and push
                st.push(stoi(token));
            }
        }
        
        return st.top();
    }
};