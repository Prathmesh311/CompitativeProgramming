#include<iostream>
#include<cmath>

using namespace std;

int power(int num, int n){
    //base case
    if(n == 1){
        return num;
    }

    // recursive body
    return num * power(num, n-1); 
}

int fastPower(int num, int n){
    //Base case
    if(n == 0){
        return 1;
    }

    //recursive body
    if(n%2 == 0){
        return pow(fastPower(num, n/2), 2);
    }
    else{
        return num * pow(fastPower(num, n/2), 2);
    }
}

int main(){
    int num = 6;
    int n = 10;

    int value = power(num, n);
    int fastValue = power(num, n);

    cout<<value<<endl;
    cout<<fastValue;
    return 0;
}