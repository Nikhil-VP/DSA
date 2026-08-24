#include <vector>
#include <unordered_set>

class Solution {
public:
    int missingInteger(std::vector<int>& nums) {
        int sum = nums[0];
        
        // Step 1: Calculate the longest sequential prefix sum
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break;
            }
        }
        
        // Step 2: Store elements in a hash set for quick lookup
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        
        // Step 3: Find the smallest integer >= sum that is missing
        while (numSet.count(sum)) {
            sum++;
        }
        
        return sum;
    }
};