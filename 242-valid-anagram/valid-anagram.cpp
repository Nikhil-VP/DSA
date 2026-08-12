class Solution {
public:
    bool isAnagram(string s, string t) {
        // Quick check: if lengths differ, they can't be anagrams
        if (s.length() != t.length()) {
            return false;
        }

        int count[26] = {0};

        // Increment count for characters in s, decrement for t
        for (int i = 0; i < s.length(); ++i) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
            
        }

        // Check if all counts are zero
        for (int i = 0; i < 26; ++i) {
            if (count[i] != 0) {
                return false;
            }
        }

        return true;
    }
};