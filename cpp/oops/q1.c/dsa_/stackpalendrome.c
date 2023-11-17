#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 100

typedef struct {
    char data[MAX_LENGTH];
    int top;
} Stack;

void init(Stack *stack) {
    stack->top = -1;
}

int is_empty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, char item) {
    if (stack->top < MAX_LENGTH - 1) {
        stack->data[++stack->top] = item;
    } else {
        printf("Stack overflow\n");
    }
}

char pop(Stack *stack) {
    if (!is_empty(stack)) {
        return stack->data[stack->top--];
    } else {
        return '\0';  // Return null character for an empty stack
    }
}

bool is_palindrome(char *input_string) {
    int len = strlen(input_string);
    Stack stack;
    init(&stack);

    // Push the first half of the characters onto the stack
    int i;
    for (i = 0; i < len / 2; i++) {
        push(&stack, input_string[i]);
    }

    // Compare the remaining characters with the characters in the stack
    if (len % 2 == 1) {
        i++;  // Skip the middle character for odd-length strings
    }

    while (i < len && !is_empty(&stack)) {
        if (input_string[i] != pop(&stack)) {
            return false;
        }
        i++;
    }

    // If the stack is empty, it's a palindrome
    return is_empty(&stack);
}

int main() {
    char input_str[MAX_LENGTH];
    printf("Enter a string: ");
    scanf("%s", input_str);

    if (is_palindrome(input_str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
