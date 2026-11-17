#include <iostream>

void Insert(int arr[], int n) {
    int i = n, temp = arr[i];

    while (i > 0 && temp > arr[i / 2]) {
        arr[i] = arr[i / 2];
        i /= 2;
    }
    arr[i] = temp;
}

int Delete(int arr[], int n) {
    int temp = arr[n];
    int value = arr[0];
    arr[0] = arr[n];
    arr[n] = value;

    int i = 0;
    int j = i * 2 + 1;
    while (j < n - 1) {
        if (arr[j + 1] > arr[j]) {
            j += 1;
        }
        if (arr[i] < arr[j]) {
            int x = arr[i];
            arr[i] = arr[j];
            arr[j] = x;
            i = j;
            j *= 2;
        } else {
            break;
        }
    }
    return value;
}

int main() {

    int arr[] = {10, 20, 30, 25, 5, 40, 35};

    for (int i = 1; i < 7; i++) {
        Insert(arr, i);
    }

    // std::cout << "Deleted value: " << Delete(arr, 6) << std::endl;
    // std::cout << "Deleted value: " << Delete(arr, 5) << std::endl;

    for (int i = 6; i >= 0; i--) {
        Delete(arr, i);
    }

    for (int i : arr) {
        std::cout << i << " ";
    }

    return 0;
}