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
    if (root==NULL||root->data==val) {
        return root;
    }

    if (val<root->data) {
        return searchKey(root->left,val);
    } 

    else {
        return searchKey(root->right,val);
    }
}

int leafnode(struct node* root) {
    if (root == NULL) {
        return 0;
    }

    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    int leftCount = leafnode(root->left);
    int rightCount = leafnode(root->right);
    return leftCount + rightCount;
}

int hight(struct node* root) {
    if (root==NULL) {
        return 0;
    }

    int left = hight(root->left);
    int right = hight(root->right);
    int a;
    if(left>right) a= left;
    else a=right;
    return 1 + a;
}

int countright(struct node* root) {
    if(root==NULL||(root->left==NULL&&root->right==NULL)){
        return 0;
    }
    return 1+ countright(root->left)+countright(root->right);
}

// delete
struct node* min(struct node* node) {
    struct node* ptr = node;
    while (ptr->left != NULL) {
        ptr = ptr->left;
    }
    return ptr;
}

struct node* delete(struct node* root, int val) {
    if (root == NULL) {
        return root;
    }

    if (val < root->data) {
        root->left = delete(root->left, val);
    } else if (val > root->data) {
        root->right = delete(root->right, val);
    } else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = min(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}



int main() {
    
    struct node * root=NULL;
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
    printf("\nInorder: ");
    inorder(root);
    printf("\n");

    // for postorder
    printf("\nPostorder: ");
    postorder(root);
    printf("\n");

     // for preorder
    printf("\nPreorder: ");
    preorder(root);
    printf("\n\n");

    //for search
    
    printf("Enter the value you want to search:-\n");
    int a;
    scanf("%d",&a);
    struct node *search=searchKey(root,a);
    if(search!=NULL){
        printf("\nFounded %d in the tree\n",a);
    }
    else printf("\nNo nodes with %d is in tree\n",a);


    //leafe nodes
    printf("\nTotal number of leaf nodes: %d\n", leafnode(root));
   
    // for hight
    printf("\nHeight of the tree:- %d\n", hight(root));

    //for nodes on right side
    printf("\nThe number of nodes on right side are:- %d\n", countright(root));

    //delelte
    printf("\nEnter the value of node you want to delete:-\n");
    int e;
    scanf("%d",&e);
    delete(root,e);
    // for inorder
    printf("\nInorder: ");
    inorder(root);
    printf("\n");

    // for postorder
    printf("\nPostorder: ");
    postorder(root);
    printf("\n");

     // for preorder
    printf("\nPreorder: ");
    preorder(root);
    printf("\n\n");


    return 0;
}