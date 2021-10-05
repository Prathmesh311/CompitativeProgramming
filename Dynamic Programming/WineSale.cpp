#include<iostream>
using namespace std;

//Top Down Approach
int profit(int wines[], int i, int j, int year, int dp[][100]){
    //Base Case
    if(i > j){
        return 0;
    }

    //Look Up
    if(dp[i][j] != 0){
        return dp[i][j];
    }

    //Recursive Case
    int p1 = wines[i]*year + profit(wines, i+1, j, year+1, dp);
    int p2 = wines[j]*year + profit(wines, i, j-1, year+1, dp);

    dp[i][j] = max(p1, p2);
    return dp[i][j];
}

int main(){
    int wines[] = {2,3,5,1,4};
    int dp[100][100] = {0};

    int len = sizeof(wines)/sizeof(int);

    cout<<profit(wines, 0, len-1, 1, dp);

    return 0;
}

