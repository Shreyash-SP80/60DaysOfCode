#include <iostream>
#include <vector>
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, (int)nums.size() - 1);
    }

private:
    TreeNode* build(const vector<int>& nums, int l, int r) {
        if (l > r) return nullptr;

        int maxIdx = l;
        for (int i = l + 1; i <= r; ++i)
            if (nums[i] > nums[maxIdx]) maxIdx = i;

        TreeNode* root = new TreeNode(nums[maxIdx]);
        root->left  = build(nums, l, maxIdx - 1);
        root->right = build(nums, maxIdx + 1, r);
        return root;
    }
};

// Helper function to print tree in-order
void printInOrder(TreeNode* root) {
    if (!root) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

int main() {
    vector<int> nums = {3, 2, 1, 6, 0, 5};

    Solution sol;
    TreeNode* root = sol.constructMaximumBinaryTree(nums);

    cout << "In-order traversal of Maximum Binary Tree:\n";
    printInOrder(root);
    cout << endl;

    return 0;
}
