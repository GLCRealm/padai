#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAX_OUTPUT_SIZE 100

typedef struct {
    char stack[MAX_STACK_SIZE];
    int top;
} Stack;

void initializeStack(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return (s->top == MAX_STACK_SIZE - 1);
}

int isEmpty(Stack *s) {
    return (s->top == -1);
}

void push(Stack *s, char data) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    s->top++;
    s->stack[s->top] = data;
}

char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    char data = s->stack[s->top];
    s->top--;
    return data;
}

int precedence(char operator) {
    if (operator == '+' || operator == '-')
        return 1;
    else if (operator == '*' || operator == '/')
        return 2;
    else
        return 0;
}

void infixToPostfix(char *infix, char *postfix) {
    Stack stack;
    initializeStack(&stack);

    int i, j;
    j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        if (infix[i] >= '0' && infix[i] <= '9') {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(&stack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(&stack) && stack.stack[stack.top] != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack); 
        } else {
            while (!isEmpty(&stack) && precedence(stack.stack[stack.top]) >= precedence(infix[i])) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, infix[i]);
        }
    }

    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
}

int main() {
    char infix[100];
    char postfix[100];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
