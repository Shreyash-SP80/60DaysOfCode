#include <iostream>
#include <algorithm>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

int countGoodNodes(TreeNode* root, int maxVal) {
    if (!root) return 0;

    int count = 0;
    if (root->val >= maxVal)
        count = 1;

    maxVal = max(maxVal, root->val);
    return count + countGoodNodes(root->left, maxVal) + countGoodNodes(root->right, maxVal);
}

int goodNodes(TreeNode* root) {
    return countGoodNodes(root, root->val);
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(5);

    cout << "Number of Good Nodes: " << goodNodes(root);
    return 0;
}
