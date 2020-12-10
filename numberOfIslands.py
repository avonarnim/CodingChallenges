import collections

class Solution(object):
    
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        islands = 0
        visited = set()
        rows, cols = len(grid), len(grid[0])
        
        def bfs(i, j):
            q = collections.deque()
            q.append((i,j))
            directions = [[0,1], [1,0], [0,-1], [-1, 0]]
            
            while q:
                (i,j) = q.popleft()
                print('popped left')
                for dr, dc in directions:
                    r = dr+i
                    c = dc+j
                    if (not (r,c) in visited and
                        r in range(rows) and
                        c in range(cols) and
                        grid[r][c] == "1"):
                            print('r' + str(r), 'c' + str(c))
                            q.append((r,c))
                            visited.add((r,c))
                            print(q)
        
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == "1" and not (i,j) in visited:
                    print('i' + str(i), 'j' + str(j))
                    visited.add((i,j))
                    bfs(i, j)
                    islands += 1
        print(visited)
                    
        return islands
        