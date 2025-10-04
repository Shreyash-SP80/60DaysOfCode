#include <iostream>
using namespace std;

bool  isPalindrome(int num) {
    int original = num;
    int reversed = 0;

    while (num > 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }

    return original == reversed; 
}

int  main() {
    int num;
    cout << "Enter number to check palindrome or not: ";
    cin >> num;
    if (isPalindrome(num)) {
        cout << num << " is Palindrome" << endl;
    } else {
        cout << num << " is not Palindrome" << endl;
    }
    return 0;
}