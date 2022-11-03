//
// Created by yjs on 2022/10/29.
//
#include <iostream>

const int N=1e5+10;
int arr[N];



int partation(int * arr, int low, int hig){
    int pivote=arr[low];
    while (low!=hig){
        while (low<hig && arr[hig]>= pivote) hig--;
        arr[low]=arr[hig];
        while (low<hig && arr[low] <= pivote) low++;
        arr[hig]=arr[low];
    }
    arr[low]=pivote;
    return low;
}

void quicksort(int *  arr, int low, int hig){
    if(low>=hig) return;
    int pivode=partation(arr,low, hig);
    quicksort(arr, low, pivode-1);
    quicksort(arr, pivode+1, hig);

}







int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    quicksort(arr, 0, n-1);

    for (int i = 0; i < n; i ++ ) printf("%d ", arr[i]);



    return 0;
}