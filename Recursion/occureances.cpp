#include<iostream>
using namespace std;

int allOcc(int a[],int i, int n, int key, int *out, int j){   // All Occurances
    //base case
    if(n == 0){
        return j;
    }

    //recursive body
    if(a[i] == key){
        out[j] = i;
        return allOcc(a,i+1, n-1, key, out, j+1);
    }else{
        return allOcc(a, i+1, n-1, key, out, j);
    }

}

int lastOcc(int *a, int n, int key){           // Last Occurance
    //base case
    if(n == 0){
        return -1;
    }

    //recursive body
    int i = lastOcc(a+1, n-1, key);
    if(i == -1){
        if(a[0] == key){
            return 0;
        }else{
            return -1;
        }
    }
    return i+1;
}

int firstOcc(int *a, int n, int key){       //First Occurance
    // base case
    if(n == 0){
        return -1;
    }

    if(a[0] == key){
        return 0;
    }
    int i = firstOcc(a+1, n-1, key);
    if(i == -1){
        return -1;
    }
    return i + 1;
    
}

int main(){
    int arr[] = {1, 3, 7, 6, 9, 7, 10};
    int n = sizeof(arr)/sizeof(int);
    int key = 7;
    int out[100];
    //cout<<n;

    cout<< firstOcc(arr, n, key)<< endl;
    cout<< lastOcc(arr, n, key)<<endl;
    int count = allOcc(arr, 0, n, key, out, 0);
    cout<<"Count="<< count<<endl;

    for(int i=0; i < count; i++){
        cout<<out[i]<<" ";
    }

    return 0;
}