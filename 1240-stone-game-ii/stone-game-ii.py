class Solution:

    def stoneGameII(self, piles: List[int]) -> int:
        dp= {}
        def dfs( Alice, i ,M):
            if i == len(piles):
                return 0
            if (Alice, i ,M) in dp:
                return dp[(Alice , i ,M)]
            res = 0 if Alice else float("inf")
            total = 0
            for X in range(1, 2*M+1):
                if i+X > len(piles):
                    break
                total += piles[i + X -1]
                if Alice:
                    res = max(res, total+ dfs(not Alice, i + X,max(M,X)))
                else:
                    res = min(res, dfs(not Alice, i+X,max(M,X)))
                dp[(Alice , i ,M)] = res


            return res
        return dfs(True , 0 ,1)