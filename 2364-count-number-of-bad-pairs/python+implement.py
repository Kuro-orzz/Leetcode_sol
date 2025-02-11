class Solution(object):
    def countBadPairs(self, nums):
        n = len(nums)
        mp = dict()
        for i in range(n):
            mp[nums[i]-i] = mp.get(nums[i]-i, 0) + 1
        ans = n*(n-1)/2
        for y in mp.values():
            ans -= y*(y-1)/2
        return ans
        """
        :type nums: List[int]
        :rtype: int
        """
        