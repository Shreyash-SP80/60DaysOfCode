#include <iostream>
#include <vector>
#include <unordered_map>
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
    unordered_map<int, int> inorderMap; // value -> index
    int postIndex;

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;

        // The current root is postorder[postIndex]
        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        // Find the root in inorder array
        int inIndex = inorderMap[rootVal];

        // Build right subtree first, because postorder is processed from end
        root->right = build(inorder, postorder, inIndex + 1, inEnd);
        root->left = build(inorder, postorder, inStart, inIndex - 1);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIndex = postorder.size() - 1;
        inorderMap.clear();
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        return build(inorder, postorder, 0, inorder.size() - 1);
    }
};

// Helper function to print tree in level-order
void printLevelOrder(TreeNode* root) {
    if (!root) return;
    vector<TreeNode*> queue = {root};
    while (!queue.empty()) {
        vector<TreeNode*> nextQueue;
        for (auto node : queue) {
            if (node) {
                cout << node->val << " ";
                nextQueue.push_back(node->left);
                nextQueue.push_back(node->right);
            } else {
                cout << "null ";
            }
        }
        cout << endl;
        queue = nextQueue;
    }
}

int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    Solution sol;
    TreeNode* root = sol.buildTree(inorder, postorder);

    cout << "Level-order traversal of constructed tree:\n";
    printLevelOrder(root);

    return 0;
}
