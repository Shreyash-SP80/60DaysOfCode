#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/* 
---------------------------------------------
   LeetCode 2154: Keep Multiplying Found Values by Two
---------------------------------------------

Question:
---------
You are given an integer array nums and an integer original.

Repeat the following steps:
1. If 'original' is found in nums → multiply it by 2.
2. Otherwise, stop the process.
3. Continue until the value is no longer present in nums.

Return the final value of 'original'.

Example 1:
-----------
Input:
nums = [5,3,6,1,12], original = 3

Output:
24

Explanation:
3 is found → becomes 6  
6 is found → becomes 12  
12 is found → becomes 24  
24 is NOT found → return 24


Example 2:
-----------
Input:
nums = [2,7,9], original = 4

Output:
4
(4 not found → return as it is)


Approach:
---------
1. Insert all elements of nums into an unordered_set for O(1) lookup.
2. While 'original' exists in the set:
      original = original * 2
3. Return the final value of original.

Time Complexity: O(n)
Space Complexity: O(n)
---------------------------------------------
*/


class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> s(nums.begin(), nums.end());

        // Continue multiplying while original exists in set
        while (s.find(original) != s.end()) {
            original *= 2;
        }
        return original;
    }
};

int main() {
    vector<int> nums = {5, 3, 6, 1, 12};
    int original = 3;

    Solution obj;
    int result = obj.findFinalValue(nums, original);

    cout << "Final Value: " << result << endl;

    return 0;
}

/*
---------------------------------------------
Output:
Final Value: 24
---------------------------------------------
*/
