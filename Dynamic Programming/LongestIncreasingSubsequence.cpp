#include<iostream>
using namespace std;

//Bottom Up Approach  O(N^2)
int LIS(int arr[], int n){
    int dp[n] = {1};        
    int longest = 0;

    for(int i=0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        longest = max(longest, dp[i]);
    }

    return longest;
}

int main(){
    int arr[] = {1,5,2,3,4,9,6,10};
    int n = sizeof(arr)/sizeof(int);

    cout<<LIS(arr, n);
    return 0;
}