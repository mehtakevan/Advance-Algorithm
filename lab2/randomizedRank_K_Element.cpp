#include <iostream>
#include <time.h>
using namespace std;

int partition (int arr[], int p, int r) {
    int pivot = arr[r], i = p-1;

    for (int j = p; j < r; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    i++;
    int temp = arr[i];
    arr[i] = arr[r];
    arr[r] = temp;

    return i;
}

int random_partition (int arr[], int p, int r) {
    int pivot = p + rand()%(r-p+1);

    int temp = arr[pivot];
    arr[pivot] = arr[r];
    arr[r] = temp;

    return (partition(arr, p, r));
}

int find (int arr[], int p, int r, int k) {
    if (p < r) {
        int q = random_partition(arr,p,r);
        if (q == k -1) // k-1 as i am looking for k-1 indexed element in ascendingly arranged array which is rank k
            return arr[q];
        else {
            if (k -1 < q)
                return find(arr, p, q-1, k);
            else
                return find(arr, q+1, r, k);
        }
    }
}

int main() {
    srand(time(0));
    int N = 10;
    int arr[N] = {1,5,2,3,6,7,8,10,9,4};
    // int arr[N] = {1,2,3,4,5,6,7,8,9,10};


int counter = 0;
    for (int i = 1; i <= 50; i++) {

    int k = 10; // k should be in range 1 to N
    int answer = find(arr,0,N-1,k);
    std::cout << "\nrank " << k << "th element : \n" << answer;
    if (answer == 10)
        counter++;
    }

    cout << endl << counter/50.0 *100;

    return 0;
}