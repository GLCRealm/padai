#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data[100];
    struct Node* next;
} Node;

Node* createNode(char *data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node** head, char *data) {
    Node* newNode = createNode(data);
    

    if (*head == NULL || strcmp((*head)->data, newNode->data) > 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* current = *head;
    Node* prev = NULL;


    while (current != NULL && strcmp(current->data, newNode->data) < 0) {
        prev = current;
        current = current->next;
    }

    prev->next = newNode;
    newNode->next = current;
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%s -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;


    insertNode(&head, "apple");
    insertNode(&head, "banana");
    insertNode(&head, "cherry");
    insertNode(&head, "berry");
    insertNode(&head, "date");

    printf("Linked List: ");
    displayList(head);

    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
