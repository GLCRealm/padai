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

//search

int search(struct node* root, int val){
    if(!root){
        return 0;
    }
    if(root -> data == val){
        return 1;
    }
    else if(val < root-> data){
        return search(root-> left,val);
    }
    else{
        return search(root->right,val);
    }
}

// delete
struct node *min(struct node *node) {
    struct node *current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}


struct node *deletenode(struct node *root, int val) {
    if (root == NULL) {
        return root;
    }

    // recursively search for the node to be deleted
    if (val < root->data) {
        root->left = deletenode(root->left, val);
    } else if (val > root->data) {
        root->right = deletenode(root->right, val);
    } else {
        // node with only one child or no child
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = min(root->right);

        root->data = temp->data;

        root->right = deletenode(root->right, temp->data);
    }
    return root;
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
    
    int b;
    printf("\nenter the element you want to deleat:-\n");
    scanf("%d",&b);

    deletenode(root,b);

    inorder(root);
    
    printf("\nenter the value you want to search:-\n");
    int val;
    scanf("%d",&val);

    if(search(root,val)==1){
        printf("\nElement %d found!\n",val);
    }
    else printf("not found");

	return 0;
}