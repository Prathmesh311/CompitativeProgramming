#include<iostream>
using namespace std;

//Bottom Up Approach
int maximumSubarraySum(int arr[], int n){
    int dp[100] = {0};
    int maxSoFar = dp[0];
    
    dp[0] = arr[0] >= 0 ? arr[0] : 0;

    for(int i=1; i < n; i++){
        dp[i] = dp[i-1] + arr[i];
        if(dp[i] < 0){
            dp[i] = 0;
        }
        maxSoFar = max(dp[i], maxSoFar);
    }
    return maxSoFar;
}

int main(){
    int arr[] = {-3,2,5,-1,6,3,-2,7,-5,2};
    int n = sizeof(arr)/sizeof(int);

    cout<<maximumSubarraySum(arr, n);

    return 0;
}