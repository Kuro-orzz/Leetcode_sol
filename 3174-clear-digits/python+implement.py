class Solution(object):
    def clearDigits(self, s):
        a = []
        for i in range(len(s)):
            if s[i] >= 'a' and s[i] <= 'z':
                a.append(s[i])
            elif len(a):
                a.pop()
            else:
                a.append(s[i])
        return "".join(a)
        """
        :type s: str
        :rtype: str
        """
        