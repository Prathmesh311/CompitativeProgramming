#include<iostream>
using namespace std;

//Top Down Approach
int ladderTopDown(int n,int k, int dp[]){
    //Base Case
    if(n == 0){
        return 1;
    }

    //Look Up
    if(dp[n] != 0){
        return dp[n];
    }

    //Recursive Case
    int ways = 0;
    for(int i=1; i <= k; i++){
        if(n-i >= 0){
            ways += ladderTopDown(n-i, k, dp);
        }
    }
    dp[n] = ways;
    return dp[n];
}

//Bottom Up Approach
int ladderBottomUp(int n, int k){
    int dp[100] = {0};

    dp[0] = 1;

    for(int i=1; i <= n; i++){
        for(int j=1; j <= k; j++){
            if(i - j >= 0){
                dp[i] += dp[i-j];
            }
        }
    }

    return dp[n];
}

int main(){
    int n,k;
    cin>>n>>k;
    int dp[100] = {0};

    //cout<<ladderTopDown(n, k, dp);
    cout<<ladderBottomUp(n, k);

    return 0;
}