#include <stdio.h>
#include <stdlib.h>

// Node structure
struct ListNode {
    int value;
    struct ListNode* next;
};

// Create a new node with given value
struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->value = val;
    node->next = NULL;
    return node;
}

// Split linked list into two halves
void splitList(struct ListNode* source, struct ListNode** firstHalf, struct ListNode** secondHalf) {
    struct ListNode* slow = source;
    struct ListNode* fast = source->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *firstHalf = source;
    *secondHalf = slow->next;
    slow->next = NULL;
}

// Merge two sorted linked lists
struct ListNode* sortedMerge(struct ListNode* a, struct ListNode* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    struct ListNode* result = NULL;

    if (a->value <= b->value) {
        result = a;
        result->next = sortedMerge(a->next, b);
    } else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }

    return result;
}

// Perform merge sort on the linked list
void mergeSort(struct ListNode** headRef) {
    struct ListNode* head = *headRef;
    if (head == NULL || head->next == NULL) return;

    struct ListNode *left = NULL, *right = NULL;

    splitList(head, &left, &right);

    mergeSort(&left);
    mergeSort(&right);

    *headRef = sortedMerge(left, right);
}

// Print linked list
void displayList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int count, value;

    printf("Enter number of nodes: ");
    scanf("%d", &count);

    struct ListNode *head = NULL, *temp = NULL;

    for (int i = 0; i < count; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);

        struct ListNode* newNode = createNode(value);

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    mergeSort(&head);

    printf("Sorted linked list: ");
    displayList(head);

    return 0;
}
