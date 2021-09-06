#include<iostream>
using namespace std;

void replacePiRecursion(char a[], int i){
    //Base Case
    if(a[i] == '\0' || a[i+1] == '\0'){
        return;
    }

    //Recursive Case
    if(a[i] == 'p' && a[i+1] == 'i'){
        int j=i+2;
        while(a[j] != '\0'){
            j++;
        }
        while(j >= i+2){                      //moving data forward
            a[j+2] = a[j];
            j--;
        }
        a[i] = '3';
        a[i+1] = '.';
        a[i+2] = '1';
        a[i+3] = '4';
        replacePiRecursion(a, i+4);
    }else{
        replacePiRecursion(a, i+1);
    }
}


int main(){
    char s[100];
    cin>>s;

    replacePiRecursion(s, 0);

    int i=0;
    while(s[i] != '\0'){
        cout<<s[i];
        i++;
    }

    return 0;
}