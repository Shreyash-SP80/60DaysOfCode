#include <iostream>
#include <queue>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;

        node (int data) {
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

void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            cout << endl;
            if(!q.empty()) { 
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }
}

void  countLeafNode(node* root, int& cnt) {
    if (root == NULL) 
        return;

    countLeafNode(root->left, cnt);

    if (root->left == NULL && root->right == NULL) 
        cnt++;

    countLeafNode(root->right, cnt);
}

// 10 20 35 -1 -1 25 -1 -1 35 80 -1 -1 90 -1 -1

int main() {
    int cnt = 0;
    node* root = NULL;
    root = buildBinaryTree(root);
    levelOrderTraversal(root);
    countLeafNode(root, cnt);
    cout << "\nLeaf Nodes: " << cnt << endl;
    return 0;
}