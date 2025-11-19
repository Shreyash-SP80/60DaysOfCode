#include <iostream>
#include <vector>
using namespace std;

/* 
---------------------------------------------
   LeetCode 83: Remove Duplicates from Sorted List
---------------------------------------------

Question:
---------
Given the head of a sorted linked list, remove duplicate nodes so that 
each element appears only once. Return the updated sorted list.

Example 1:
Input:  [1,1,2]
Output: [1,2]

Example 2:
Input:  [1,1,2,3,3]
Output: [1,2,3]


Approach:
---------
Since the list is already sorted, duplicates will always be adjacent.

1. Use a pointer 'curr' starting at head.
2. While curr and curr->next exist:
       If curr->val == curr->next->val:
            skip the next node → curr->next = curr->next->next
       Else:
            move curr forward → curr = curr->next
3. Return head.

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

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;

        while (curr && curr->next) {
            if (curr->val == curr->next->val) {
                // Skip duplicate node
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
            }
        }
        return head;
    }
};

// Helper function to create a linked list from vector
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
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> arr = {1,1,2,3,3};

    ListNode* head = createList(arr);

    Solution obj;
    ListNode* result = obj.deleteDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(result);

    return 0;
}

/*
---------------------------------------------
Output:
List after removing duplicates: 1 2 3 
---------------------------------------------
*/
