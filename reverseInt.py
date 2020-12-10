class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        isNeg = False
        if x < 0:
            isNeg = True
        x = abs(x)
        stringVersion = str(x)
        stringVersionReverse = stringVersion[::-1]
        intReverse = int(stringVersionReverse)
        intReverse = (-1)*intReverse if isNeg else intReverse
        if intReverse > (2**31 - 1) or intReverse < -(2**31):
            intReverse = 0
        return intReverse
        