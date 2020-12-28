class MinStack(object):
    
    class Node():
        def __init__(self, val, mini, nextNode):
            self.val = val
            self.min = mini
            self.next = nextNode
    
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.tail = None

    def push(self, x):
        """
        :type x: int
        :rtype: None
        """
        if self.tail == None:
            self.tail = self.Node(x, x, None)
        else:
            self.tail = self.Node(x, x if x < self.tail.min else self.tail.min, self.tail)

    def pop(self):
        """
        :rtype: None
        """
        self.tail = self.tail.next

    def top(self):
        """
        :rtype: int
        """
        return self.tail.val

    def getMin(self):
        """
        :rtype: int
        """
        return self.tail.min
    

# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()