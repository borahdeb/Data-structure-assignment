#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;  // Left child
    struct Node *right; // Right child
};

// Creates a new node with a specified value
struct Node* createNode(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Inserts an element into the binary search tree
struct Node* insertElement(struct Node* root, int x) {
    if (root == NULL) {
        // Tree is empty, create a new node and return its address
        struct Node* temp = createNode(x);
        return temp;
    }
    if (root->data >= x) {
        // Value to be inserted is smaller or equal, go to left subtree
        root->left = insertElement(root->left, x);
    } else {
        // Value to be inserted is larger, go to right subtree
        root->right = insertElement(root->right, x);
    }
    return root;
}

// Inorder traversal (left, root, right)
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Preorder traversal (root, left, right)
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal (left, right, root)
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node* root = NULL;
    
    // Insert elements into the binary tree
    root = insertElement(root, 8);
    root = insertElement(root, 10);
    root = insertElement(root, 3);
    root = insertElement(root, 1);
    root = insertElement(root, 6);
    root = insertElement(root, 14);
    root = insertElement(root, 7);
    
    printf("Inorder traversal:\n");
    inorder(root);
    printf("\nPreorder traversal:\n");
    preorder(root);
    printf("\nPostorder traversal:\n");
    postorder(root);
    
    return 0;
}

