class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> map_s(256, 0);
        vector<int> map_t(256, 0);
        
        for (int i = 0; i < s.length(); i++) {
            // If the last seen positions of s[i] and t[i] don't match, string is not isomorphic
            if (map_s[s[i]] != map_t[t[i]]) {
                return false;
            }
            // Store current position (i + 1 to avoid matching default 0)
            map_s[s[i]] = i + 1;
            map_t[t[i]] = i + 1;
        }
        
        return true;
    }
};