class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adjRev(n);
        vector<int> indegree(n);

        for(int u=0; u<n; u++){
            for(auto v : graph[u]){
                adjRev[v].push_back(u);
                indegree[u]++;
            }
        }

        queue<int> q;
        vector<int> safe;

        for(int i=0; i<n; i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            safe.push_back(node);

            for(auto it : adjRev[node])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }

        sort(safe.begin(), safe.end());
        return safe;

    }
};