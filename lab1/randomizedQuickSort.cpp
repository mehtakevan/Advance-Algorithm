#include <iostream>
#include <time.h>
using namespace std;

int count = 0;

int partition (int arr[], int p, int r) {
   int pivot = arr[r];
   int i = p -1;

   for (int j = p; j < r; j++) {
       count++;
       if (arr[j] <= pivot) {
           ++i;
           // swap
           int temp = arr[i];
           arr[i] = arr[j];
           arr[j] = temp;
       }
   }

   int temp = arr[i +1];
   arr[i +1] = arr[r];
   arr[r] = temp;

   return i + 1;
}

int randomized_partition(int arr[], int p, int r) {
   int i = p + rand()%(r -p +1);

   // swap the last element with the randomly choosen index
   int temp = arr[i];
   arr[i] = arr[r];
   arr[r] = temp;

   return (partition(arr, p, r));
}

void rquicksort (int arr[], int p, int r) {
   if (p < r) {
       int q = randomized_partition(arr,p,r);
       rquicksort(arr,p,q-1);
       rquicksort(arr,q+1,r);
   }
}

int main () {
   srand(time(0));
   int n = 10;

    int arr[n] = {9,0,7,1,5,2,3,4,6,8};


   rquicksort(arr, 0, n-1);

   for (int i = 0; i < n; i++) {
       cout << arr[i] << " ";
   }
   cout <<"\ncomparisons : " << count;
   return 0;
}