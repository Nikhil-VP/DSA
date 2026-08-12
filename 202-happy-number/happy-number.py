class Solution:
    def isHappy(self, n: int) -> bool:
        
        def sos(n):
            sum=0
            m=0
            while n>0:
                m=n%10
                sum = sum + m*m
                n=n//10
            return sum
        seen = set()
        while n!=1 and n not in seen:
            seen.add(n)
            n = sos(n)
        return n == 1
        
            

        


        

        