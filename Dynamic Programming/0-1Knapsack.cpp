int knapsack(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
    int dp[n+1][w+1];
    
    for(int i=0; i < n+1; i++){
        for(int j=0; j < w+1; j++){
            if(i == 0 || j == 0){               // initialising matrix
                dp[i][j] = 0;
            }
            else if(weights[i-1] <= j){
                dp[i][j] = max((values[i-1] + dp[i-1][j - weights[i-1]]), dp[i-1][j]);        //main process
            }
            else if(weights[i-1] > j){
                dp[i][j] = dp[i-1][j];          // excluding element if weight is greater than sack capacity
            }
        }
    }
    
    return dp[n][w];
}

