class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """

        seen = {}
        for i in range(len(s)):
            if s[i] not in seen:
                seen[s[i]] = (True, i)
            else:
                seen[s[i]] = (False, i)
        
        minVal = len(s)
        for _, value in seen.items():
            minVal = value[1] if (value[0] == True and value[1] < minVal) else minVal
        if minVal == len(s):
            return -1
        return minVal
        