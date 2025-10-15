#include <iostream>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;

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

    if (data == -1)
        return NULL;

    root = new node(data);


    cout << "Enter data for inserting left of " << data << endl;
    root->left = buildBinaryTree(root->left);

    cout << "Enter data for inserting right of " << data << endl;
    root->right = buildBinaryTree(root->right);

    return root;
}

// 10 20 35 -1 -1 25 -1 -1 35 80 -1 -1 90 -1 -1

void  inOrderTraversal(node* root) {
    if (root == NULL)    
        return;
    
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

int main() {
    node* root;
    root = buildBinaryTree(root);

    inOrderTraversal(root);

    return 0;
}
