class Solution {
public:
    //TC - O(2^2n * 2n)
    //SC - O(2n)
    bool isValid(string& curr)
    {
        int count = 0;
        for(char ch : curr)
        {
            if(ch == '(')
                count++;
            else
                count--;
            if(count < 0)
                return false;
        }

        return count == 0 ? true : false;
    }
    void solve(string& curr, int n, vector<string>& result)
    {
        if(curr.size() == 2*n)
        {
            if(isValid(curr))
                result.push_back(curr);
            return;
        }

        curr.push_back('(');
        solve(curr, n, result);
        curr.pop_back();

        curr.push_back(')');
        solve(curr, n, result);
        curr.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string curr = "";
        solve(curr, n, result);
        return result;
    }
};