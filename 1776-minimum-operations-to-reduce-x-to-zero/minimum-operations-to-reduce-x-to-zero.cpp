#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int minOperations(std::vector<int>& nums, int x) {
        int total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }

        int target = total_sum - x;

        // If target is 0, we must remove all elements
        if (target == 0) return nums.size();
        // If target < 0, it's impossible to sum to x
        if (target < 0) return -1;

        int left = 0;
        int current_sum = 0;
        int max_len = -1;

        for (int right = 0; right < nums.size(); ++right) {
            current_sum += nums[right];

            while (left <= right && current_sum > target) {
                current_sum -= nums[left];
                left++;
            }

            if (current_sum == target) {
                max_len = std::max(max_len, right - left + 1);
            }
        }

        return max_len == -1 ? -1 : nums.size() - max_len;
    }
};