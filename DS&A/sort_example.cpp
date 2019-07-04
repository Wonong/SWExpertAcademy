#include <iostream>
#include "./sort.h"

using namespace std;

int main(){
    int n;
    int *arr;
    int *arr2;

    cin >> n;
    arr = (int*)malloc(sizeof(int)*n);
    arr2 = (int*)malloc(sizeof(int)*n);
    for(int i=0; i<n; i++) cin >> arr[i];

    quickSort(arr, 0, n-1);
    
    for(int i=0; i<n; i++) cout << arr[i] << ' ';
    cout << endl;

    return 0;
}