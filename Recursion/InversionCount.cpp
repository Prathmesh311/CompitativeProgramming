#include<iostream>
using namespace std;

int merge(int *a, int start, int end){
    int mid = (start+end)/2;

    int i = start;
    int j = mid+1;
    int k = start;

    int temp[100];
    int cnt = 0;

    while(i <= mid && j <= end){
        if (a[i] <= a[j])
        {
            temp[k++] = a[i++];
        }else{
            temp[k++] = a[j++];
            cnt += mid - (i-1);
        }
    }
    while (i <= mid){
        temp[k++] = a[i++];
    }
    while (j <= end)
    {
        temp[k++] = a[j++];
    }
    
    for(int i=start; i<end; i++){
        a[i] = temp[i];
    }
    return cnt;
}


int inversionCount(int a[], int start, int end){
    //Base Case
    if(start >= end){
        return 0;
    }

    //Recursive Case
    int mid = (start+end)/2;
    
    int x = inversionCount(a, start, mid);
    int y = inversionCount(a, mid+1, end);
    int z = merge(a, start, end);

    return x+y+z;
    
}

int main(){
    int arr[] = {5, -2, 9, -12, 1, 3, 7, 35};
    int n = sizeof(arr)/sizeof(int);
    //cout<<n<<endl;

    int count = inversionCount(arr, 0, n-1);
    cout<<count;

    return 0;
}