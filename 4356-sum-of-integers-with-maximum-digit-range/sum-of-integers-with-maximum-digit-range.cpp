// class Solution {
// public:
//     int diff(int num){
//         int mindigit = 1e9,maxdigit = 0;
//         int rem;
//         while(num!=0){
//             rem = num % 10;
//             mindigit = min(mindigit, rem);
//             maxdigit = max(maxdigit, rem);
//             num = num /10;
//         }
//         // cout << maxdigit << mindigit <<"\n";
//         return (maxdigit - mindigit);
//     }
//     int maxDigitRange(vector<int>& nums) {
//         vector<pair<int , int>> digit;
//         int maxrange=0,sum =0 ;
//         for(int i=0;i < nums.size();i++){
//             digit[i]. = diff(nums[i]);
//             maxrange = max(maxrange,digit[nums[i]]);
//         }
//         for(const auto& [digits,value] : digit){
//             // cout << digits << value;
//             if(value == maxrange){
//                 sum += digits;
//             }
//         }
//         return sum;

//     }
// };
class Solution {
public:
    int diff(int num) {
        int mindigit = 10, maxdigit = 0;
        
        while (num > 0) {
            int rem = num % 10;
            mindigit = min(mindigit, rem);
            maxdigit = max(maxdigit, rem);
            num /= 10;
        }
        
        return maxdigit - mindigit;
    }

    int maxDigitRange(vector<int>& nums) {
        int maxrange = -1;
        long long sum = 0;

        // Step 1: Find the maximum digit range across all numbers
        for (int num : nums) {
            maxrange = max(maxrange, diff(num));
        }

        // Step 2: Sum all numbers (including duplicates) that match the maximum range
        for (int num : nums) {
            if (diff(num) == maxrange) {
                sum += num;
            }
        }

        return sum;
    }
};