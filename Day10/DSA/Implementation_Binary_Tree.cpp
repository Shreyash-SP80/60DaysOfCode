#include <iostream>
using namespace std;

// Binary Tree node implementation 
class node {
    public:
        int data;     // Store the data
        node* left;   // to store the address of left child
        node* right;  // to store the address of right child

        // Constructor for creation of node 
        node(int data) {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

node* buildBinaryTree(node* root) {
    cout << "Enter data: ";
    int data;
    cin >> data;

    root = new node(data);

    // If data == -1 then the parent do not have any child
    if (data == -1) 
        return NULL;

    
    // For inserting the data left of the parent node
    cout << "Enter data for inserting left of " << data << endl;
    root -> left = buildBinaryTree(root->left);

    // For inserting the data right of the parent node
    cout << "Enter data for inserting right of " << data << endl;
    root -> right = buildBinaryTree(root->right);

    // After all this process return root
    return root;
}

// 10 20 35 -1 -1 25 -1 -1 35 80 -1 -1 90 -1 -1

int main() {

    // Create *root object to store the all tree
    node* root = NULL;
    root = buildBinaryTree(root);  // Call the buildBinaryTree() to create an binary tree and returns the complete binary tree
    cout << "Binary Tree created.." << endl;
    return 0;

}

// Output =>
// Enter data: 10
// Enter data for inserting left of 10
// Enter data: 20
// Enter data for inserting left of 20
// Enter data: 35
// Enter data for inserting left of 35
// Enter data: -1
// Enter data for inserting right of 35
// Enter data: -1
// Enter data for inserting right of 20
// Enter data: 25
// Enter data for inserting left of 25
// Enter data: -1
// Enter data for inserting right of 25
// Enter data: -1
// Enter data for inserting right of 10
// Enter data: 35
// Enter data for inserting left of 35
// Enter data: 80
// Enter data for inserting left of 80
// Enter data: -1
// Enter data for inserting right of 80
// Enter data: -1
// Enter data for inserting right of 35
// Enter data: 90
// Enter data for inserting left of 90
// Enter data: -1
// Enter data for inserting right of 90
// Enter data: -1
// Binary Tree created..

