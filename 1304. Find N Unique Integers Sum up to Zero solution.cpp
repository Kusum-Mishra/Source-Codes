class Solution {
public:
    //TC - O(n)
    //SC - O(n) only for returning answer
    vector<int> sumZero(int n) {
        vector<int> result(n);
        int start = 1;
        int i = 0, j = n-1;

        while(i < j)
        {
            result[i] = start;
            result[j] = -start;
            i++;
            j--;
            start++;
        } 
        return result;
    }
};