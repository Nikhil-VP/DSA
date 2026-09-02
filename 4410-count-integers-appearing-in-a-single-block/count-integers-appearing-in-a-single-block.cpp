class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_set<int> seen;
        unordered_set<int> invalid;
        
        int prev = -1;
        for (int num : nums) {
            if (num != prev) {

                if (seen.count(num)) {
                    invalid.insert(num);
                }
                seen.insert(num);
                prev = num;
            }
        }
    
        return seen.size() - invalid.size();
    }
};