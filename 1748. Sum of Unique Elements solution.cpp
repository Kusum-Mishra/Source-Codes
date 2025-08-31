class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int freqArr[101] = {0};
        int n = nums.size();
        for(int i=0; i < n; i++)
            freqArr[nums[i]]++;
            
        int sum = 0;
        for(int i = 0; i < 101; i++)
        {
            if(freqArr[i] == 1)
                sum += i;
        }

        return sum;
    }
};