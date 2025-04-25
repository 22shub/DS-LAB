#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("%d enqueued to the queue.\n", value);
}

void dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty. Nothing to dequeue.\n");
        return;
    }

    Node* temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    printf("%d dequeued from the queue.\n", temp->data);
    free(temp);
}

void display(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    Node* temp = q->front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    Queue* q = createQueue();
    int choice, value;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(q, value);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                display(q);
                break;
            case 4:
                printf("Exiting program.\n");
                free(q);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}