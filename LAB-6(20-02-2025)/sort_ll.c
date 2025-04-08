#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int value;
    struct ListNode* next;
};

struct ListNode* createNode(int val) {
    struct ListNode* node = 
        (struct ListNode*)malloc(sizeof(struct ListNode));
    node->value = val;
    node->next = NULL;
    return node;
}

struct ListNode* rearrangeEvenOdd(struct ListNode* head) {
    struct ListNode* evenStart = NULL;
    struct ListNode* evenEnd = NULL;
    struct ListNode* current = head;
    struct ListNode* previous = NULL;

    while (current != NULL) {
        if (current->value % 2 == 0) {
            if (previous != NULL) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            if (evenStart == NULL) {
                evenStart = current;
                evenEnd = evenStart;
            } else {
                evenEnd->next = current;
                evenEnd = evenEnd->next;
            }
            current = current->next;
        } else {
            previous = current;
            current = current->next;
        }
    }

    if (evenStart == NULL) {
        return head;
    }
    evenEnd->next = head;
    return evenStart;
}

void displayList(struct ListNode* node) {
    while (node != NULL) {
        printf("%d ", node->value);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct ListNode* head = createNode(2);
    head->next = createNode(15);
    head->next->next = createNode(8);
    head->next->next->next = createNode(25);
    head->next->next->next->next = createNode(30);
    head->next->next->next->next->next = createNode(18);
    head->next->next->next->next->next->next = createNode(22);
    head->next->next->next->next->next->next->next = createNode(9);

    printf("Original Linked List: ");
    displayList(head);

    head = rearrangeEvenOdd(head);

    printf("Modified Linked List: ");
    displayList(head);

    return 0;
}