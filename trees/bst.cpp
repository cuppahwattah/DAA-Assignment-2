
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

Node* insertNode(Node* root, int value) {
    if (root == nullptr)
        return new Node(value);

    if (value < root->data)
        root->left = insertNode(root->left, value);
    else if (value > root->data)
        root->right = insertNode(root->right, value);

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
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid number of elements.";
        return 1;
    }

    Node* root = nullptr;

    cout << "Enter the elements: ";

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        root = insertNode(root, value);
    }

    cout << "\nBinary Search Tree:\n";
    displayTree(root, 0);

    return 0;
}