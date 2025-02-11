class Solution(object):
    def removeOccurrences(self, s, part):
        while True:
            idx = s.find(part)
            if(idx == -1):
                break
            s = s[:idx]+s[idx+len(part):]
        return s
        """
        :type s: str
        :type part: str
        :rtype: str
        """
        