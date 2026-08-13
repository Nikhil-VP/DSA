#include <string>
#include <vector>
#include <stack>
#include <algorithm>

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastIndex(26, 0);
        vector<bool> visited(26, false);
        stack<char> st;

        // Step 1: Store the last occurrence index for each character
        for (int i = 0; i < s.length(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        // Step 2: Process each character using a monotonic stack
        for (int i = 0; i < s.length(); i++) {
            char curr = s[i];
            
            // If character is already in our result stack, skip it
            if (visited[curr - 'a']) continue;

            // Maintain monotonic property: pop larger characters if they appear later
            while (!st.empty() && st.top() > curr && lastIndex[st.top() - 'a'] > i) {
                visited[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(curr);
            visited[curr - 'a'] = true;
        }

        // Step 3: Reconstruct string from stack
        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());

        return result;
    }
};