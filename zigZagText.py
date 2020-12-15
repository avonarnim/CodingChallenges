class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1:
            return s
        mod = numRows*2-2
        sections = []
        for i in range(len(s)/mod+1):
            sections.append(s[i*mod:i*mod+mod])
        print(sections)
        output = ""
        for i in range(numRows):
            for j in range(len(sections)):
                if len(sections[j]) != 0:
                    output += sections[j][0]
                    sections[j] = sections[j][1:] if len(sections[j]) > 1 else ""
                print(sections[j], ' ', (numRows-i)*2-2)
                if len(sections[j]) >= (numRows-i)*2-2 and i != 0 and i != numRows-1:
                    print('in here')
                    output += sections[j][-1]
                    sections[j] = sections[j][:-1] if len(sections[j]) > 1 else ""
        return output