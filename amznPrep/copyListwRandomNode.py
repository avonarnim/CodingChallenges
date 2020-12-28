"""
# Definition for a Node.
class Node:
    def __init__(self, x, next=None, random=None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution(object):
    visited = {}
    
    def copyRandomList(self, head):
        """
        :type head: Node
        :rtype: Node
        """
        if head == None:
            return None
        elif head in self.visited:
            return self.visited[head]
        
        newHead = Node(head.val)
        
        self.visited[head] = newHead

        newHead.next = self.copyRandomList(head.next)
        newHead.random = self.copyRandomList(head.random)
            
        return newHead
        