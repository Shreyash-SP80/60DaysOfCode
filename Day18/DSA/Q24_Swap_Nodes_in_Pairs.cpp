#include <iostream>
#include <vector>
using namespace std;

/* 
---------------------------------------------
   LeetCode 24: Swap Nodes in Pairs
---------------------------------------------

Question:
---------
Given the head of a singly linked list, swap every two adjacent nodes and 
return its head. You must swap nodes themselves — not values.

Example 1:
Input:  [1,2,3,4]
Output: [2,1,4,3]

Example 2:
Input:  []
Output: []

Example 3:
Input:  [1]
Output: [1]

Example 4:
Input:  [1,2,3]
Output: [2,1,3]


Approach:
---------
1. Use a dummy node pointing to the head (helps to manage swaps cleanly).
2. Use a pointer 'prev' that always stays behind the pair to be swapped.
3. For each pair:
      first  = prev->next
      second = first->next

      Perform the swap by adjusting pointers:
      first->next  = second->next
      second->next = first
      prev->next   = second

4. Move prev to the end of the swapped pair and continue until no pair left.

Time Complexity:  O(n)
Space Complexity: O(1)
---------------------------------------------
*/


// Linked List Node Definition
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Swap pairs function
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;

        while (prev->next != nullptr && prev->next->next != nullptr) {
            ListNode* first = prev->next;
            ListNode* second = first->next;

            // Swapping the nodes
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move prev pointer for next swap
            prev = first;
        }

        return dummy->next;
    }
};

// Helper function to create linked list
ListNode* createList(vector<int> arr) {
    if (arr.empty()) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for (int i = 1; i < arr.size(); i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

// Print linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    vector<int> arr = {1,2,3,4};

    ListNode* head = createList(arr);

    Solution obj;
    ListNode* result = obj.swapPairs(head);

    cout << "Swapped List: ";
    printList(result);

    return 0;
}

/*
---------------------------------------------
Output:
Swapped List: 2 1 4 3 
---------------------------------------------
*/
