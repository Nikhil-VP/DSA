class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        open = ['(','{','[']
        for i in s:
            if i in open:
                stack.append(i)
            elif i == ')' and stack and stack[-1] == '(' :
                stack.pop()
            elif i == ']' and stack and stack[-1] == '[' :
                stack.pop()
            elif i == '}' and stack and stack[-1] == '{':
                stack.pop()
            else:
                return False
        if stack:
            return False 
        return True

        
        