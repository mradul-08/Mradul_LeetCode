class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();

        vector<vector<int>> t(n,vector<int>(n));

        for(int i =0; i<n; i++){
            t[i][i] =1;

        }
        for(int L =2 ; L <=n; L++){
            for(int i = 0; i < n-L+1; i++){
                int j = i + L -1;
            
            if(s[i] == s[j]){
                t[i][j] = 2+ t[i+1][j - 1 ];

            }
            else{
                t[i][j] = max(t[i][j - 1], t[i+1][j]);
            }
        }
        }
        return t[0][n -1 ];
    }
};