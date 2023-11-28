#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node2 {
    int data;
    struct node2* next;
};

struct node3 {
    int data;
    struct node3* next;
};

struct node* createnode(int val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));

    if (temp == NULL) {
        printf("memory allocation failed\n");
        return 0;
    }

    temp->data = val;
    temp->next = NULL;
    return temp;
}

struct node2* createnode2(int val) {
    struct node2* temp = (struct node2*)malloc(sizeof(struct node2));

    if (temp == NULL) {
        printf("memory allocation failed\n");
        return 0;
    }

    temp->data = val;
    temp->next = NULL;
    return temp;
}

struct node3* createnode3(int val) {
    struct node3* temp = (struct node3*)malloc(sizeof(struct node3));

    if (temp == NULL) {
        printf("memory allocation failed\n");
        return 0;
    }

    temp->data = val;
    temp->next = NULL;
    return temp;
}

void merg(struct node** head, struct node2** head2) {
    struct node* itr = (*head);
    struct node2* itr2 = (*head2);
    struct node3* first = NULL;
    struct node3* second = NULL;

    while (itr != NULL && itr2 != NULL) {
        struct node3* new = createnode3(itr->data);
        if (first == NULL) {
            first = new;
            second = new;
        } 
        else {
            second->next = new;
            second = second->next;
        }
        itr = itr->next;
        
        new = createnode3(itr2->data);
        second->next = new;
        second = second->next;
        itr2 = itr2->next;
    }

    // handle remaining elements in the first list
    while (itr != NULL) {
        struct node3* new = createnode3(itr->data);
        second->next = new;
        second = second->next;
        itr = itr->next;
    }

    // Handle remaining elements in the second list
    while (itr2 != NULL) {
        struct node3* new = createnode3(itr2->data);
        second->next = new;
        second = second->next;
        itr2 = itr2->next;
    }

    // Print the merged list
    struct node3* temp = first;

    printf("the merged list is :-\n");

    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void printlist(struct node** head) {
    struct node* itr = (*head);

    if (!head) {
        printf("the list is empty");
        return;
    }

    printf("the first list is :-\n");

    while (itr != NULL) {
        printf("%d\t", itr->data);
        itr = itr->next;
    }
    printf("\n");
}

void printlist2(struct node2** head2) {
    struct node2* itr = (*head2);

    if (!head2) {
        printf("the list is empty");
        return;
    }

    printf("the second list is :-\n");

    while (itr != NULL) {
        printf("%d\t", itr->data);
        itr = itr->next;
    }
    printf("\n");
}

int main() {
    struct node* head = createnode(0);
    struct node* itr = head;

    struct node2* head2 = createnode2(5);
    struct node2* itr2 = head2;

    head->next = createnode(10);
    head->next->next = createnode(20);
    head->next->next->next = createnode(30);
    head->next->next->next->next = createnode(40);
    head->next->next->next->next->next = createnode(50);

    head2->next = createnode2(15);
    head2->next->next = createnode2(25);
    head2->next->next->next = createnode2(35);
    head2->next->next->next->next = createnode2(45);
    head2->next->next->next->next->next = createnode2(55);

    printlist(&head);
    printlist2(&head2);

    merg(&head, &head2);
}
