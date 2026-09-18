class Solution:
    def maxDepth(self, s: str) -> int:
        counter = 0
        maxcount =0
        for c in s:
            if c == '(':
                counter +=1
                maxcount = max(maxcount , counter)
            if c == ')':
                counter -=1
        return maxcount