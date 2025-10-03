#include <iostream>
using namespace std;


int  linearSearch(int *arr, int n, int srch) {

    for (int i = 0; i < n; i++) {
        if (arr[i] == srch) {
            return i;
        }
    }
    return -1;

}

int  main() {
    int n, srch;
    cout << "Enter the length of array: ";
    cin >> n;
    int *arr = new int[n];

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter Search element: ";
    cin >> srch;

    int result = linearSearch(arr, n, srch);
    if (result != -1) {
        cout << "Element is Found at index " << result << endl;
    } else {
        cout << "Element not Found" << endl;
    }

    return 0;
}