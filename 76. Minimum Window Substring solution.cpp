class Solution {
public:
    //TC - O(n) + O(2m)
    //SC - O(256)
    string minWindow(string s, string t) {
        int hash[256] = {0};
        int left = 0, right = 0, count = 0;
        int minLen = 1e9;
        int startInd = -1;
        int m = s.size(), n = t.size();
        
        for(int i = 0; i < n; i++)      //O(n)
            hash[t[i]]++;

        while(right < m)        //O(m)
        {
            if(hash[s[right]] > 0)
                count++;

            hash[s[right]]--;

            while(count == n)       //O(m)
            {
                int len = right - left + 1;
                if(len < minLen)
                {
                    minLen = len;
                    startInd = left;
                }
                hash[s[left]]++;
                if(hash[s[left]] > 0 )
                    count--; 
                
                left++;
            }
            right++;
        }

        return (startInd == -1 ? "" : s.substr(startInd, minLen));
    }
};