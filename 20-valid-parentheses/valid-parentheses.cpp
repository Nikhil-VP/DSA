class Solution {
public:
    bool isValid(string s) {
        stack<char> ch;
        for(char c:s){
            if(c=='(' || c=='{' || c=='[') ch.push(c);
            else if(c==')'&& !ch.empty() && ch.top()=='(')ch.pop();
            else if(c=='}'&&  !ch.empty() && ch.top()=='{')ch.pop();
            else if(c==']'&& !ch.empty() && ch.top()=='[')ch.pop();
            else return false;
        }
        if(!ch.empty()) return false;
        return true;
    }
};