class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, len = 0, maxLen = 0;
        int n = s.size();
        int hash[256];
        memset(hash, -1, sizeof(hash));

        if(n == 0)
            return 0;

        while(right < n)
        {
            if(hash[s[right]] != -1)
            {
                if(hash[s[right]] >= left)
                    left = hash[s[right]] + 1;
            }

            len = right - left + 1;
            maxLen = max(len, maxLen);

            hash[s[right]] = right;
            right++;
        }

        return maxLen;
    }
};