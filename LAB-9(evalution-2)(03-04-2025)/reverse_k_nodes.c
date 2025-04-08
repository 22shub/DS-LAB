#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *start = NULL;

void reverseFirstK(struct ListNode **ref_head, int limit) {
    if (*ref_head == NULL || limit == 1) return;

    struct ListNode *curr = *ref_head;
    struct ListNode *prev = NULL, *ahead = NULL;
    struct ListNode *tailEnd = NULL;
    int counter = 0;

    while (curr != NULL && counter < limit) {
        ahead = curr->next;
        curr->next = prev;
        prev = curr;
        curr = ahead;
        counter++;
    }

    if (tailEnd != NULL) {
        tailEnd->next = curr;
    }

    *ref_head = prev;

    if (*ref_head != NULL) {
        tailEnd = *ref_head;
        while (tailEnd->next != NULL) {
            tailEnd = tailEnd->next;
        }
    }
}

void showList(struct ListNode *node) {
    while (node != NULL) {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");
}

void appendNode(int value) {
    struct ListNode *newElement = (struct ListNode *)malloc(sizeof(struct ListNode));
    newElement->val = value;
    newElement->next = NULL;

    if (start == NULL) {
        start = newElement;
    } else {
        struct ListNode *itr = start;
        while (itr->next != NULL) {
            itr = itr->next;
        }
        itr->next = newElement;
    }
}

int main() {
    int total, k, input;

    printf("Enter total number of elements: ");
    scanf("%d", &total);

    printf("Enter k value: ");
    scanf("%d", &k);

    printf("Input list values:\n");
    for (int i = 0; i < total; i++) {
        scanf("%d", &input);
        appendNode(input);
    }

    reverseFirstK(&start, k);
    showList(start);

    return 0;
}
