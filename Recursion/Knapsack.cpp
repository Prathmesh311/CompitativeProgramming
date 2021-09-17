#include<iostream>
using namespace std;

int knapsack(int weights[], int prices[], int n, int c){
    //Base Case
    if(n == 0 || c == 0){
        return 0;
    }

    int include, exclude;
    exclude = INT8_MIN;
    include = INT8_MIN;

    //Recursive Case

    //Include Element
    if(weights[n-1] <= c){
        include = prices[n-1] + knapsack(weights, prices, n-1, c - weights[n-1]);
    }

    //Exclude Element
    exclude = knapsack(weights, prices, n-1, c);

    return max(include, exclude);

}

int main(){
    int weights[] = {1, 2, 3, 5};
    int prices[] = {40, 20, 30, 100};

    int n = 4;
    int c = 7;
    
    int maxProfit = knapsack(weights, prices, n, c);
    cout<<"Max Profit = "<<maxProfit;

    return 0;
}