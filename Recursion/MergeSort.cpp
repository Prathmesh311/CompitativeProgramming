#include<iostream>
using namespace std;

void merge(int *a, int start, int end){
    int mid = (start+end)/2;

    int i = start;
    int j = mid+1;
    int k = start;

    int temp[100];
    while (i <= mid && j <= end)
    {
        if(a[i] <= a[j]){
            temp[k++] = a[i++];
        }else{
            temp[k++] = a[j++];
        }
    }
    while(i <= mid){
        temp[k++] = a[i++];
    }
    while (j <= end)
    {
        temp[k++] = a[j++];
    }
    
    for(int i=start; i <= end; i++){
        a[i] = temp[i];
    }

}

void mergeSort(int a[], int start, int end){
    //Base Case
    if(start >= end){
        return;
    }

    //Recursive Case
    int mid = (start+end)/2;

    mergeSort(a, start, mid);
    mergeSort(a, mid+1, end);

    merge(a, start, end);
}

int main(){
    int arr[] = {5, -2, 9, -12, 1, 3, 7, 35};
    int n = sizeof(arr)/sizeof(int);
    cout<<n<<endl;
    mergeSort(arr, 0, n-1);

    for(int i=0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
