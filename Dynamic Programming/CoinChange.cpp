#include<iostream>
using namespace std;

//Top Down Approach
int coinChange(int n, int coins[], int len, int dp[]){
    //Base Case
    if(n == 0){
        return 0;
    }

    //Look Up
    if(dp[n] != 0){
        return dp[n];
    }

    //Recursive Case
    int minCoins = INT8_MAX;

    for(int i=0; i < len; i++){
        if(n-coins[i] >= 0){
            int numOfCoins = coinChange(n-coins[i], coins, len, dp);
            if(numOfCoins < minCoins){
                minCoins = numOfCoins;
            }
        }
    }
    dp[n] = minCoins + 1;
    return dp[n];
}

//Bottom Up Approach
int coinChangeBottomUp(int n, int coins[], int len){
    int dp[1000] = {0};
    int minCoins;

    for(int i=1; i <= n; i++){
        int minCoins = INT8_MAX;
        for(int j=0; j < len; j++){
            if(i-coins[j] >= 0){
                minCoins = min(minCoins, dp[i-coins[j]]);
            }
        }
        dp[i] = minCoins + 1;
    }

    return dp[n];
}

int main(){
    int n, m;
    cin>>n;
    cin>>m;
    int coins[m];
    for(int i=0; i < m; i++){
        cin>>coins[i];
    }
    int dp[1000] = {0};

    int len = sizeof(coins)/sizeof(coins[0]);

    //cout<<coinChange(n, coins, len, dp);
    cout<<coinChangeBottomUp(n, coins, len);

    return 0;
}