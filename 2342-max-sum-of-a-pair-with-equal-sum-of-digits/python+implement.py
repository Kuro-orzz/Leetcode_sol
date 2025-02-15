class Solution(object):
    def sumDigit(self, num):
        return sum(int(x) for x in str(num))

    def cmp(self, a, b):
        if(a[0] != b[0]): return a[0] - b[0]
        return a[1] - b[1]

    def maximumSum(self, nums):
        a = []
        for x in nums:
            a.append(tuple((self.sumDigit(x), x)))
        a.sort(self.cmp)
        ans = -1
        for i in range(1, len(a)):
            if a[i][0] == a[i-1][0]:
                ans = max(ans, a[i][1]+a[i-1][1])
        return ans

        """
        :type nums: List[int]
        :rtype: int
        """
        