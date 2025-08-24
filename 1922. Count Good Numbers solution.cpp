class Solution {
public:
    int findPower(long long a, long long b)
    {
        int mod = 1e9 + 7;
        if(b == 0)
            return 1;

        long long half = findPower(a, b/2);
        long long result = (half * half) % mod;

        if(b % 2 == 1){
            result = (result * a) % mod;
        }
        
        return result;  
    }

    int countGoodNumbers(long long n) {
        int mod = 1e9 + 7;
        long long evenPos = (n + 1)/2;
        long long oddPos = n/2;

        return ((long long)findPower(5, evenPos) * findPower(4, oddPos)) % mod;
    }
};