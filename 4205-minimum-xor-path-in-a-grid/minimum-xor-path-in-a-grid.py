class Solution:
    def minCost(self, grid: list[list[int]]) -> int:
        m, n = len(grid), len(grid[0])

        dp = [[set() for _ in range(n)] for _ in range(m)]
        dp[0][0].add(grid[0][0])

        q = {(0, 0)}

        while q:
            tq = set()

            for i, j in q:
                if i + 1 < m:
                    for x in dp[i][j]:
                        dp[i + 1][j].add(x ^ grid[i + 1][j])

                    tq.add((i + 1, j))
                
                if j + 1 < n:
                    for x in dp[i][j]:
                        dp[i][j + 1].add(x ^ grid[i][j + 1])

                    tq.add((i, j + 1))

            q = tq

        return min(dp[-1][-1])