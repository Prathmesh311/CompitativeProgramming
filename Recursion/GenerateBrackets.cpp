#include<iostream>
using namespace std;

void generateBrackets(char *out,int n, int i, int open, int close){
    //Base Case
    if(i == 2*n){
        out[i] = '\0';
        cout<<out<<endl;
        return;
    }

    //Recursive Case

    //Selecting Opening bracket
    if(open > 0){
        out[i] = '(';
        generateBrackets(out, n, i+1, open-1, close);
    }

    //Selecting Closing bracket
    if(close > open){
        out[i] = ')';
        generateBrackets(out, n, i+1, open, close-1);
    }
    return;
}

int main(){
    int n = 4;
    //cin>>n;
    char output[100];

    generateBrackets(output, n, 0, n, n);

    return 0;
}

