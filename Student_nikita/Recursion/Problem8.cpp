#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(string str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end])
            return false;
        start++;
        end--;
    }
    return true;
}

void partitionPalindrome(string s, int start, vector<string>& currentPartition, vector<vector<string>>& allPartitions) {
    if (start == s.length()) {
        allPartitions.push_back(currentPartition);
        return;
    }

    for (int i = start; i < s.length(); i++) {
        if (isPalindrome(s, start, i)) {
            string palindrome = s.substr(start, i - start + 1);
            currentPartition.push_back(palindrome);
            partitionPalindrome(s, i + 1, currentPartition, allPartitions);
            currentPartition.pop_back();
        }
    }
}

vector<vector<string>> palindromePartition(string s) {
    vector<vector<string>> allPartitions;
    vector<string> currentPartition;
    partitionPalindrome(s, 0, currentPartition, allPartitions);
    return allPartitions;
}

int main() {
    string s = "aab";
    vector<vector<string>> partitions = palindromePartition(s);

    // Print all palindrome partitions
    for (const auto& partition : partitions) {
        for (const auto& palindrome : partition) {
            cout << palindrome << " ";
        }
        cout << endl;
    }

    return 0;
}
