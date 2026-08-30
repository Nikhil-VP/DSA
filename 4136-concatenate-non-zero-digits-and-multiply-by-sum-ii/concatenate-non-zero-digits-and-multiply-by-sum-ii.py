from bisect import bisect_left, bisect_right
from typing import List

class Solution:
    def sumAndMultiply(self, s: str, queries: List[List[int]]) -> List[int]:
        MOD = 10**9 + 7
        
        nz_digits = []
        nz_indices = []
        
        for i, char in enumerate(s):
            if char != '0':
                nz_digits.append(int(char))
                nz_indices.append(i)
                
        m = len(nz_digits)
        pow10 = [1] * (m + 1)
        val_pref = [0] * (m + 1)
        sum_pref = [0] * (m + 1)
        
        for i in range(m):
            pow10[i + 1] = (pow10[i] * 10) % MOD
            val_pref[i + 1] = (val_pref[i] * 10 + nz_digits[i]) % MOD
            sum_pref[i + 1] = sum_pref[i] + nz_digits[i]
            
        ans = []
        for l, r in queries:
            L = bisect_left(nz_indices, l)
            R = bisect_right(nz_indices, r) - 1
            
            if L > R:
                ans.append(0)
                continue
                
            length = R - L + 1
            x = (val_pref[R + 1] - val_pref[L] * pow10[length]) % MOD
            digit_sum = sum_pref[R + 1] - sum_pref[L]
            
            ans.append((x * digit_sum) % MOD)
            
        return ans