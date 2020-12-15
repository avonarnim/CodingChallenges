class Solution(object):
    def convert(self, line):
        """
        :type s: str
        :type numRows: int
        :rtype: str

        line contains a line of words and spaces. Capitalize every word
        """
        if len(line) == 0:
            return ""
        line = line.capitalize()
        for i in range(len(line)):
            if line[i] == " " and i != len(line)-1:
                temp = line[i+1:]
                line = line[:i+1] + temp.capitalize()
        return line