from collections import Counter

class Solution:
    def largestInteger(self, nums: List[int], k: int) -> int:
        n = len(nums)
        # Maps each element to the count of size-k subarrays it appears in
        subarray_counts = Counter()
        
        # Iterate over all possible starting indices for subarrays of size k
        for i in range(n - k + 1):
            # Use a set to ensure each element is counted once per subarray
            unique_in_subarray = set(nums[i : i + k])
            for num in unique_in_subarray:
                subarray_counts[num] += 1
        
        # Find the maximum element that appears in exactly 1 subarray
        ans = -1
        for num, count in subarray_counts.items():
            if count == 1:
                ans = max(ans, num)
                
        return ans