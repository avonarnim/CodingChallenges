class Solution(object):
    def expand_around_center(self, s, currPali, l, r):
        currPali = currPali
        print(l, r)
        while l >= 0 and r < len(s):
            if s[l] == s[r]:
                currPali = s[l] + currPali + s[r]
                l -= 1
                r += 1
            else:
                break
        return currPali
        
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        maxPali = ""
        for curr in range(len(s)):
            print(curr)
            i = curr-1
            j = curr+1
            # curr is center
            currPali = self.expand_around_center(s, s[curr], i, j)
            maxPali = currPali if len(currPali) > len(maxPali) else maxPali
            
            # curr is lower of pair
            up = curr + 1
            if up < len(s) and s[up] == s[curr]:
                i = curr-1
                j = up+1
                currPali = self.expand_around_center(s, s[curr]+s[up], i, j)
                maxPali = currPali if len(currPali) > len(maxPali) else maxPali
            
            # curr is upper of pair
            low = curr - 1
            if low >= 0 and s[low] == s[curr]:
                i = low-1
                j = curr+1
                currPali = self.expand_around_center(s, s[low]+s[curr], i, j)
                maxPali = currPali if len(currPali) > len(maxPali) else maxPali
        return maxPali
        