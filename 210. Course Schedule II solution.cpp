class Solution {
public:
    //using toposort (using bfs) - if there are all elements in the topo sort then true;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjLs(numCourses);
        for(auto it : prerequisites)
        {
            int u = it[0];
            int v = it[1];
            adjLs[v].push_back(u);
        }

        vector<int> inDegree(numCourses);
        for(int i=0; i<numCourses; i++)
        {
            for(auto& it : adjLs[i])
                inDegree[it]++;
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(inDegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto& it : adjLs[node])
            {
                inDegree[it]--;
                if(inDegree[it] == 0)
                    q.push(it);
            }
        }

        if(topo.size() == numCourses)   return topo;
        else    return {}; 
    }
};