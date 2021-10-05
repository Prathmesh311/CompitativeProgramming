#include<iostream>
using namespace std;

int minStepsToOne(int n, int dp[]){
    //Base Case
    if(n <= 1){
        return 0;
    }

    //Recursive Case
    //Look Up
    if(dp[n] != 0){
        return dp[n];
    }

    int step1, step2, step3;

    if(n % 3 == 0){
        step1 = minStepsToOne(n/3, dp);
    }
    if(n % 2 == 0){
        step2 = minStepsToOne(n/2, dp);
    }
    step3 = minStepsToOne(n-1, dp);

    dp[n] = min(min(step1, step2), step3) + 1;  //Storing in memory
    return dp[n];
}

int minStepsToOneBottomUp(int n){
    int dp[100] = {0};

    int step1, step2, step3;
    for(int i=2; i <= n; i++){
        

        if(i % 3 == 0){
            step1 = dp[i/3] + 1;
        }
        if(i % 2 == 0){
            step2 = dp[i/2] + 1;
        }
        step3 = dp[i-1] + 1;

        dp[i] = min(min(step1, step2), step3);  //Storing in memory
        
    }
    return dp[n];
}

int main(){
    int n = 10;
    //cin>>n;
    int dp[100] = {0};

    //cout<<minStepsToOne(n, dp);
    cout<<minStepsToOneBottomUp(n);
    return 0;
}

