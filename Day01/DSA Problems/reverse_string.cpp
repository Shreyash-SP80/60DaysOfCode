#include <iostream>
#include <string>
using namespace std;

string reverseString(string str) {
    int left = 0, right = str.length() - 1;

    while (left < right) {
        swap(str[left], str[right]);
        left++;
        right--;
    }
    return str;
    
}


int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);  // take full line input

    string reversed = reverseString(input);

    cout << "Reversed string: " << reversed << endl;

    return 0;
}