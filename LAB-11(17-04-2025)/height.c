#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *leftChild, *rightChild;
} TreeNode;

TreeNode* buildTree() {
    int value;
    printf("Enter node value (-1 for no node): ");
    scanf("%d", &value);

    if (value == -1) return NULL;

    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = value;

    printf("Enter left child of %d:\n", value);
    node->leftChild = buildTree();

    printf("Enter right child of %d:\n", value);
    node->rightChild = buildTree();

    return node;
}

void inorderTraversal(TreeNode* root) {
    if (root == NULL) return;

    inorderTraversal(root->leftChild);
    printf("%d ", root->data);
    inorderTraversal(root->rightChild);
}

int calculateHeight(TreeNode* root) {
    if (root == NULL) return 0;

    int leftHeight = calculateHeight(root->leftChild);
    int rightHeight = calculateHeight(root->rightChild);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main() {
    printf("Build the binary tree:\n");
    TreeNode* root = buildTree();

    printf("\nInorder Traversal of the Tree: ");
    inorderTraversal(root);

    int height = calculateHeight(root);
    printf("\nHeight of the Tree: %d\n", height);

    return 0;
}