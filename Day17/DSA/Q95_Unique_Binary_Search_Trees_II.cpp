#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
/*
Problem: 95. Unique Binary Search Trees II
-----------------------------------------------------
Given an integer n, return all the structurally unique BST's
(Binary Search Trees) which have exactly n nodes of unique
values from 1 to n. Return the answer in any order.

Example 1:
Input: n = 3
Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]

Example 2:
Input: n = 1
Output: [[1]]

Constraints:
1 <= n <= 8  (practically limited by combinatorial explosion)

Approach:
We use recursion + divide-and-conquer to build all possible BSTs:
- For each value i in [start..end], treat i as the root.
- Recursively build all left subtrees from [start..i-1].
- Recursively build all right subtrees from [i+1..end].
- Combine every left and right subtree pair with root i (clone by creating new nodes).
- Base case: when start > end, return a vector containing nullptr (represents an empty subtree).
This enumerates every structure exactly once.

Time Complexity: Catalan-number growth — O(Catalan(n)) trees, building each tree costs O(n) → overall exponential.
Space Complexity: O(Catalan(n) * n) to store all trees (exponential).

The program includes a serialize function that prints each tree in level-order
(LeetCode-style) replacing null nodes with "null" and trimming trailing nulls.
*/


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r): val(x), left(l), right(r) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return build(1, n);
    }

private:
    // build all BSTs with values in range [start, end]
    vector<TreeNode*> build(int start, int end) {
        vector<TreeNode*> res;
        if (start > end) {
            res.push_back(nullptr);
            return res;
        }

        for (int rootVal = start; rootVal <= end; ++rootVal) {
            vector<TreeNode*> leftSubtrees = build(start, rootVal - 1);
            vector<TreeNode*> rightSubtrees = build(rootVal + 1, end);

            for (TreeNode* L : leftSubtrees) {
                for (TreeNode* R : rightSubtrees) {
                    TreeNode* root = new TreeNode(rootVal);
                    root->left = L;
                    root->right = R;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};

// Serialize a tree to LeetCode-like level order string, e.g. [1,null,2,null,3]
string serializeTree(TreeNode* root) {
    if (!root) return "[]";

    vector<string> vals;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        if (node) {
            vals.push_back(to_string(node->val));
            q.push(node->left);
            q.push(node->right);
        } else {
            vals.push_back("null");
        }
    }

    // remove trailing "null" entries
    int i = (int)vals.size() - 1;
    while (i >= 0 && vals[i] == "null") --i;

    if (i < 0) return "[]";

    // construct final string
    string out = "[";
    for (int j = 0; j <= i; ++j) {
        out += vals[j];
        if (j != i) out += ",";
    }
    out += "]";
    return out;
}

// Helper to delete a tree and free memory (post-order)
void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Solution sol;

    // Example 1
    int n1 = 3;
    vector<TreeNode*> ans1 = sol.generateTrees(n1);
    cout << "Input: " << n1 << endl;
    cout << "Output: [";
    for (size_t i = 0; i < ans1.size(); ++i) {
        cout << serializeTree(ans1[i]);
        if (i + 1 < ans1.size()) cout << ",";
    }
    cout << "]" << endl;

    // Free memory
    for (TreeNode* t : ans1) deleteTree(t);

    cout << endl;

    // Example 2
    int n2 = 1;
    vector<TreeNode*> ans2 = sol.generateTrees(n2);
    cout << "Input: " << n2 << endl;
    cout << "Output: [";
    for (size_t i = 0; i < ans2.size(); ++i) {
        cout << serializeTree(ans2[i]);
        if (i + 1 < ans2.size()) cout << ",";
    }
    cout << "]" << endl;

    // Free memory
    for (TreeNode* t : ans2) deleteTree(t);

    return 0;
}

/*
Expected OUTPUT (ordering from this implementation):
Input: 3
Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]

Input: 1
Output: [[1]]
*/
