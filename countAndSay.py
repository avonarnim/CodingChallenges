class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        if n == 1:
            return "1"
        else:
            return str(self.wayToSay(self.countAndSay(n-1)))
        
    def wayToSay(self, rawString):
        if not type(rawString) == str:
            rawString = str(rawString)
        saying = ""
        val = 0
        count = 0
        
        for i in rawString:
            if val == i:
                count += 1
            else:
                if count != 0:
                    saying += str(count) + str(val)
                val = i
                count = 1
        if count != 0:
            saying += str(count) + str(val)
        return int(saying)