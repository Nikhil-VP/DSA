class Solution {
public:
    bool isPalindromic(string s) {
        string binaryStr = "";
        
        
        for (char c : s) {
            binaryStr += bitset<8>(c).to_string();
        }
        
       
        string reversedStr = binaryStr;
        reverse(reversedStr.begin(), reversedStr.end());
        
        return binaryStr == reversedStr;
    }
};