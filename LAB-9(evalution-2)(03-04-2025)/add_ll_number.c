#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
} *list1 = NULL, *list2 = NULL, *result = NULL;

void buildList(struct Node **head, int count) {
    struct Node *current, *newNode;
    *head = (struct Node*) malloc(sizeof(struct Node));

    (*head)->next = NULL;
    scanf("%d", &(*head)->value);
    current = *head;

    for (int i = 1; i < count; i++) {
        newNode = (struct Node*) malloc(sizeof(struct Node));
        scanf("%d", &newNode->value);
        newNode->next = NULL;
        current->next = newNode;
        current = newNode;
    }
}

void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d ", node->value);
        node = node->next;
    }
}

void addLinkedLists(struct Node *a, struct Node *b) {
    struct Node *current, *temp;

    if (a == NULL) {
        result = b;
        return;
    }

    if (b == NULL) {
        result = a;
        return;
    }

    while (a && b) {
        if (result == NULL) {
            result = (struct Node*) malloc(sizeof(struct Node));
            result->value = a->value + b->value;
            current = result;
            current->next = NULL;
        } else {
            temp = (struct Node*) malloc(sizeof(struct Node));
            temp->value = a->value + b->value;
            temp->next = NULL;
            current->next = temp;
            current = temp;
        }

        a = a->next;
        b = b->next;
    }
}

int main() {
    int size1, size2;

    scanf("%d", &size1);
    buildList(&list1, size1);

    scanf("%d", &size2);
    buildList(&list2, size2);

    printf("After Addition:\n");
    addLinkedLists(list1, list2);
    printList(result);

    return 0;
}

