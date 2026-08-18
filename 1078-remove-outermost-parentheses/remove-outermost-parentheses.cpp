class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string n="";
        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
            if (!st.empty()) {
                    n += '(';
                }

                st.push('(');
        }
            else{
                st.pop();  
                if(!st.empty())
                {
                n += ')';
                }
            }
        }
        return n;
    }
};