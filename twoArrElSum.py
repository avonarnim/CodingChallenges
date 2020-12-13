class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                pairwiseSum = nums[i] + nums[j]
                if pairwiseSum == target:
                    return [i,j]
        
        