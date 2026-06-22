class Solution {
private:
    vector<vector<long long>> dp;

    long long f(int i, int j, string &s, string &t) {

        // If t is completely formed
        if (j < 0)
            return 1;

        // s is exhausted but t is not formed
        if (i < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        // Characters match
        if (s[i] == t[j]) {
            return dp[i][j] =
                f(i - 1, j - 1, s, t) +   // take
                f(i - 1, j, s, t);        // not take
        }

        // Characters don't match
        return dp[i][j] = f(i - 1, j, s, t);
    }

public:
    int numDistinct(string s, string t) {

        int n = s.size();
        int m = t.size();

        dp.resize(n, vector<long long>(m, -1));

        return f(n - 1, m - 1, s, t);
    }
};