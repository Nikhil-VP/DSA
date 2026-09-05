// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int i,j;int req;
//         vector<int> arr(2);
//         for(i=0;i < nums.size();i++)
//         {
//             req = target - nums[i];
//             for(j=i+1; j<nums.size();j++)
//             {
//                 if(req == nums[j])
//                 {
//                     arr[0] = i;
//                     arr[1] = j;
//                 }
//             }
//         }
//         return arr;
//     }
// };
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> num_map; 
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
    
            if (num_map.find(complement) != num_map.end()) {
                return {num_map[complement], i};
            }
 
            num_map[nums[i]] = i;
        }
        
        return {};
    }
};