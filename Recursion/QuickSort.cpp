#include<iostream>
using namespace std;

int partition(int *a, int start, int end){
    int i = start-1;
    int j = start;

    //int pivot = rand(start, end);

    for(; j < end; j++){
        if(a[j] < a[end]){
            i = i+1;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[end]);
    return i+1;
}

void quickSort(int a[], int start, int end){
    //Base case
    if(start >=  end){
        return;
    }

    //Recursive case
    int p = partition(a, start, end);

    quickSort(a, start, p-1);      //Left side
    quickSort(a, p+1, end);        //Right side

}

int main(){
    int arr[] = {5, 9, 1, 12, 3, 7, 0};
    int n = sizeof(arr)/sizeof(int);

    quickSort(arr, 0, n-1);
    for(int i=0; i < n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}