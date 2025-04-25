#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

bool search(struct Node* root, int value) {
    if (root == NULL) return false;
    if (value == root->data) return true;
    return (value < root->data) ? search(root->left, value) : search(root->right, value);
}

struct Node* createTree() {
    struct Node* root = NULL;
    int count, value;
    printf("Enter the number of nodes: ");
    scanf("%d", &count);
    printf("Input %d values:\n", count);
    for (int i = 0; i < count; i++) {
        scanf("%d", &value);
        root = insertNode(root, value);
    }
    return root;
}

void inorderTraversal(struct Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void deleteTree(struct Node* root) {
    if (root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}

int main() {
    struct Node* root = createTree();
    printf("\nInorder Traversal of the Tree: ");
    inorderTraversal(root);
    int searchValue;
    printf("\n\nEnter a value to search: ");
    scanf("%d", &searchValue);
    if (search(root, searchValue)) {
        printf("%d is present in the tree.\n", searchValue);
    } else {
        printf("%d is not found in the tree.\n", searchValue);
    }
    deleteTree(root);
    return 0;
}