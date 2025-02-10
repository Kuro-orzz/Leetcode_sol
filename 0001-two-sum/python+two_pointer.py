class Solution(object):
    def twoSum(self, nums, target):
        a = list()
        for i in range(len(nums)):
            a.append(tuple((nums[i], i)))
        a.sort()
        p1, p2 = 0, len(a)-1
        while p1 < p2:
            if a[p1][0] + a[p2][0] < target:
                p1 += 1
            elif a[p1][0] + a[p2][0] > target:
                p2 -= 1
            else:
                return [a[p1][1], a[p2][1]]
        return [0, 0]

        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        