# Adam Interview

class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        low = prices[0]

        diff = 0

        for i in range(len(prices)):
          if (prices[i] < low):
            low = prices[i]
          elif prices[i]-low > diff:
            diff = prices[i]-low

        return diff

# input: [7,1,5,3,6,4]  output: 5
# input: [7,6,4,3,1] output: 0
