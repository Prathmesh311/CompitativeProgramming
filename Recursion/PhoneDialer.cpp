#include<iostream>
#include<array>
using namespace std;

char keypad[][10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void dialer(char *in,char *out, int n, int j){
    //Base Case
    if(in[n] == '\0'){
        out[j] == '\0';
        cout<<out<<endl;
        return;
    }

    //Recursive Case
    int i = in[n] - '0';

    for(int k=0; keypad[i][k] != '\0'; k++){
        out[j] = keypad[i][k];
        dialer(in, out, n+1, j+1);
    }
    return;
}

int main(){
    char input[] = "23";
    char output[100];

    dialer(input, output, 0, 0);

    return 0;
}