#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int diameterHelper(TreeNode* root, int &maxDiameter) {
    if (!root) return 0;

    int leftHeight = diameterHelper(root->left, maxDiameter);
    int rightHeight = diameterHelper(root->right, maxDiameter);

    maxDiameter = max(maxDiameter, leftHeight + rightHeight);
    return 1 + max(leftHeight, rightHeight);
}

int diameterOfBinaryTree(TreeNode* root) {
    int maxDiameter = 0;
    diameterHelper(root, maxDiameter);
    return maxDiameter;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Diameter of the Binary Tree: " << diameterOfBinaryTree(root) << endl;
    return 0;
}
