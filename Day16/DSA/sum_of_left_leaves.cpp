#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sumOfLeftLeaves(TreeNode* root) {
    if (!root) return 0;

    int sum = 0;
    if (root->left && !root->left->left && !root->left->right)
        sum += root->left->val;

    return sum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

// Output =>
// Sum of Left Leaves: 24


    cout << "Sum of Left Leaves: " << sumOfLeftLeaves(root);
    return 0;
}

