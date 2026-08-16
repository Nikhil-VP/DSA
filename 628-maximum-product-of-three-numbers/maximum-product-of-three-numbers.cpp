// class Solution {
// public:
//     int maximumProduct(vector<int>& nums) {
//         sort(nums.rbegin(),nums.rend());// if no sort O(n)
//         int n = nums.size();
//         long long maxpro = 0;
//         if(nums[n-1] < 0 && nums[n-2] < 0 )
//         {
//            maxpro = max(nums[n-1] * nums[n-2] * nums[0], nums[2] * nums[1] * nums[0]);

//         }
//         else{
//             maxpro =nums[2] * nums[1] * nums[0] ;
//         }

//         return maxpro;
//     }
// };
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;
        
        for (int n : nums) {
            // Update the top 3 largest values
            if (n > max1) {
                max3 = max2;
                max2 = max1;
                max1 = n;
            } else if (n > max2) {
                max3 = max2;
                max2 = n;
            } else if (n > max3) {
                max3 = n;
            }
            
            // Update the top 2 smallest values
            if (n < min1) {
                min2 = min1;
                min1 = n;
            } else if (n < min2) {
                min2 = n;
            }
        }
        
        // Return the maximum of:
        // 1. Three largest numbers
        // 2. Two smallest numbers (large negatives) * largest number
        return max(max1 * max2 * max3, min1 * min2 * max1);
    }
};