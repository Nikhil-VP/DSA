class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        if s == goal:
            return True
        if goal in s:
            return False
        s = s + s
        if goal in s:
            return True
        else:
            return False