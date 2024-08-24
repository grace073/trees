#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    // Node(int val) {
    //     this->left = NULL;
    //     this->right = NULL;
    //     this->data = val;
    // }
    Node(int val):data(val),left(NULL),right(NULL){
        //ctor body (Additional details if needed)
    }
};

void preOrder(Node *root) {
    // NODE->LEFT->RIGHT (NLR)
    if (root == NULL) {
        return;
    }
    // N:
    cout << root->data << " ";
    // L:
    preOrder(root->left);
    // R:
    preOrder(root->right);
}

void postOrder(Node *root) {
    // LEFT->RIGHT->NODE (LRN)
    if (root == NULL) {
        return;
    } 
    // L:
    postOrder(root->left);
    // R:
    postOrder(root->right);
    // N:
    cout << root->data << " ";
}

void inOrder(Node *root) {
    // LEFT->NODE->RIGHT (LNR)
    if (root == NULL) {
        return;
    } 
    // L:
    inOrder(root->left);
    // N:
    cout << root->data << " ";
    // R:
    inOrder(root->right);
}

void createTree(Node *root) {
    int data;
    
    // For left child
    cout << "Enter value for left of Node " << root->data << " (Enter -1 for NULL): ";
    cin >> data;
    if (data != -1) {
        root->left = new Node(data);
        createTree(root->left);
    }

    // For right child
    cout << "Enter value for right of Node " << root->data << " (Enter -1 for NULL): ";
    cin >> data;
    if (data != -1) {
        root->right = new Node(data);
        createTree(root->right);
    }
}

int main() {
    int data;
    cout << "Enter value of root Node: ";
    cin >> data;
    Node *root = new Node(data);
    createTree(root);

    cout << "Preorder Traversal: ";
    preOrder(root);
    cout << endl;

    cout << "postOrder Traversal: ";
    postOrder(root);
    cout << endl;

    cout << "inOrder Traversal: ";
    inOrder(root);
    cout << endl;

    return 0;
}
