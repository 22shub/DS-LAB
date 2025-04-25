#include <stdio.h>
#define CAPACITY 100

int queue[CAPACITY];
int front = -1, rear = -1;

void addToQueue(int element) {
    if (rear == CAPACITY - 1) return;

    if (front == -1) front = 0;
    queue[++rear] = element;
}

int removeFromQueue() {
    if (front == -1 || front > rear) return -1;

    int removedElement = queue[front++];
    if (front > rear) front = rear = -1;
    return removedElement;
}

void reverseQueueRecursive() {
    int element = removeFromQueue();
    if (element == -1) return;

    reverseQueueRecursive();
    addToQueue(element);
}

void printQueue() {
    if (front == -1) return;

    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
}

int main() {
    int count, element;

    printf("Enter the number of elements: ");
    scanf("%d", &count);

    printf("Enter the elements: ");
    for (int i = 0; i < count; i++) {
        scanf("%d", &element);
        addToQueue(element);
    }

    printf("Queue before reversing: ");
    printQueue();

    reverseQueueRecursive();

    printf("\nQueue after reversing: ");
    printQueue();

    return 0;
}
