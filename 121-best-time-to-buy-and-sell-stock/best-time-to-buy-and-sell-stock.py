class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxp = 0
        curr = prices[0]
        for i in range(0,len(prices)):
            cost = prices[i] - curr
            maxp = max(maxp,cost)
            curr = min(curr,prices[i])
        return maxp


        



