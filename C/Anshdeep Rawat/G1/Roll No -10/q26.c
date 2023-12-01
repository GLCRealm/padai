#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left, * right;
};

struct node* createnode(int val){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp-> data = val;
    temp->left= NULL;
    temp->right = NULL;
    return temp;
} 

void inorder(struct node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
}

// insert function to insert in a bst
void insert(struct node* root, int val) {
    struct node* prev = NULL;
    struct node* current = root;

    while (current != NULL) {
        prev = current;
        if (val == current->data) {
            return;
        } else if (val < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    struct node* temp = createnode(val);
    if (prev == NULL) {
        root = temp; 
    } else if (val < prev->data) {
        prev->left = temp;
    } else {
        prev->right = temp;
    }
}

// linear search function on a BST
int linearsearch(struct node *root, int val) {
    if (root == NULL) {
        return 0; // Not found
    }

    // Perform in-order traversal (linear search)
    if (linearsearch(root->left, val) || root->data == val || linearsearch(root->right, val)) {
        return 1; // Found
    }

    return 0; // Not found
}

int main() {
    struct node* root = createnode(5);
    struct node* p1 = createnode(3);
    struct node* p2 = createnode(6);
    struct node* p3 = createnode(1);
    struct node* p4 = createnode(4);
    root ->left  = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;

    insert(root,7);
    insert(root,10);
    insert(root,8);
    insert(root,9);
    insert(root,11);

    inorder(root);
    
    printf("\nenter the value you want to search:-\n");
    int val;
    scanf("%d",&val);

    if(linearsearch(root,val)==1){
        printf("Element %d found!\n",val);
    }
    else printf("Not Found\n");
}
