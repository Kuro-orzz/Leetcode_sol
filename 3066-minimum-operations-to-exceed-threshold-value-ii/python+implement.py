from heapq import *

class Solution(object):
    def minOperations(self, nums, k):
        heapify(nums)
        ans = 0
        while True:
            x = heappop(nums)
            if x >= k: return ans
            else:
                y = heappop(nums)
                heappush(nums, min(x, y)*2 + max(x, y))
                ans += 1
        return 0
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        