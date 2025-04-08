#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int value;
    struct ListNode* nextNode;
};

struct ListNode* reverseLinkedList(struct ListNode* start) {
    struct ListNode *current = start, *previous = NULL, *nextNode;
    while (current != NULL) {
        nextNode = current->nextNode;
        current->nextNode = previous;
        previous = current;
        current = nextNode;
    }
    return previous;
}

void displayList(struct ListNode* node) {
    while (node != NULL) {
        printf(" %d", node->value);
        node = node->nextNode;
    }
}

struct ListNode* createNewNode(int data) {
    struct ListNode* tempNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    tempNode->value = data;
    tempNode->nextNode = NULL;
    return tempNode;
}

int main() {
    struct ListNode* start = createNewNode(5);
    start->nextNode = createNewNode(3);
    start->nextNode->nextNode = createNewNode(6);
    start->nextNode->nextNode->nextNode = createNewNode(1);
    start->nextNode->nextNode->nextNode->nextNode = createNewNode(8);

    printf("Original Linked List:");
    displayList(start);
    start = reverseLinkedList(start);
    printf("\nReversed Linked List:");
    displayList(start);
    return 0;
}