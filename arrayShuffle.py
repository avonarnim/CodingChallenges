import random 

class Solution(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.base = []
        for i in range(len(nums)):
            self.base.append(nums[i])

    def reset(self):
        """
        Resets the array to its original configuration and return it.
        :rtype: List[int]
        """
        return self.base
        

    def shuffle(self):
        """
        Returns a random shuffling of the array.
        :rtype: List[int]
        """
        toReturn = []
        indicesToPick = [i for i in range(len(self.base))]
        while len(indicesToPick) != 0:
            randVal = random.randint(0, len(indicesToPick)-1)
            toReturn.append(self.base[indicesToPick[randVal]])
            del indicesToPick[randVal]
        return toReturn
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()