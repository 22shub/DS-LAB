#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int value;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

TreeNode* addNode(TreeNode* root, int value) {
    if (root == NULL) return createNode(value);
    if (value < root->value)
        root->left = addNode(root->left, value);
    else
        root->right = addNode(root->right, value);
    return root;
}

void traverseInOrder(TreeNode* root, int array[], int* index) {
    if (root == NULL) return;
    traverseInOrder(root->left, array, index);
    array[(*index)++] = root->value;
    traverseInOrder(root->right, array, index);
}

void searchPair(TreeNode* root, int targetSum) {
    int elements[1000], count = 0;
    traverseInOrder(root, elements, &count);

    int start = 0, end = count - 1;
    while (start < end) {
        int currentSum = elements[start] + elements[end];
        if (currentSum == targetSum) {
            printf("%d %d\n", elements[start], elements[end]);
            return;
        } else if (currentSum < targetSum) {
            start++;
        } else {
            end--;
        }
    }

    printf("No pair found\n");
}

int main() {
    TreeNode* root = NULL;
    int numElements, value, targetSum;

    scanf("%d", &numElements);
    for (int i = 0; i < numElements; i++) {
        scanf("%d", &value);
        root = addNode(root, value);
    }

    scanf("%d", &targetSum);
    searchPair(root, targetSum);

    return 0;
}
