class Solution():
    self.possible = {str(i) for i in range(1, 27)}
    
    def countNumWays(encoded):
        ways = 0
        if len(encoding) > 0 and encoding[0] in self.possible:
            ways += 1 + countNumWays(encoded[1:])
        if len(encoding) > 1 and encoding[:2] in self.possible:
            ways += 1 + countNumWays(encoded[2:])
        return ways

    def convert(self, encoded):
        """
        :type s: str
        :type numRows: int
        :rtype: str

        encoding is {1:A, 2:B, ..., 26:Z}
        Use dynamic programming to detect how many ways the passed-string of int chars, 'encoded', can be interpreted
        """
        result = self.countNumWays(encoded)
        print(result)
        return result

Solution().convert(11)