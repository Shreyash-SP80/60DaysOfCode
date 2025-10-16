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

void buildFromLevelOrder(node* &root) {
    queue<node*> q;

    cout << "Enter data for root: ";
    int data ;
    cin >> data;
    root = new node(data);
    
    q.push(root);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data << " : ";
        int leftData;
        cin >> leftData;

        if(leftData != -1) {
            temp -> left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for: " << temp->data << " : ";
        int rightData;
        cin >> rightData;

        if(rightData != -1) {
            temp -> right = new node(rightData);
            q.push(temp->right);
        }
    }
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
            if(!q.empty()) q.push(NULL);
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) q.push(temp ->left);
            if(temp ->right) q.push(temp ->right);
        }
    }
}

// Example Input: 10 20 35 90 94 25 29 -1 -1
int main() {
    node* root = NULL;
    buildFromLevelOrder(root);
    cout << "\nLevel Order Traversal:\n";
    levelOrderTraversal(root);
    return 0;
}

// Output => 
// Enter data for root: 10
// Enter left node for: 10 : 20
// Enter right node for: 10 : 35
// Enter left node for: 20 : 90
// Enter right node for: 20 : 94
// Enter left node for: 35 : 25
// Enter right node for: 35 : 29
// Level Order Traversal:
// 10 
// 20 35 
// 90 94 25 29
