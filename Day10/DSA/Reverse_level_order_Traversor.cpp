#include <iostream>
#include <stack>
#include <queue>
using namespace std;

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

    if (data == -1) 
        return NULL;

    cout << "Enter data for inserting left of " << data << endl;
    root -> left = buildBinaryTree(root->left);

    cout << "Enter data for inserting right of " << data << endl;
    root -> right = buildBinaryTree(root->right);

    return root;
}

// 10 20 35 -1 -1 25 -1 -1 35 80 -1 -1 90 -1 -1

void reverseLevelOrderTraversor(node *root) {
    cout << "\nReverse Level Order Traversal: ";
    queue<node*> q;
    stack<node*> s;

    q.push(root);
    q.push(NULL);
    
    while (!q.empty()) {
        node* temp = q.front();
        q.pop();
        s.push(temp);

        if (temp == NULL) {
            if (!q.empty()) 
                q.push(NULL);
            
        } else {
            if (temp->right) 
                q.push(temp->right);

            if (temp->left)
                q.push(temp->left);
        }
    }

    while (!s.empty()) {
        if (s.top() == NULL) {
            cout << endl;
            s.pop();
        }
        else {
            cout << s.top()->data << " ";
            s.pop();
        }
    }
    
}

int main() {
    node* root = NULL;
    root = buildBinaryTree(root); 

    reverseLevelOrderTraversor(root); 
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

// Reverse Level Order Traversal:
// 35 25 80 90
// 20 35
// 10
