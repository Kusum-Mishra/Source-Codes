class Solution {
public:
    //TC - O(m * n)
    //SC - O(m * n)
    
    vector<vector<int>> directions {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    bool isSafe(int x, int y, vector<vector<int>>& grid)
    {
        return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 1;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        int freshOranges = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2)
                    q.push({i, j});
                else if(grid[i][j] == 1)
                    freshOranges++;
            }
        }

        if(freshOranges == 0)
            return 0;

        int minutes = 0;
        while(q.size() > 0)
        {
            int size = q.size();
            while(size--)
            {
                pair<int, int> curr = q.front();
                q.pop();
                int i = curr.first;
                int j = curr.second;

                for(auto& dir : directions)
                {
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];

                    if(isSafe(new_i, new_j, grid)){
                        grid[new_i][new_j] = 2;
                        q.push({new_i, new_j});
                        freshOranges--;
                    }
                }
            }
            minutes++;
        }

        return freshOranges == 0 ? minutes - 1 : -1;
    }
};