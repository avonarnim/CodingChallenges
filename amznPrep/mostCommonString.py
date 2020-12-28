class Solution(object):
    def mostCommonWord(self, paragraph, banned):
        """
        :type paragraph: str
        :type banned: List[str]
        :rtype: str
        """
        words = ''.join([c.lower() if c.isalnum() else ' ' for c in paragraph])
        words=words.split()
        
        seen = {}
        for word in words:
            if word in seen:
                seen[word] += 1
            elif word not in banned:
                seen[word] = 1
                
        maxWord = ""
        maxTimes = 0
        for key, value in seen.items():
            if value > maxTimes and key not in banned:
                maxWord = key
                maxTimes = value
        return maxWord
        