from queue import PriorityQueue

class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        pq = PriorityQueue()
        for x in nums:
            pq.put(x)
        ans = 0
        while True:
            x = pq.get()
            if x >= k: return ans
            else:
                y = pq.get()
                pq.put(min(x, y)*2 + max(x, y))
                ans += 1
        return 0