#include<iostream>
using namespace std;

void generateBrackets(char *out, int i, int open, int close){
    //Base Case
    if(open == 0 && close == 0){
        out[i] = '\0';
        cout<<out<<endl;
        return;
    }

    //Recursive Case

    //Selecting Opening bracket
    if(open > 0){
        out[i] = '(';
        generateBrackets(out, i+1, open-1, close);
    }

    //Selecting Closing bracket
    if(close > 0){
        out[i] = ')';
        generateBrackets(out, i+1, open, close-1);
    }
}

int main(){
    int n;
    cin>>n;
    char output[100];

    generateBrackets(output, 0, n, n);

    return 0;
}