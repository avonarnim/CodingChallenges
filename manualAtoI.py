class Solution(object):
    def myAtoi(self, s):
        """
        :type s: str
        :rtype: int
        """
        i = 0
        while i < len(s) and s[i] == " ":
            i += 1
        neg = False
        if i < len(s):
            if s[i] == '-':
                neg = True
                i += 1
            elif s[i] == '+':
                neg = False
                i += 1
        print('neg ', neg)
        stringInts = ""
        while i < len(s) and s[i] in {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}:
            stringInts += s[i]
            i += 1
        if stringInts == "":
            return 0
        intInt = int(stringInts)
        intInt = -1*intInt if neg else intInt
        if intInt < -2147483648:
            intInt = -2147483648
        if intInt > 2147483647:
            intInt = 2147483647
        return intInt