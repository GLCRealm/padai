#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

Node* searchNode(Node* head, int key) {
    Node* current = head;

    while (current != NULL) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    insertNode(&head, 10);
    insertNode(&head, 20);
    insertNode(&head, 30);
    insertNode(&head, 40);

    printf("Linked List: ");
    displayList(head);

    int key;
    printf("Enter value to search: ");
    scanf("%d", &key);

    Node* resultNode = searchNode(head, key);
    if (resultNode != NULL) {
        printf("Node with value %d found at address: %p\n", key, (void *)resultNode);
    } else {
        printf("Node with value %d not found.\n", key);
    }

    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
