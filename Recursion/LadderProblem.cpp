#include<iostream>
using namespace std;

int ladder(int n){
    //Base Case
    if(n == 0){
        return 1;
    }
    if(n < 0){
        return 0;
    }

    //Recursive Case
    return ladder(n-1) + ladder(n-2) + ladder(n-3);
}


int main(){
    int n = 3;
    
    int numOfWays = ladder(n);
    cout<<numOfWays;
    return 0;
}