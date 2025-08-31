class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
            
        int dup = x;
        int reversed_x = 0;
        while(x != 0)
        {
            int lastdigit = x % 10;
            x = x/10;

            if(reversed_x < INT_MIN/10 || (reversed_x == INT_MIN/10 && lastdigit < -8))
                return 0;
            if(reversed_x > INT_MAX/10 || (reversed_x == INT_MAX/10 && lastdigit > 7))
                return 0;

            reversed_x = reversed_x*10 + lastdigit;
        }

        if(reversed_x == dup)
            return true;
        else
            return false;
    }
};