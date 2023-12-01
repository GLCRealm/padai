#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STACK_SIZE 50

typedef struct {
    int stack[MAX_STACK_SIZE];
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

void push(Stack *s, int data) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    s->top++;
    s->stack[s->top] = data;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    int data = s->stack[s->top];
    s->top--;
    return data;
}

int evaluatePostfix(char *postfix) {
    Stack stack;
    initializeStack(&stack);

    int i, operand1, operand2, result;
    for (i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            push(&stack, postfix[i] - '0');
        } else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/') {
            operand2 = pop(&stack);
            operand1 = pop(&stack);

            switch (postfix[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid operator: %c\n", postfix[i]);
                    exit(EXIT_FAILURE);
            }

            push(&stack, result);
        }
    }

    return stack.stack[stack.top];
}

int main() {
    char postfix[50];

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result after evaluation: %d\n", result);

    return 0;
}
