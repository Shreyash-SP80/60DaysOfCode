#include <iostream>
using namespace std;


int  reverseInteger(int num) {
    long reversed = 0;
    bool isNegative = num < 0;
    num = abs(num);

    while (num > 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }

    if (isNegative) reversed = -reversed;
    return (reversed > INT32_MAX || reversed < INT16_MIN)? 0: reversed;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Reversed: " << reverseInteger(n) << endl;
    return 0;
}


