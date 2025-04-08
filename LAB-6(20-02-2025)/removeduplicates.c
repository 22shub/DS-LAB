#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int value;
    struct ListNode* next;
};

struct ListNode* eliminateDuplicates(struct ListNode* start) {
    struct ListNode* outer = start;
    while (outer != NULL) {
        struct ListNode* inner = outer;
        while (inner->next != NULL) {
            if (inner->next->value == outer->value) {
                struct ListNode* temp = inner->next;
                inner->next = inner->next->next;
                free(temp);
            } else {
                inner = inner->next;
            }
        }
        outer = outer->next;
    }
    return start;
}

void displayList(struct ListNode* start) {
    struct ListNode* current = start;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

struct ListNode* createNewNode(int value) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->value = value;
    node->next = NULL;
    return node;
}

int main() {
    struct ListNode* start = createNewNode(5);
    start->next = createNewNode(15);
    start->next->next = createNewNode(5);
    start->next->next->next = createNewNode(25);
    start->next->next->next->next = createNewNode(35);
    start->next->next->next->next->next = createNewNode(45);
    start->next->next->next->next->next->next = createNewNode(25);

    start = eliminateDuplicates(start);
    displayList(start);
    return 0;
}