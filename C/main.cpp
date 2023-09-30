#include <stdio.h>
#include <stdlib.h>

// Node structure for a doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

// Function to insert a new node at the middle of the list
void insertAtMiddle(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL.\n");
        return;
    }

    struct Node* newNode = createNode(data);

    newNode->next = prevNode->next;
    prevNode->next = newNode;
    newNode->prev = prevNode;

    if (newNode->next != NULL)
        newNode->next->prev = newNode;
}

// Function to delete a node from the middle or end of the list
void deleteNode(struct Node** head, struct Node* nodeToDelete) {
    if (*head == NULL || nodeToDelete == NULL)
        return;

    if (*head == nodeToDelete)
        *head = nodeToDelete->next;

    if (nodeToDelete->next != NULL)
        nodeToDelete->next->prev = nodeToDelete->prev;

    if (nodeToDelete->prev != NULL)
        nodeToDelete->prev->next = nodeToDelete->next;

    free(nodeToDelete);
}

// Function to count the number of nodes in the list
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

// Function to display the doubly linked list
void displayList(struct Node* head) {
    struct Node* current = head;

    printf("Doubly linked list: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert at the beginning
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    displayList(head);

    // Insert at the middle
    struct Node* firstNode = head;
    insertAtMiddle(firstNode, 15);
    displayList(head);

    // Count the number of nodes
    printf("Number of nodes: %d\n", countNodes(head));

    // Delete a node
    struct Node* nodeToDelete = head->next;
    deleteNode(&head, nodeToDelete);
    displayList(head);

    // Count the number of nodes after deletion
    printf("Number of nodes: %d\n", countNodes(head));

    return 0;
}
