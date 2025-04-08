#include <stdio.h>
#include <stdlib.h>

struct StackNode {
    char letter;
    struct StackNode *next;
};

struct StackNode *stackTop = NULL;

// Push characters of a string to the stack
void loadToStack(char input[]) {
    int index = 0;
    while (input[index] != '\0') {
        struct StackNode *newNode = (struct StackNode *)malloc(sizeof(struct StackNode));
        newNode->letter = input[index];
        newNode->next = stackTop;
        stackTop = newNode;
        index++;
    }
}

// Pop top character from the stack
void removeTop() {
    if (stackTop == NULL) return;
    struct StackNode *temp = stackTop;
    stackTop = stackTop->next;
    free(temp);
}

int main() {
    char word[100];
    int size;

    printf("Enter the number of characters in the word: ");
    scanf("%d", &size);
    getchar(); // consume newline

    printf("Enter the word: ");
    for (int i = 0; i < size; i++) {
        scanf("%c", &word[i]);
    }
    word[size] = '\0';

    loadToStack(word); // Push characters into stack

    // Compare with original to check for palindrome
    int isPalindrome = 1;
    for (int i = 0; i < size; i++) {
        if (stackTop == NULL || stackTop->letter != word[i]) {
            isPalindrome = 0;
            break;
        }
        removeTop();
    }

    // Cleanup
    while (stackTop != NULL) removeTop();

    if (isPalindrome) {
        printf("✅ The word is a palindrome.\n");
    } else {
        printf("❌ The word is not a palindrome.\n");
    }

    return 0;
}
