#include <iostream>
using namespace std;

int countDigits(int num) {
    if (num == 0) return 1;
    int count = 0;
    while (num != 0) {
        num /= 10;
        count++;
    }
    return count;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Number of digits: " << countDigits(n) << endl;
    return 0;
}
