class Solution:
    def maxSum(self, nums: List[int], k: int) -> int:
        MOD = 10 ** 9 + 7
        bits = 30

        count = [0] * bits
        res = 0

        for num in nums:
            b = 0
            while num > 0:
                if num & 1:
                    count[b] += 1
                
                num >>= 1
                b += 1
        
        for _ in range(k):
            curr = 0
            for b in range(30):
                if count[b] > 0:
                    count[b] -= 1
                    curr += (1 << b)
            
            res = (res + curr * curr) % MOD
        return res 

