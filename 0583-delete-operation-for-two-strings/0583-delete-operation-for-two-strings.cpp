class Solution {
public:
    vector<vector<int>> dp;

    int helper(string& w1, string& w2, int i, int j) {

        // Both strings finished
        if (i == w1.size() && j == w2.size())
            return 0;

        // One string finished
        if (i == w1.size() || j == w2.size())
            return max((int)w1.size() - i, (int)w2.size() - j);

        // Already computed
        if (dp[i][j] != -1)
            return dp[i][j];

        // Characters match
        if (w1[i] == w2[j])
            return dp[i][j] = helper(w1, w2, i + 1, j + 1);

        // Delete from either string
        return dp[i][j] = 1 + min(
            helper(w1, w2, i + 1, j),   // delete w1[i]
            helper(w1, w2, i, j + 1)    // delete w2[j]
        );
    }

    int minDistance(string word1, string word2) {

        dp.resize(word1.size() + 1,
                  vector<int>(word2.size() + 1, -1));

        return helper(word1, word2, 0, 0);
    }
};