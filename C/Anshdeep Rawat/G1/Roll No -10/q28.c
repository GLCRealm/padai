#include <stdio.h>
#include <stdlib.h>
#define HASH_SIZE 10 

struct node {
    int data;
    struct node *left, *right;
};

struct node *createnode(int val) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void inorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d\t", root->data);
    inorder(root->right);
}

//hashing

int hashfx(int val) {
    return val % HASH_SIZE;
}

void insert(struct node **root, struct node *table[], int val) {
    int index = hashfx(val);
    struct node *temp = createnode(val);

    
    if (*root == NULL) {
        *root = temp;
    } 
    else {
        struct node *c = *root;
        struct node *p = NULL;

        while (c != NULL) {
            p = c;
            if (val == c->data) {
                free(temp);
                return;
            } else if (val < c->data) {
                c = c->left;
            } else {
                c = c->right;
            }
        }

        if (val < p->data) {
            p->left = temp;
        } else {
            p->right = temp;
        }
    }

    
    temp->right = table[index];
    table[index] = temp;
}

// Search function for the hash table
int search(struct node *table[], int val) {
    int index = hashfx(val);
    struct node *temp = table[index];

    while (temp != NULL) {
        if (temp->data == val) {
            return 1;
        }
        temp = temp->right;
    }

    return 0; 
}

int main() {
    struct node *root = NULL;

    struct node *table[HASH_SIZE];
    for (int i = 0; i < HASH_SIZE; i++) {
        table[i] = NULL;
    }

    insert(&root, table, 5);
    insert(&root, table, 3);
    insert(&root, table, 6);
    insert(&root, table, 1);
    insert(&root, table, 4);
    insert(&root, table, 7);
    insert(&root, table, 10);
    insert(&root, table, 8);
    insert(&root, table, 9);
    insert(&root, table, 11);


    printf("Inorder traversal of BST:\n");
    inorder(root);
    printf("\n");


    printf("Enter the value you want to search:\n");
    int val;
    scanf("%d", &val);

    // Hashing search
    if (search(table, val) == 1) {
        printf("Element %d found using hashing\n", val);
    } else {
        printf("Element %d not found using hashing.\n", val);
    }

    return 0;
}
