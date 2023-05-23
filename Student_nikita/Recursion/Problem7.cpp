#include <iostream>
#include <vector>

using namespace std;

// Structure to represent an item
struct Item {
    int weight;
    int profit;
};

// Function to solve the 0/1 Knapsack problem
int knapsack(int W, const vector<Item>& items) {
    int n = items.size();

    // Create a table to store the maximum profit for each subproblem
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        int weight = items[i - 1].weight;
        int profit = items[i - 1].profit;

        for (int j = 1; j <= W; j++) {
            if (weight > j) {
                // If the current item's weight exceeds the capacity of the knapsack,
                // we cannot include it in the optimal solution
                dp[i][j] = dp[i - 1][j];
            } else {
                // Find the maximum value by considering both the cases:
                // 1. Including the current item
                // 2. Excluding the current item
                dp[i][j] = max(dp[i - 1][j], profit + dp[i - 1][j - weight]);
            }
        }
    }

    // Return the maximum profit
    return dp[n][W];
}

int main() {
    int W; // Capacity of the knapsack
    int n; // Number of items

    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items(n);

    cout << "Enter the weight and profit of each item:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << ": ";
        cin >> items[i].weight >> items[i].profit;
    }

    int maxProfit = knapsack(W, items);
    cout << "Maximum profit: " << maxProfit << endl;

    return 0;
}
