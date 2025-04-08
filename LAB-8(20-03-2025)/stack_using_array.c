#include <stdio.h>

int storage[6];         // Stack storage
int pointer = -1;       // Stack pointer
int overflowFlag = 1;   // To avoid repeated overflow messages

void insert()
{
    int value;

    if (pointer == 6 - 1)
    {
        if (overflowFlag == 1)
        {
            printf("Stack overflow occurred\n");
            overflowFlag++;
        }
    }
    else
    {
        printf("Enter value: ");
        scanf("%d", &value);
        pointer++;
        storage[pointer] = value;
    }
}

void removeTop()
{
    if (pointer == -1)
    {
        printf("Stack underflow occurred\n");
    }
    else
    {
        int removedItem = storage[pointer];
        printf("Removed item: %d\n", removedItem);
        pointer--;
    }
}

void showStack()
{
    printf("Current stack: ");
    for (int i = pointer; i >= 0; i--)
    {
        printf("%d ", storage[i]);
    }
    printf("\n");
}

int main()
{
    insert();
    insert();
    insert();
    removeTop();
    showStack();

    return 0;
}

