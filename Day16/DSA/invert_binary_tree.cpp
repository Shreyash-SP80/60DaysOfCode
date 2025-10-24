#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

TreeNode* invertTree(TreeNode* root) {
    if (!root) return NULL;

    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);

    return root;
}

void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    cout << "Original Tree (Inorder): ";
    printInorder(root);
    cout << "\nInverted Tree (Inorder): ";
    invertTree(root);
    printInorder(root);
    return 0;
}

// Output  =>
// Original Tree (Inorder): 1 2 3 4 6 7 9 
// Inverted Tree (Inorder): 9 7 6 4 3 2 1
