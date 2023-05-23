#include <iostream>
#include <vector>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::vector<TreeNode*> generateTrees(int n) {
    if (n == 0) {
        return {nullptr};
    }

    std::vector<TreeNode*> result;
    for (int i = 1; i <= n; i += 2) {
        int leftCount = i - 1;
        int rightCount = n - i;

        std::vector<TreeNode*> leftTrees = generateTrees(leftCount);
        std::vector<TreeNode*> rightTrees = generateTrees(rightCount);

        for (TreeNode* left : leftTrees) {
            for (TreeNode* right : rightTrees) {
                TreeNode* root = new TreeNode(0);
                root->left = left;
                root->right = right;
                result.push_back(root);
            }
        }
    }

    return result;
}

// Function to print the tree in preorder traversal
void printTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    std::cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

// Function to deallocate memory of the tree
void deleteTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    int n = 3;
    std::vector<TreeNode*> trees = generateTrees(n);

    for (TreeNode* root : trees) {
        printTree(root);
        std::cout << std::endl;
        deleteTree(root);
    }

    return 0;
}
