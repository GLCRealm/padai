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

struct node {
    int data;
    struct node *left, *right;
};

struct node* createnode(int val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void inorder(struct node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(struct node* root) {
    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void preorder(struct node* root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

struct node* insertnode(struct node* root, int val) {

    if (root==NULL) {
        return createnode(val);
    }

    if (val<root->data) {
        root->left = insertnode(root->left,val);
    } 

    else if (val>root->data) {
        root->right = insertnode(root->right,val);
    }

    return root;
}






struct node* searchKey(struct node* root, int val) {
    if (root == NULL || root->data == val) {
        return root;
    }

    if (val < root->data) {
        return searchKey(root->left, val);
    } 

    else {
        return searchKey(root->right, val);
    }
}

int countLeafNodes(struct node* root) {
    if (root == NULL) {
        return 0;
    }

    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    int leftCount = countLeafNodes(root->left);
    int rightCount = countLeafNodes(root->right);
    return leftCount + rightCount;
}

int hight(struct node* root) {
    if (root == NULL) {
        return 0;
    }

    // Recursively calculate the height of left and right subtrees
    int left = hight(root->left);
    int right = hight(root->right);
    int a;
    if(left>right) a= left;
    else a=right;
    return 1 + a;
}

int main() {
    struct node* root = createnode(50);

    printf("Enter the number of nodes to insert:-\n");
    int b;
    scanf("%d", &b);

    for (int i = 0; i < b; i++) {
        int value;
        printf("Enter the value for node %d: ", i + 1);
        scanf("%d", &value);
        root = insertnode(root, value);
    }

     // for inorder
    printf("Inorder: ");
    inorder(root);
    printf("\n");

     // for postorder
    printf("Postorder: ");
    postorder(root);
    printf("\n");

     // for preorder
    printf("Preorder: ");
    preorder(root);
    printf("\n");

    // for search
    // int a;
    // printf("Enter the value you want to search:-\n");
    // scanf("%d",&a);
    // struct node *search=searchKey(root,a);
    // if(search!=NULL){
    //     printf("founded %d in the tree\n",a);
    // }
    // else printf("No nodes with %d is in tree\n",a);

    // leafe nodes
    //printf("Total number of leaf nodes: %d\n", countLeafNodes(root));
   

    //printf("Height of the tree: %d\n", hight(root));
    return 0;
}
