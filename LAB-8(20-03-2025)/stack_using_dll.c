#include <stdio.h>
#include <stdlib.h>

struct StackNode {
    int value;
    struct StackNode *next;
    struct StackNode *prev;
};

struct StackNode *stackTop = NULL;

void addToStack() {
    int num;
    printf("Enter value: ");
    scanf("%d", &num);

    struct StackNode *newNode = (struct StackNode *)malloc(sizeof(struct StackNode));
    newNode->value = num;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (stackTop == NULL) {
        stackTop = newNode;
    } else {
        newNode->next = stackTop;
        stackTop->prev = newNode;
        stackTop = newNode;
    }
}

void removeFromStack() {
    if (stackTop == NULL) {
        printf("Stack is empty. Cannot pop.\n");
        return;
    }

    struct StackNode *temp = stackTop;
    stackTop = stackTop->next;
    if (stackTop != NULL) {
        stackTop->prev = NULL;
    }
    free(temp);
}

void printStack() {
    struct StackNode *current = stackTop;
    printf("Stack contents: ");
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main() {
    addToStack();
    addToStack();
    addToStack();
    removeFromStack();
    printStack();

    return 0;
}
