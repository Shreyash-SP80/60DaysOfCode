#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        if (str[left] != str[right]) 
            return false;
        left++;
        right--;
    }
    return true;
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    if (isPalindrome(str))
        cout << "Palindrome String" << endl;
    else
        cout << "Not a Palindrome String" << endl;

    return 0;
}

