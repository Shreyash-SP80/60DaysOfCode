#include <iostream>
#include <vector>
using namespace std;

/*
💡 Problem: 96. Unique Binary Search Trees
-----------------------------------------------------
Given an integer n, return the number of structurally unique 
Binary Search Trees (BSTs) that store values 1 to n.

🧩 Example 1:
Input: n = 3
Output: 5

🧩 Example 2:
Input: n = 1
Output: 1

🔒 Constraints:
1 <= n <= 19
-----------------------------------------------------

🔍 Approach:
We use Dynamic Programming (DP) to calculate the number of unique BSTs.

Let dp[i] = number of unique BSTs with i nodes.

Base cases:
dp[0] = 1 (empty tree)
dp[1] = 1 (single node)

For i from 2 to n:
   For each j from 1 to i:
       Choose j as root → 
           Left subtree size = j - 1
           Right subtree size = i - j
       dp[i] += dp[j - 1] * dp[i - j]

The final answer is dp[n].

This is essentially the nth Catalan number.

🕒 Time Complexity: O(n²)
🧠 Space Complexity: O(n)
-----------------------------------------------------
*/


class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }

        return dp[n];
    }
};

// 🧪 Driver code
int main() {
    Solution sol;
    
    int n1 = 3;
    int n2 = 1;

    cout << "Input: " << n1 << endl;
    cout << "Output: " << sol.numTrees(n1) << endl; // Expected Output: 5

    cout << "\nInput: " << n2 << endl;
    cout << "Output: " << sol.numTrees(n2) << endl; // Expected Output: 1

    return 0;
}

/*
✅ OUTPUT:
Input: 3
Output: 5

Input: 1
Output: 1
*/
