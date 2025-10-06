#include <iostream>
using namespace std;

int main() {
    int num, sum = 0;

    cout << "Enter a number: ";
    cin >> num;

    // Sum of proper divisors
    for (int i = 1; i <= num / 2; ++i) {
        if (num % i == 0)
            sum += i;
    }

    if (sum == num)
        cout << num << " is a Perfect number." << endl;
    else
        cout << num << " is not a Perfect number." << endl;

    return 0;
}
