#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* buildTree(int preorder[], int* preorderIndex, int inorderStart, int inorderEnd, int* positionMap, int offset) {
    if (inorderStart > inorderEnd) return NULL;

    int currentValue = preorder[(*preorderIndex)++];
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->value = currentValue;
    node->left = node->right = NULL;

    if (inorderStart == inorderEnd) return node;

    int splitPosition = positionMap[currentValue - offset];
    node->left = buildTree(preorder, preorderIndex, inorderStart, splitPosition - 1, positionMap, offset);
    node->right = buildTree(preorder, preorderIndex, splitPosition + 1, inorderEnd, positionMap, offset);

    return node;
}

void displayInorder(struct TreeNode* root) {
    if (root == NULL) return;
    displayInorder(root->left);
    printf("%d ", root->value);
    displayInorder(root->right);
}

void freeTree(struct TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int inorder[100], preorder[100];
    int nodeCount = 0;

    printf("Input inorder traversal (space-separated): ");
    char inputBuffer[500];
    fgets(inputBuffer, sizeof(inputBuffer), stdin);
    char* token = strtok(inputBuffer, " \n");
    while (token && nodeCount < 100) {
        inorder[nodeCount++] = atoi(token);
        token = strtok(NULL, " \n");
    }

    int totalNodes = nodeCount;
    nodeCount = 0;

    printf("Input preorder traversal (space-separated): ");
    fgets(inputBuffer, sizeof(inputBuffer), stdin);
    token = strtok(inputBuffer, " \n");
    while (token && nodeCount < 100) {
        preorder[nodeCount++] = atoi(token);
        token = strtok(NULL, " \n");
    }

    if (nodeCount != totalNodes) {
        printf("Error: The number of nodes in traversals do not match.\n");
        return 1;
    }

    if (totalNodes == 0) {
        printf("The tree is empty.\n");
        return 0;
    }

    int minValue = inorder[0], maxValue = inorder[0];
    for (int i = 1; i < totalNodes; i++) {
        if (inorder[i] < minValue) minValue = inorder[i];
        if (inorder[i] > maxValue) maxValue = inorder[i];
    }

    int range = maxValue - minValue + 1;
    int* positionMap = (int*)malloc(range * sizeof(int));
    if (positionMap == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < range; i++) positionMap[i] = -1;
    for (int i = 0; i < totalNodes; i++) positionMap[inorder[i] - minValue] = i;

    int preorderIndex = 0;
    struct TreeNode* root = buildTree(preorder, &preorderIndex, 0, totalNodes - 1, positionMap, minValue);

    printf("\nTree constructed (Inorder traversal): ");
    displayInorder(root);
    printf("\n");

    free(positionMap);
    freeTree(root);

    return 0;
}