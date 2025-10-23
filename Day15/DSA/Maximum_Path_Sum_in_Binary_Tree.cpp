#include <iostream>
#include <algorithm>
#include <climits> 
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
int maxPathSumHelper(TreeNode* root, int &maxSum) {
    if (!root) return 0;

    int left = max(0, maxPathSumHelper(root->left, maxSum));
    int right = max(0, maxPathSumHelper(root->right, maxSum));

    maxSum = max(maxSum, root->val + left + right);
    return root->val + max(left, right);
}

int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN;
    maxPathSumHelper(root, maxSum);
    return maxSum;
}

int main() {
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << "Maximum Path Sum: " << maxPathSum(root) << endl;
    return 0;
}

// Output =>
// Maximum Path Sum: 42

