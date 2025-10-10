#include <iostream>
using namespace std;

int removeDuplicates(int arr[], int n) {
    if (n == 0) return 0;
    int j = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    } 
    return j + 1;
}

int main() {
    int arr[] = {1, 1, 2, 2, 3, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int newLength = removeDuplicates(arr, n);
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newLength; i++)
        cout << arr[i] << " ";
    return 0;
}

// Output =>
// Input: arr = [1, 1, 2, 2, 3, 4, 4]
// Output: [1, 2, 3, 4]
