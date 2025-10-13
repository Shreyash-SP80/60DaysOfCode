#include <iostream>
using namespace std;

int findMissingNumber(int arr[], int n) {
    int total = (n + 1) * (n + 2) / 2; // sum of 1..n+1
    for (int i = 0; i < n; i++)
        total -= arr[i];
    return total;
}

int main() {
    int n;
    cout << "Enter size of array (n-1 elements of 1..n): ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Missing number is: " << findMissingNumber(arr, n);
    return 0;
}

// Output =>
// Enter size of array: 5
// Enter elements: 1 2 4 5 6
// Missing number is: 3

