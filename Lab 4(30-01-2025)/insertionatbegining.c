#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;  
    struct Node*next;  
};
struct Node* createNode(int new_data)
{
     struct Node* new_node= (struct Node*)malloc(sizeof(struct Node));
     new_node->data = new_data;
     new_node->next = NULL;
     return new_node;
}
struct Node* pushatfront
(struct Node* head, int new_data)
{
    struct Node* new_node = createNode(new_data);
    new_node->next = head;
    return new_node;
}
void showlist
(struct Node* head)
{
    struct Node* temp = head;
    while (temp != NULL) {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    struct Node* head = createNode(0);
    head->next = createNode(33);
    head->next->next = createNode(61);
    head->next->next->next = createNode(84);

    printf("the original Linked List s:");
    showlist
    (head);
    printf("After insertion:");
    int data = 10;
    head = pushatfront
    (head, data);
    showlist
    (head);
    return 0;
}



