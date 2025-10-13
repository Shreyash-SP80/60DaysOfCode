#include <iostream>
#include <string>
using namespace std;

string removeVowels(string s) {
    string result = "";
    for (char c : s) {
        char lower = tolower(c);
        if (lower != 'a' && lower != 'e' && lower != 'i' && lower != 'o' && lower != 'u')
            result += c;
    }
    return result;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);
    cout << "String without vowels: " << removeVowels(input);
    return 0;
}
