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

    // inorder(root);
    // printf("\n");
    insert(root,7);
    insert(root,10);
    insert(root,8);
    insert(root,9);
    insert(root,11);


    inorder(root);

    int val = 6;
    if(search(root , val)){
        printf("\nfound %d", val );
    }
    else printf("not found"); 
    val = 14;
    if(search(root , val)){
        printf("\nfound %d", val );
    }
    else printf("\nnot found"); 
	return 0;
}