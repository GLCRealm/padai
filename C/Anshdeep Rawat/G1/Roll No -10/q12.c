#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->right = NULL;
    return newNode;
}

void insertNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->right != NULL) {
            temp = temp->right;
        }
        temp->right = newNode;
    }
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->right;
    }
    printf("\n");
}

void deleteNode(Node** head, int key) {
    if (*head == NULL) {
        printf("Empty list, cannot delete.\n");
        return;
    }

    Node* current = *head;
    Node* prev = NULL;

    if (current->data == key) {
        *head = current->right;
        free(current);
        return;
    }

    while (current != NULL && current->data != key) {
        prev = current;
        current = current->right;
    }

    if (current == NULL) {
        printf("Element not found. Unsuccessful search.\n");
        return;
    }

    prev->right = current->right;
    free(current);
    printf("Element with key %d deleted.\n", key);
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
    printf("Enter key to delete: ");
    scanf("%d", &key);
    deleteNode(&head, key);

    printf("Updated Linked List: ");
    displayList(head);

    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->right;
        free(temp);
    }

    return 0;
}
