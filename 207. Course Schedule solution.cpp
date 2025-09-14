class Solution {
public:
    //detect cycle using dfs in DAG
    bool dfsCheck(int node, vector<vector<int>>& adjLs, vector<int>& visited, vector<int>& pathVisited)
    {
        visited[node] = 1;
        pathVisited[node] = 1;

        for(auto it : adjLs[node]){
            if(visited[it] == 0)
            {
                if(dfsCheck(it, adjLs, visited, pathVisited) == true)   return true;
            }
            else if(pathVisited[it] == 1)
                return true;
        }

        pathVisited[node] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses, 0);
        vector<int> pathVisited(numCourses, 0);

        vector<vector<int>> adjLs(numCourses);
        for(auto& it : prerequisites){
            int u = it[0];
            int v = it[1];
            adjLs[u].push_back(v);
        }

        for(int i=0; i<numCourses; i++)
        {
            if(visited[i]==0)
                if(dfsCheck(i, adjLs, visited, pathVisited) == true)
                    return false;
        }
        return true;
    }
};