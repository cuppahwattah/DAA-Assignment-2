
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node* createTree() {
    int value;
    cin >> value;

    if (value == -1)
        return nullptr;

    Node* root = new Node(value);

    root->left = createTree();
    root->right = createTree();

    return root;
}

void displayTree(Node* root, int space) {
    if (root == nullptr)
        return;

    space += 5;

    displayTree(root->right, space);

    cout << endl;

    for (int i = 5; i < space; i++)
        cout << " ";

    cout << root->data << endl;

    displayTree(root->left, space);
}

int main() {
    cout << "Enter the elements in preorder (-1 for no child):\n";

    Node* root = createTree();

    cout << "\nBinary Tree:\n";
    displayTree(root, 0);

    return 0;
}