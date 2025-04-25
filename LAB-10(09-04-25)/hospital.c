#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node *head = NULL, *tail = NULL;
int count = 0;

void enqueue(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->value = val;
    newNode->next = NULL;

    if (tail == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    count++;
}

void showQueue() {
    if (head == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

void refreshValues() {
    Node* current = head;
    int i = 1;

    while (current != NULL) {
        current->value = i++;
        current = current->next;
    }
}

void dequeue() {
    if (head == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head == NULL) {
        tail = NULL;
    }

    free(temp);
    count--;

    refreshValues();
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    printf("Queue after enqueues: ");
    showQueue();

    dequeue();
    printf("Queue after first dequeue: ");
    showQueue();

    enqueue(40);
    enqueue(50);
    printf("Queue after more enqueues: ");
    showQueue();

    dequeue();
    printf("Queue after second dequeue: ");
    showQueue();

    return 0;
}