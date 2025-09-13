class Solution {
public:
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& visited)
    {
        visited[row][col] = -1;
        int m = grid.size();
        int n = grid[0].size();

        for(auto& dir : directions){
            int new_i = row + dir[0];
            int new_j = col + dir[1];

            if(new_i >= 0 && new_j >= 0 && new_i < m && new_j < n && visited[new_i][new_j] != -1 && grid[new_i][new_j] == '1'){
                dfs(new_i, new_j, grid, visited);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));

        int islands = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1' && visited[i][j] != -1){
                    islands++;
                    dfs(i, j, grid, visited);
                }
            }
        }
        return islands;
    }
};