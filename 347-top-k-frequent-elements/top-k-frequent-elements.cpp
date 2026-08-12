#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 1. Sort input to group identical numbers together
        sort(nums.begin(), nums.end());
        
        vector<pair<int, int>> freq_list; // Stores {frequency, element}
        int i = 0, j = 0;
        
        // 2. Count occurrences using two pointers
        while (j < nums.size()) {
            if (nums[i] == nums[j]) {
                j++;
            } else {
                int count = j - i;
                freq_list.push_back({count, nums[i]});
                i = j;
            }
        }
        // Handle the final group
        freq_list.push_back({j - i, nums[i]});
        
        // 3. Sort pairs by frequency in descending order
        sort(freq_list.rbegin(), freq_list.rend());
        
        // 4. Collect top k elements
        vector<int> result;
        for (int index = 0; index < k; ++index) {
            result.push_back(freq_list[index].second);
        }
        
        return result;
    }
};