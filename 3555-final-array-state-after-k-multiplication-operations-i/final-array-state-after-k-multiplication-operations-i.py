class Solution:
    
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        while k != 0:    
            min_pos = 0
            for i in range(0,len(nums)):
                if nums[i] < nums[min_pos]:
                    min_pos = i
            nums[min_pos] = nums[min_pos]*multiplier
            k -= 1
        return nums
            