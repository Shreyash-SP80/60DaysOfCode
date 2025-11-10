#include <iostream>
using namespace std;


/*
🧮 Problem: 19. Remove Nth Node From End of List
------------------------------------------------
Given the head of a singly linked list, remove the nth node 
from the end of the list and return its head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]

Constraints:
1 <= size of list (sz) <= 30
0 <= Node.val <= 100
1 <= n <= sz
------------------------------------------------
Approach Used:
→ Two Pointer Technique (Fast & Slow Pointer)
→ Time Complexity: O(n)
→ Space Complexity: O(1)
------------------------------------------------
*/


// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Function to remove nth node from the end
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Step 1: Create a dummy node before head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Step 2: Initialize two pointers fast & slow
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Step 3: Move fast pointer (n+1) steps ahead
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Step 4: Move both pointers until fast reaches the end
        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        // Step 5: Remove the nth node from end
        slow->next = slow->next->next;

        // Step 6: Return new head (dummy->next)
        return dummy->next;
    }
};

// Utility function to print linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Utility function to create linked list from array
ListNode* createList(int arr[], int n) {
    if (n == 0) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < n; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Driver Code (main function)
int main() {
    Solution obj;

    // Example 1
    int arr1[] = {1, 2, 3, 4, 5};
    int n1 = 2;
    ListNode* head1 = createList(arr1, 5);
    cout << "Original List: ";
    printList(head1);
    head1 = obj.removeNthFromEnd(head1, n1);
    cout << "After removing " << n1 << "th node from end: ";
    printList(head1);

    cout << "\n";

    // Example 2
    int arr2[] = {1};
    int n2 = 1;
    ListNode* head2 = createList(arr2, 1);
    cout << "Original List: ";
    printList(head2);
    head2 = obj.removeNthFromEnd(head2, n2);
    cout << "After removing " << n2 << "th node from end: ";
    printList(head2);

    cout << "\n";

    // Example 3
    int arr3[] = {1, 2};
    int n3 = 1;
    ListNode* head3 = createList(arr3, 2);
    cout << "Original List: ";
    printList(head3);
    head3 = obj.removeNthFromEnd(head3, n3);
    cout << "After removing " << n3 << "th node from end: ";
    printList(head3);

    return 0;
}

/*
---------------- OUTPUT ----------------

Original List: 1 -> 2 -> 3 -> 4 -> 5
After removing 2th node from end: 1 -> 2 -> 3 -> 5

Original List: 1
After removing 1th node from end:

Original List: 1 -> 2
After removing 1th node from end: 1
----------------------------------------
*/
