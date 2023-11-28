#include <stdio.h>
#include <stdlib.h>

//  implementing binary search tree

// node 
struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newnode(int val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

void insert(struct node** root, int val) {
    struct node* prev = NULL;
    struct node* current = *root;

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

    struct node* temp = newnode(val);
    if (prev == NULL) {
        *root = temp;
    } else if (val < prev->data) {
        prev->left = temp;
    } else {
        prev->right = temp;
    }
}

void inorder(struct node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d\t", root->data);
    inorder(root->right);
}

void preorder(struct node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d\t", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d\t", root->data);
    
}

// int search(struct node* root, int val){
//     if(!root){
//         return 0;
//     }
//     if(root -> data == val){
//         return 1;
//     }
//     else if(val < root-> data){
//         return search(root-> left,val);
//     }
//     else{
//         return search(root->right,val);
//     }
// }


int search(struct node* root, int val){
    if(!root){
        return 0 ;
    }
    if(root->data == val){
        return 1;
    }
    else if(root -> data > val){
        return search(root->left, val);
    }
    else{
        return search(root -> right, val); 
    }
}
struct node* minvaluenode(struct node* node) {
    struct node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }

    return current;
}

struct node* deletenode(struct node* root, int key) {
    if (root == NULL) {
        return root;
    }

    
    if (key < root->data) {
        root->left = deletenode(root->left, key);
    }
    
    else if (key > root->data) {
        root->right = deletenode(root->right, key);
    }
    
    else {

        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = minvaluenode(root->right);
        root->data = temp->data;
        root->right = deletenode(root->right, temp->data);
    }

    return root;
}

int main() {
    struct node* root = NULL;

    for (int i = 1; i < 11; i+= 2) {
        insert(&root, i);
    }
    printf("Inorder traversal:\n");
    inorder(root);
    printf("\n");

    printf("Preorder traversal:\n");
    preorder(root);
    printf("\n");

    printf("Postorder traversal:\n");
    postorder(root);
    printf("\n");

    printf("inserting node with value 4\n");
    insert(&root,4);
    inorder(root);
    printf("\n");

    int a = 0;
    while( a != -1){
        printf("enter the number to be inserted :");
        scanf("%d",&a);
        insert(&root,a);
        printf("inserting node with value %d \n", a);
        inorder(root);
        printf("\n");
    }


    
    if(search(root, 5)) printf("found 5 \n");
    else printf("not found \n");

    printf("deleting node with value 4\n");
    root = deletenode(root,4);
    inorder(root);
    printf("\n");

    printf("deleting node with value 5\n");
    root = deletenode(root,5);
    inorder(root);
    printf("\n");
    

    return 0;
}
