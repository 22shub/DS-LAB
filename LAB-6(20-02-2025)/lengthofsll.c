#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int value;
    struct ListNode* nextNode;
};

struct ListNode* allocateNode(int data) {
    struct ListNode* node = 
       (struct ListNode*)malloc(sizeof(struct ListNode));
    node->value = data;
    node->nextNode = NULL;
    return node;
}

int getNodeCount(struct ListNode* start) {
    int total = 0;
    struct ListNode* current = start;
    while (current != NULL) {
        total++;
        current = current->nextNode;
    }
    return total;
}

int main() {
    struct ListNode* start = allocateNode(15);
    start->nextNode = allocateNode(7);
    start->nextNode->nextNode = allocateNode(9);
    start->nextNode->nextNode->nextNode = allocateNode(4);
    start->nextNode->nextNode->nextNode->nextNode = allocateNode(8);
    printf("Total nodes in the list: %d", getNodeCount(start));
    return 0;
}