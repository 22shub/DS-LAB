#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int value;
    struct TreeNode *leftChild, *rightChild;
};

int nodeCount = 0, leafCount = 0;

struct TreeNode* createTree() {
    int data;
    printf("Enter node value (-1 for no node): ");
    scanf("%d", &data);
    if (data == -1) return NULL;

    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->value = data;
    node->leftChild = node->rightChild = NULL;

    printf("Enter left child of %d:\n", data);
    node->leftChild = createTree();

    printf("Enter right child of %d:\n", data);
    node->rightChild = createTree();

    return node;
}

void calculateNodes(struct TreeNode* root) {
    if (root == NULL) return;

    nodeCount++;
    calculateNodes(root->leftChild);
    calculateNodes(root->rightChild);
}

void calculateLeaves(struct TreeNode* root) {
    if (root == NULL) return;

    if (root->leftChild == NULL && root->rightChild == NULL) {
        leafCount++;
    }
    calculateLeaves(root->leftChild);
    calculateLeaves(root->rightChild);
}

int main() {
    struct TreeNode* root = createTree();

    calculateNodes(root);
    calculateLeaves(root);

    printf("\nTotal Nodes: %d\n", nodeCount);
    printf("Leaf Nodes : %d\n", leafCount);

    return 0;
}