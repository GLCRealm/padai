// #include <stdio.h>
// #include <stdlib.h>

// struct node{
//     int data;
//     struct node *left,*right;
// };

// struct node* cratenode(int val){
//     struct node* temp=(struct node *)malloc(sizeof(struct node));
//     temp->data=val;
//     temp->left=NULL;
//     temp->right=NULL;
//     return temp;
// }

// void intorder(struct node *root){
//     if(root==NULL){
//         return ;
//     }

//     intorder(root->left);
//     printf("%d",root->data);
//     intorder(root->left);
// }

// void postorder(struct node *root){
//     if(root==NULL){
//         return ;
//     }
//     postorder(root->left);
//     postorder(root->left);
//     printf("%d",root->data);
// }

// void preorder(struct node *root){
//     if(root==NULL){
//         return ;
//     }
//     printf("%d",root->data);
//     preorder(root->left);
//     preorder(root->left);
// }

// int main() {
				
//     struct node *root=cratenode(50);
//     root->left=cratenode(40);
//     root->left->left=cratenode(35);
//     root->left->left->right=cratenode(36);
//     root->left->right=cratenode(45);
//     root->left->right->left=cratenode(44);

//     root->right=cratenode(60);
//     root->right->left=cratenode(55);
//     root->right->left->left=cratenode(51);
//     root->right->right->left=cratenode(52);
//     root->right->right=cratenode(65);
//     root->right->right->left=cratenode(64);
//     root->right->right->right=cratenode(69);
//     intorder(root);
//     printf("\n");
//     postorder(root);
//     printf("\n");
//     preorder(root);
// }

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left, *right;
};

struct node* cratenode(int val){
    struct node* temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void inorder(struct node* root){
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(struct node* root){
    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void preorder(struct node* root){
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    struct node* root = cratenode(50);
    root->left = cratenode(40);
    root->left->left = cratenode(35);
    root->left->left->right = cratenode(36);
    root->left->right = cratenode(45);
    root->left->right->left = cratenode(44);

    root->right = cratenode(60);
    root->right->left = cratenode(55);
    root->right->left->left = cratenode(51);
    root->right->right = cratenode(65);
    root->right->right->left = cratenode(64);
    root->right->right->right = cratenode(69);

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    printf("Postorder: ");
    postorder(root);
    printf("\n");

    printf("Preorder: ");
    preorder(root);
    printf("\n");

    return 0;
}
