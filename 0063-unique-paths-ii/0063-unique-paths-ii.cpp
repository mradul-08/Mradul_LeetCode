class Solution {
public:
int m, n;
int t [101][101];

int solve(int i, int j, vector<vector<int>>& grid){
    if(i < 0 || i >=m || j < 0 || j >=n || grid[i][j] == 1){
        return 0;
    }

    if(i == m-1 && j == n-1){
        return 1;
    }
    if(t[i][j] != -1){
        return t[i][j];
    }

    int right = solve(i, j+1, grid);
    int down = solve(i +1, j, grid);

    return t[i][j] = right + down;

}

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(t, -1, sizeof(t));
   
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();

        return solve(0, 0,obstacleGrid );
    }
};