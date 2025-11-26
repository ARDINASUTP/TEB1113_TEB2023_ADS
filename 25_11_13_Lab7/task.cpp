#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};

Node* createNode(int key) {
    Node* newNode = new Node;
    newNode->key = key;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return createNode(key);
    }

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

bool search(Node* root, int key) {
    if (root == nullptr) return false;
    if (root->key == key) return true;

    if (key < root->key)
        return search(root->left, key);
    else
        return search(root->right, key);
}

Node* findMin(Node* root) {
    while (root && root->left != nullptr)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return nullptr;

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } 
    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } 
    else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }

        else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* minNode = findMin(root->right);
        root->key = minNode->key;
        root->right = deleteNode(root->right, minNode->key);
    }
    return root;
}


Node* update(Node* root, int oldKey, int newKey) {
    if (!search(root, oldKey)) {
        cout << "Key not found.\n";
        return root;
    }
    root = deleteNode(root, oldKey);
    root = insert(root, newKey);
    return root;
}


void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->key << " ";
}

int main() {
    Node* root = nullptr;


    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Inorder: ";
    inorder(root); cout << "\n";

    cout << "Preorder: ";
    preorder(root); cout << "\n";

    cout << "Postorder: ";
    postorder(root); cout << "\n";


    cout << "\nSearching 40... " 
         << (search(root, 40) ? "Found" : "Not Found") << "\n";


    cout << "Deleting 30...\n";
    root = deleteNode(root, 30);

    cout << "Inorder after delete: ";
    inorder(root); cout << "\n";


    cout << "Updating 40 -> 45...\n";
    root = update(root, 40, 45);

    cout << "Inorder after update: ";
    inorder(root); cout << "\n";

    return 0;
}

