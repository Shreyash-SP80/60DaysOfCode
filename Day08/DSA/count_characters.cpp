#include <iostream>
#include <cctype>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: "; 
    cin >> str;

    int alphabets = 0, digits = 0, special = 0;

    for (char c : str) {
        if (isalpha(c))
            alphabets++;
        else if (isdigit(c))
            digits++;
        else
            special++;
    }

    cout << "Alphabets: " << alphabets << endl;
    cout << "Digits: " << digits << endl;
    cout << "Special Characters: " << special << endl;

    return 0;
}

// Output =>
// Input: Hello@2025
// Output:
// Alphabets = 5
// Digits = 4
// Special Characters = 1

