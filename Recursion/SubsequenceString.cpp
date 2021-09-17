#include<iostream>
using namespace std;

int generateSubsequence(char *in, char *out, int i, int j, int count){
    //Base Case
    if(in[i] == '\0'){
        out[j] = '\0';
        cout<<out<<endl;
        return count+1;
    }

    //Recursive Case

    //Taking element in subset
    out[j] = in[i];
    int k = generateSubsequence(in, out, i+1, j+1, count);

    //Excluding element from subset
    k = generateSubsequence(in, out, i+1, j, k);
    return k;
}
int main(){
    char input[] = "abc";
    char output[10];

    cout<<generateSubsequence(input, output, 0, 0, 0);

    

    return 0;
}