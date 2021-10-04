#include<iostream>
using namespace std;

//Top Down Approach
int fiboTopDown(int n, int dp[]){     
    //Base Case
    if(n == 0 || n == 1){
        return n;
    }

    //Recursive Case
    //Look up
    if(dp[n] != 0){
        return dp[n];
    }

    dp[n] = fiboTopDown(n-1, dp) + fiboTopDown(n-2, dp);
    return dp[n];
}

//Bottom Up approach
int fiboBottomUp(int n){
    int dp[100] = {0};
    dp[1] = 1;

    for(int i=2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

//Space optimization bottom up
int fiboSpaceOptimization(int n){
    int a = 0;
    int b = 1;
    int c;

    for(int i=2; i <= n; i++){
        c = a+b;
        a = b;
        b = c;
    }

    return c;
}


int main(){
    int n = 12;
    //cin>>n;
    int dp[100] = {0};

    //cout<<fiboTopDown(n, dp);
    //cout<<fiboBottomUp(n);
    cout<<fiboSpaceOptimization(n);

    return 0;
}