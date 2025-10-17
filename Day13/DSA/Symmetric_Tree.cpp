#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode* n1, TreeNode* n2) {
        if (n1 == nullptr && n2 == nullptr)
            return true;

        if (n1 == nullptr || n2 == nullptr)
            return false;

        return (n1->val == n2->val) &&
               isMirror(n1->left, n2->right) &&
               isMirror(n1->right, n2->left);
    }
};

// Helper function to print the tree (Level Order)
void printLevelOrder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                cout << node->val << " ";
                q.push(node->left);
                q.push(node->right);
            } else {
                cout << "null ";
            }
        }
        cout << endl;
    }
}

int main() {
    /*
         Example Tree (Symmetric):
                 1
                / \
               2   2
              / \ / \
             3  4 4  3
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    cout << "Level Order Traversal:\n";
    printLevelOrder(root);

    Solution solution;
    bool symmetric = solution.isSymmetric(root);

    cout << "\nIs the tree symmetric? " << (symmetric ? "Yes" : "No") << endl;

    return 0;
}
