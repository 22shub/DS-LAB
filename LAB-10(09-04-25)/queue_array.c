#include <stdio.h>
#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

void enqueue() {
    if (rear == MAX - 1) {
        printf("The queue is full\n");
        return;
    }
    int data;
    printf("Enter the data: ");
    scanf("%d", &data);
    if (front == -1) {
        front = 0;
    }
    queue[++rear] = data;
    printf("Enqueued %d\n", data);
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("The queue is empty\n");
        front = rear = -1; 
        return;
    }
    printf("Dequeued %d\n", queue[front++]);
    if (front > rear) {
        front = rear = -1; 
    }
}

void peek() {
    if (front == -1 || front > rear) {
        printf("The queue is empty\n");
        return;
    }
    printf("Front element is %d\n", queue[front]);
}

void display() {
    if (front == -1 || front > rear) {
        printf("The queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n1: Enqueue\n2: Dequeue\n3: Peek\n4: Display\n5: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}