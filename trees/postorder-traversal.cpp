
#include <iostream>
#include <queue>
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

Node* createTree(int values[], int n) {
    if (n == 0)
        return nullptr;

    Node* root = new Node(values[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;

    while (i < n) {
        Node* current = q.front();
        q.pop();

        current->left = new Node(values[i]);
        q.push(current->left);
        i++;

        if (i < n) {
            current->right = new Node(values[i]);
            q.push(current->right);
            i++;
        }
    }

    return root;
}

void postorder(Node* root) {
    if (root == nullptr)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
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

    cout << "Enter the number of nodes: ";
    cin >> n;

    if (n < 0 || n > 100) {
        cout << "Enter a number between 0 and 100.";
        return 1;
    }

    int values[100];

    cout << "Enter the elements level by level: ";

    for (int i = 0; i < n; i++)
        cin >> values[i];

    Node* root = createTree(values, n);

    cout << "\nBinary Tree:\n";
    displayTree(root, 0);

    cout << "\nPost-order Traversal: ";
    postorder(root);

    return 0;
}