from functools import lru_cache


class Solution:
    def stoneGameVII(self, stones: List[int]) -> int:
        @lru_cache(None)
        def f(i, j):
            if i == j:
                return 0
            elif i == j - 1:
                return max(stones[i], stones[j])
            else:
                left = min(stones[i+1] + f(i+2, j), stones[j] + f(i+1, j-1))
                right = min(stones[i] + f(i+1, j-1), stones[j-1] + f(i, j-2))
                return max(left, right)
        return f(0, len(stones)-1)
