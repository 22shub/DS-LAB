#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* buildTree() {
    int value;
    printf("Enter node value (-1 for no node): ");
    scanf("%d", &value);
    if (value == -1) return NULL;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;

    printf("Enter left child of %d:\n", value);
    newNode->left = buildTree();

    printf("Enter right child of %d:\n", value);
    newNode->right = buildTree();

    return newNode;
}

void traverseInOrder(struct Node* root) {
    if (root == NULL) return;
    traverseInOrder(root->left);
    printf("%d ", root->data);
    traverseInOrder(root->right);
}

void traversePreOrder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    traversePreOrder(root->left);
    traversePreOrder(root->right);
}

void traversePostOrder(struct Node* root) {
    if (root == NULL) return;
    traversePostOrder(root->left);
    traversePostOrder(root->right);
    printf("%d ", root->data);
}

int main() {
    printf("Build your binary tree:\n");
    struct Node* root = buildTree();

    printf("\nIn-Order Traversal: ");
    traverseInOrder(root);

    printf("\nPre-Order Traversal: ");
    traversePreOrder(root);

    printf("\nPost-Order Traversal: ");
    traversePostOrder(root);

    return 0;
}