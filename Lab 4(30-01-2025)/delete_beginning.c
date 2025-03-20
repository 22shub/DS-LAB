#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* deleteHead(struct Node* head) {
    if (head == NULL)
        return NULL;
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}
void printList(struct Node* curr) {
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}
struct Node *createNode(int new_data){
    struct Node *new_node =
      (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}
int main() {
    struct Node* head = createNode(6);
    head->next = createNode(1);
    head->next->next = createNode(0);
    head->next->next->next = createNode(90);
    head = deleteHead(head);
    printList(head);

    return 0;
}