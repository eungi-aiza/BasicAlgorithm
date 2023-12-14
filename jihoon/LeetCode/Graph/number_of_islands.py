class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        def dfs(i,j):
            # Return when index out of range or element not "1"
            if i<0 or i>=len(grid) or j<0 or j>=len(grid[0]) or grid[i][j] != "1":
                return
            # Change "1" to "0"
            grid[i][j] = "0"

            # Recursively call dfs to search north, south, east, west
            dfs(i+1,j)
            dfs(i-1,j)
            dfs(i,j+1)
            dfs(i,j-1)

        count = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                # Root node to trigger dfs
                if grid[i][j] == "1":
                    # Recursively iterate through all adjacent 1's and change to '0' inplace
                    dfs(i,j)
                    count += 1
        return count