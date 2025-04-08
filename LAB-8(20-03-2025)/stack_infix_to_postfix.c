#include <stdio.h>
#include <stdlib.h>

struct StackNode {
    char symbol;
    struct StackNode *next;
};

struct StackNode *stackTop = NULL;

// Push character onto stack
void pushSymbol(char ch) {
    struct StackNode *newNode = (struct StackNode *)malloc(sizeof(struct StackNode));
    newNode->symbol = ch;
    newNode->next = stackTop;
    stackTop = newNode;
}

// Pop character from stack
void popSymbol() {
    if (stackTop == NULL) return;
    struct StackNode *temp = stackTop;
    stackTop = stackTop->next;
    free(temp);
}

// Return precedence of operators
int getPrecedence(char operator) {
    if (operator == '+' || operator == '-') return 1;
    if (operator == '*' || operator == '/') return 2;
    return 0;
}

// Convert infix expression to postfix
void convertToPostfix(char infix[], char postfix[], int length) {
    int outputIndex = 0;

    for (int i = 0; i < length; i++) {
        char current = infix[i];

        // Operand
        if ((current >= 'a' && current <= 'z') || 
            (current >= 'A' && current <= 'Z') || 
            (current >= '0' && current <= '9')) {
            postfix[outputIndex++] = current;
        }
        // Left parenthesis
        else if (current == '(') {
            pushSymbol(current);
        }
        // Right parenthesis
        else if (current == ')') {
            while (stackTop != NULL && stackTop->symbol != '(') {
                postfix[outputIndex++] = stackTop->symbol;
                popSymbol();
            }
            if (stackTop != NULL) {
                popSymbol();  // Pop '('
            }
        }
        // Operator
        else {
            while (stackTop != NULL && getPrecedence(stackTop->symbol) >= getPrecedence(current)) {
                postfix[outputIndex++] = stackTop->symbol;
                popSymbol();
            }
            pushSymbol(current);
        }
    }

    // Remaining operators in the stack
    while (stackTop != NULL) {
        postfix[outputIndex++] = stackTop->symbol;
        popSymbol();
    }

    postfix[outputIndex] = '\0';
}

int main() {
    char infixExpr[100], postfixExpr[100];
    int length;

    printf("Enter the length of the infix expression: ");
    scanf("%d", &length);

    printf("Enter the infix expression: ");
    for (int i = 0; i < length; i++) {
        scanf(" %c", &infixExpr[i]);  // space before %c to skip whitespace
    }
    infixExpr[length] = '\0';

    convertToPostfix(infixExpr, postfixExpr, length);
    printf("Postfix expression: %s\n", postfixExpr);

    return 0;
}
