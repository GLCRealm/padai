#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef struct {
    int stack[MAX_STACK_SIZE];
    int top;
} Stack;

void initializeStack(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX_STACK_SIZE - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int data) {
    if (isFull(s)) {
        printf("Stack is full. Cannot push element.\n");
        return;
    }
    s->top++;
    s->stack[s->top] = data;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot pop element.\n");
        return -1; 
    }
    int data = s->stack[s->top];
    s->top--;
    return data;
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return -1; 
    }
    return s->stack[s->top];
}

int main() {
    Stack stack;
    initializeStack(&stack);

    
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

   
    printf("Top element: %d\n", peek(&stack));

    
    printf("Popping elements:\n");
    while (!isEmpty(&stack)) {
        printf("%d\n", pop(&stack));
    }

    
    printf("Trying to pop from an empty stack:\n");
    printf("%d\n", pop(&stack));

    return 0;
}
