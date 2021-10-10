class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int dp[row][col];

        for(int i=0; i < row; i++){
            for(int j=0; j < col; j++){
                
                if(i==0 && j==0){                         //For 1st element
                    dp[i][j] = grid[0][0];
                }
                else if(i == 0){                          //For 1st Row
                    dp[i][j] = dp[0][j-1] + grid[0][j];
                }
                else if(j == 0){                          //For 1st Col
                    dp[i][j] = dp[i-1][0] + grid[i][0];
                }
                else{
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
                }
            }
        }
        
        return dp[row-1][col-1];
    }
};
