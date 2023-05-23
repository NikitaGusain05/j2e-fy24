#include <iostream>
#include <vector>
using namespace std;

void generateStrings(const vector<char>& characters, int k, string currentString) {
    // Base case: if currentString reaches length k, print it
    if (currentString.length() == k) {
        cout << currentString << endl;
        return;
    }

    // Recursive case: add each character from the set to currentString and recurse
    for (char c : characters) {
        string newString = currentString + c;
        generateStrings(characters, k, newString);
    }
}

int main() {
    int k;
    cout << "Enter the length of the strings (k): ";
    cin >> k;

    int n;
    cout << "Enter the number of characters (n): ";
    cin >> n;

    vector<char> characters(n);
    cout << "Enter the characters: ";
    for (int i = 0; i < n; i++) {
        cin >> characters[i];
    }

    cout << "Possible strings of length " << k << ":" << endl;
    generateStrings(characters, k, "");

    return 0;
}
