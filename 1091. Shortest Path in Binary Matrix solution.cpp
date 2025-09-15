class Solution {
public:
    //can be solved using normal BFS
    //can also be solved using dijkstra (using queue because all the distances are unit distances so we dont need a priority queue)

    typedef pair<int, pair<int, int>> P;

    vector<vector<int>> directions {{0, -1}, {0, 1}, {-1, 0}, {1, 0}, {-1, -1}, {1, 1}, {1, -1}, {-1, 1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(m == 0 || n == 0 || grid[0][0] != 0)
            return -1;

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        queue<P> qu;
        qu.push({0, {0, 0}});
        result[0][0] = 0;

        while(qu.size() > 0)
        {
            int dist = qu.front().first;
            pair<int, int> p = qu.front().second;
            qu.pop();

            int x = p.first;
            int y = p.second;

            for(auto& dir : directions){
                int new_x = x + dir[0];
                int new_y = y + dir[1];

                if(new_x >= 0 && new_y >= 0 && new_x < m && new_y < n && grid[new_x][new_y] == 0 && dist + 1 < result[new_x][new_y])
                {
                    result[new_x][new_y] = dist + 1;
                    grid[new_x][new_y] = 1;
                    qu.push({dist + 1, {new_x, new_y}});
                }
            }
        }

        if(result[m-1][n-1] == INT_MAX)
            return -1;
        else 
            return result[m-1][n-1] + 1;
    }
};