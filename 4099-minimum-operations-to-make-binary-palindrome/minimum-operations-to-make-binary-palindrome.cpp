// class Solution {
// public:
    
//     vector<int> minOperations(vector<int>& nums) {
//         vector<long long> binary;
//         vector<int> ans;
//     for (int i = 1; i < 100000; i++) {
//         int n = i;
//         string str = "";
        
//         // Convert to binary string
//         while (n > 0) {
//             str += to_string(n % 2);
//             n /= 2;
//         }
        
//         // Check if the binary string is a palindrome
//         string reversed = str;
//         reverse(reversed.begin(), reversed.end());
        
//         if (str == reversed) {
//             binary.push_back(i); 
//         }
//     }

//     //     for (const auto& numi : binary) {
//     //     cout << numi << " ";
//     // }
//         for(int x:nums){
//             auto it = lower_bound(binary.begin(),binary.end(),x);
//             long long min_ops = abs(*it - x);
//             if(it!=binary.begin()){
//                 min_ops = min(min_ops, abs(*(it -1)-x));
//             }
//             ans.push_back(min_ops);
//         }

//         return ans;
//     }
// };
#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
private:
    // Fast bitwise binary palindrome check
    static bool isBinaryPalindrome(int n) {
        int original = n;
        int reversed = 0;
        while (n > 0) {
            reversed = (reversed << 1) | (n & 1);
            n >>= 1;
        }
        return original == reversed;
    }

    // Precompute palindromes once across all test cases
    static const std::vector<int>& getPalindromes() {
        static std::vector<int> binary;
        if (binary.empty()) {
            for (int i = 1; i <= 100000; ++i) {
                if (isBinaryPalindrome(i)) {
                    binary.push_back(i);
                }
            }
        }
        return binary;
    }

public:
    std::vector<int> minOperations(std::vector<int>& nums) {
        const auto& binary = getPalindromes();
        std::vector<int> ans;
        ans.reserve(nums.size());

        for (int x : nums) {
            auto it = std::lower_bound(binary.begin(), binary.end(), x);
            
            long long min_ops = std::abs(static_cast<long long>(*it) - x);
            if (it != binary.begin()) {
                min_ops = std::min(min_ops, std::abs(static_cast<long long>(*(it - 1)) - x));
            }
            ans.push_back(min_ops);
        }

        return ans;
    }
};