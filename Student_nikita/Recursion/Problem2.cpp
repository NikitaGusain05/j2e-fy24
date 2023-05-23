#include <iostream>
#include <vector>

int uniquePaths(int n, int m) {
    // Create a 2D grid with size (n x m)
    std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));

    // Fill the first row with 1's (only one way to reach each cell)
    for (int i = 0; i < m; i++) {
        dp[0][i] = 1;
    }

    // Fill the first column with 1's (only one way to reach each cell)
    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }

    // Calculate the number of unique paths for each cell
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            // The number of unique paths to reach a cell is the sum of the paths
            // from the cell above and the cell to the left
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    // The bottom-right cell will contain the total number of unique paths
    return dp[n - 1][m - 1];
}

int main() {
    int n, m;
    std::cout << "Enter the number of rows (n): ";
    std::cin >> n;
    std::cout << "Enter the number of columns (m): ";
    std::cin >> m;

    int paths = uniquePaths(n, m);
    std::cout << "Number of unique paths: " << paths << std::endl;

    return 0;
}
