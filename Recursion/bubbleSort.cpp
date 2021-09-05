#include<iostream>
using namespace std;

void bubbleSortRecursive(int a[], int j, int n){  //Full recursion
    //base case
    if(n == 1){
        return;
    }
    if(j == n-1){
        return bubbleSortRecursive(a, 0, n-1);
    }

    //recursive case
    
    if(a[j] > a[j+1]){
        swap(a[j], a[j+1]);
    }
    return bubbleSortRecursive(a, j+1, n);
}


void bubbleSort(int a[], int n){           // half recursion
    //base case
    if(n == 1){
        return;
    }

    for(int j=0; j < n-1; j++){
        if(a[j] > a[j+1]){
            swap(a[j], a[j+1]);
        }
    }
    bubbleSort(a, n-1);
}

int main(){
    int arr[] = {5, 2, 8, 12, 7};
    //bubbleSort(arr, 5);
    bubbleSortRecursive(arr, 0,5);
    for(int i=0; i < 5; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}