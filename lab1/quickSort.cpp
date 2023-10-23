#include <iostream>
#include <time.h>
using namespace std;

int count = 0;

int partition (int arr[], int p, int r) {
    int pivot = arr[r];
    int i = p-1;
    for (int j = p; j < r; j++) {
        count++;
        if (arr[j] < pivot) {
            // swap but increment first i to correct position only
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i +1];
    arr[i +1] = arr[r];
    arr[r] = temp;
    return i + 1; // the correct index of the pivot
}

void quicksort (int arr[], int p, int r) {
    if (p < r) {
        int q = partition(arr,p,r);
        quicksort(arr, p, q-1);
        quicksort(arr, q+1, r);
    }
}

int main () {
    int n = 31;

    int arr[n] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,17,28,29,30};

    quicksort(arr, 0, n-1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout <<"\ncomparisons : " << count;
    return 0;
}