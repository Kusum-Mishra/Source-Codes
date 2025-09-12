class Solution {
public:
    //TC - O(N) + O(V+E)
    //SC - O(N) visited + O(N) recursion
    void dfs(int node, vector<vector<int>>& adjList, vector<int>& visited)
    {
        visited[node] = 1;
        for(auto it : adjList[node])
        {
            if(!visited[it])
                dfs(it, adjList, visited);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjList(n);

        //to change adjacency matrix to list
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j && isConnected[i][j] == 1)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        int province = 0;
        vector<int> visited(n, 0);
        for(int i = 0; i < n; i++)
        {
            if(!visited[i]){
                province++;
                dfs(i, adjList, visited);
            }
        }

        return province;
    }
};