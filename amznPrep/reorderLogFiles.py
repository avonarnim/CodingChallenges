class Solution(object):
    def reorderLogFiles(self, logs):
        """
        :type logs: List[str]
        :rtype: List[str]
        """
        
        letLog = [log for log in logs if log.split()[1].isalpha()]
        digLog = [log for log in logs if not log.split()[1].isalpha()]

        def compare(x):
            xArr = x.split()
            key, rest = xArr[0], xArr[1:]
            return ' '.join(rest) + ' ' + key
        letLog.sort(key=compare)
        return letLog + digLog
    