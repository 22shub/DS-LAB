#include <stdio.h>
#include <stdlib.h>

struct StackNode {
    int val;
    struct StackNode* link;
};

struct StackNode* stackA = NULL;
struct StackNode* stackB = NULL;

// Push a value onto the given stack
void pushToStack(struct StackNode** root, int item) {
    struct StackNode* node = (struct StackNode*)malloc(sizeof(struct StackNode));
    node->val = item;
    node->link = *root;
    *root = node;
}

// Pop the top element from the given stack
int popFromStack(struct StackNode** root) {
    if (*root == NULL) {
        printf("Stack is empty!\n");
        return -999;
    }

    struct StackNode* tempNode = *root;
    int removed = tempNode->val;
    *root = tempNode->link;
    free(tempNode);
    return removed;
}

// Print all elements from the given stack
void printStack(struct StackNode* top, int stackID) {
    printf("Contents of Stack %d: ", stackID);
    while (top != NULL) {
        printf("%d ", top->val);
        top = top->link;
    }
    printf("\n");
}

// Print combined content from both stacks
void showMergedList(struct StackNode* a, struct StackNode* b) {
    printf("Combined Linked List:\n");

    struct StackNode* ptr = a;
    while (ptr != NULL) {
        printf("%d ", ptr->val);
        ptr = ptr->link;
    }

    ptr = b;
    while (ptr != NULL) {
        printf("%d ", ptr->val);
        ptr = ptr->link;
    }

    printf("\n");
}

int main() {
    // Add elements to both stacks
    pushToStack(&stackA, 10);
    pushToStack(&stackA, 20);
    pushToStack(&stackA, 30);

    pushToStack(&stackB, 40);
    pushToStack(&stackB, 50);
    pushToStack(&stackB, 60);

    // Remove one element from each stack
    printf("Removed from Stack A: %d\n", popFromStack(&stackA));
    printf("Removed from Stack B: %d\n", popFromStack(&stackB));

    printf("\n");
    showMergedList(stackA, stackB);
    return 0;
}
