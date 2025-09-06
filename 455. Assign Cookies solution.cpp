class Solution {
public:
    /*int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size(), m = s.size();
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int j = 0, count = 0;
        for(int i=0; i<n && j<m ; i++)
        {
            if(i <= j && g[i] <= s[j])
            {
                count++;
                j++;
            }
            else
            {
                while(j < m && g[i] > s[j]) 
                    j++;
                if(j < m){
                    count++;
                    j++;
                }
            }
            
        }
        return count;
    }*/

    int findContentChildren(vector<int>& g, vector<int>& s)
    {
        int n = g.size(), m = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0, count = 0;
        while(i < n && j < m)
        {
            if(g[i] <= s[j])
            {
                count++;
                i++;
            }
            j++;
        }

        return count;
    }
};