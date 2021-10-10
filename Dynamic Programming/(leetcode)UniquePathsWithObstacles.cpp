class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        int dp[row][col];
        memset(dp, 0, sizeof dp);
        
        if(obstacleGrid[0][0] == 1){       //Returning 0 if (0,0) element is obstacle
            return 0;
        }
        
        for(int i=0; i < row; i++){        //Marking ways for 1st col
            if(obstacleGrid[i][0] == 0){
                dp[i][0] = 1;
            }else{
                i = row;
            }
        }
        
        for(int i=0; i < col; i++){        //Marking ways for 1st row
            if(obstacleGrid[0][i] == 0){
                dp[0][i] = 1;
            }else{
                i = col;
            }
        }
        
        
        for(int i=1; i < row; i++){        //Traversing through grid and finding number of unique paths to destination
            for(int j=1; j < col; j++){    
                
                if(!obstacleGrid[i][j]){
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        
        return dp[row-1][col-1];
    }
};
