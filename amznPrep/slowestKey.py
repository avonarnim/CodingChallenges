class Solution(object):
    def slowestKey(self, releaseTimes, keysPressed):
        """
        :type releaseTimes: List[int]
        :type keysPressed: str
        :rtype: str
        """
        maxDuration = releaseTimes[0]
        maxKey = keysPressed[0]
        print(maxDuration)
        for i in range(1, len(keysPressed)):
            duration = releaseTimes[i]-releaseTimes[i-1]
            if duration > maxDuration:
                maxDuration = duration
                maxKey = keysPressed[i]
            elif duration == maxDuration:
                if keysPressed[i] > maxKey:
                    maxKey = keysPressed[i]
        return maxKey
        