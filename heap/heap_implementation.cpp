#include <iostream>

void insert(int arr[], int n) {
    int i = n, temp = arr[i];

    while (i > 0 && temp > arr[i / 2]) {
        arr[i] = arr[i / 2];
        i /= 2;
    }
    arr[i] = temp;
}

int main() {

    int arr[] = {10, 20, 30, 25, 5, 40, 35};

    for (int i = 1; i < 7; i++) {
        insert(arr, i);
    }

    for (int i : arr) {
        std::cout << i << " ";
    }

    return 0;
}