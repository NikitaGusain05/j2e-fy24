#include <iostream>
#include <vector>

using namespace std;

void generateSubsets(vector<int>& set, int n, int index, int sum, vector<int>& subsetSums) {
    if (index == n) {
        subsetSums.push_back(sum);
        return;
    }

    // Include the current element in the subset
    generateSubsets(set, n, index + 1, sum + set[index], subsetSums);

    // Exclude the current element from the subset
    generateSubsets(set, n, index + 1, sum, subsetSums);
}

void printSubsetSums(vector<int>& set) {
    int n = set.size();
    vector<int> subsetSums;
    generateSubsets(set, n, 0, 0, subsetSums);

    cout << "Subset sums:\n";
    for (int sum : subsetSums) {
        cout << sum << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the size of the set: ";
    cin >> n;

    vector<int> set(n);
    cout << "Enter the elements of the set:\n";
    for (int i = 0; i < n; i++) {
        cin >> set[i];
    }

    printSubsetSums(set);

    return 0;
}
