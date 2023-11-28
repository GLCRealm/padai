#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node** head, int val) {
    struct Node* newNode = createNode(val);
    newNode->next = *head;
    *head = newNode;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void partitionList(struct Node** head, int V) {
    struct Node* lessThanV = NULL;
    struct Node* greaterThanOrEqualV = NULL;
    struct Node* temp = *head;

    while (temp != NULL) {
        struct Node* nextNode = temp->next;
        if (temp->data < V) {
            temp->next = lessThanV;
            lessThanV = temp;
        } else {
            temp->next = greaterThanOrEqualV;
            greaterThanOrEqualV = temp;
        }
        temp = nextNode;
    }

    // Connect the two partitions
    if (lessThanV != NULL) {
        *head = lessThanV;
        while (lessThanV->next != NULL) {
            lessThanV = lessThanV->next;
        }
        lessThanV->next = greaterThanOrEqualV;
    } else {
        *head = greaterThanOrEqualV;
    }
}

int main() {
    struct Node* head = NULL;
    int n, val, V;

    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);

    printf("Enter the elements of the linked list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insertNode(&head, val);
    }

    printf("Enter the value V for partitioning: ");
    scanf("%d", &V);

    printf("Original Linked List: ");
    printList(head);

    partitionList(&head, V);

    printf("Partitioned Linked List: ");
    printList(head);

    return 0;
}
