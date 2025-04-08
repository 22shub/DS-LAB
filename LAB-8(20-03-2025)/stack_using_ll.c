#include <stdio.h>
#include <stdlib.h>

struct StackNode {
    int value;
    struct StackNode *link;
};

struct StackNode *stackTop = NULL;

// Push a new value onto the stack
void insertToStack() {
    int element;
    printf("Enter a number: ");
    scanf("%d", &element);

    struct StackNode *newElement = (struct StackNode *)malloc(sizeof(struct StackNode));
    newElement->value = element;
    newElement->link = stackTop;
    stackTop = newElement;
}

// Pop the top value from the stack
void removeFromStack() {
    if (stackTop == NULL) {
        printf("Stack is empty. Nothing to pop.\n");
        return;
    }

    struct StackNode *temp = stackTop;
    stackTop = stackTop->link;
    free(temp);
}

// Display all values in the stack
void printStack() {
    struct StackNode *current = stackTop;
    printf("Stack contents: ");
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->link;
    }
    printf("\n");
}

int main() {
    insertToStack();
    insertToStack();
    insertToStack();
    removeFromStack();
    printStack();

    return 0;
}
