#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode; 
        *head = newNode;
    } else {
        newNode->next = (*head)->next;
        (*head)->next = newNode;
        *head = newNode;
    }
}

void delete(Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* current = (*head)->next;
    Node* previous = *head;

    
    while (current != *head && current->data != data) {
        previous = current;
        current = current->next;
    }

    if (current == *head && current->data != data) {
        printf("Element not found in the list\n");
        return;
    }

    previous->next = current->next;

    if (current == *head) {
        *head = previous;
    }

    free(current);
}

void display(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = head->next; 

    printf("Circular linked list: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head->next);

    printf("\n");
}

int main() {
    Node* head = NULL;

    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);

    display(head);

    delete(&head, 20);
    display(head);

    delete(&head, 40);

    display(head);


    while (head != NULL) {
        Node* temp = head->next;
        if (temp == head) {
            free(head);
            break;
        }
        head->next = temp->next;
        free(temp);
    }

    return 0;
}
