#include<stdio.h>
#include<stdlib.h>

//define singli node

struct node{
    int data;
    struct node* next;
};



 // create node

struct node* creatsingli(int val){

    struct node* temp=(struct node*)malloc(sizeof(struct node));
        
    if (temp==NULL){
        printf("memory allocation failed ");
        return 0;
    }

    temp->data=val;
    temp->next=NULL;
    return temp;

    };


 //print function

void printsingl(struct node** head1){
    struct node* temp=(*head1);

    if(temp==NULL){
        printf("the list is empty");
    }

    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
};


// instrt at begain

void insatbeg1(struct node** head1,int val){

    struct node* itr=(*head1);
    struct node* temp=creatsingli(val);

    if(!head1){     //if(head1=NULL)
        printf("empty list");
        (*head1)=temp;                                                                                    
    }

    temp->next=itr;
    (*head1)=temp;


}



// void singliud(struct node**head1,int a){

//     for(int i<=2;i=a;i++){
            
//         printf("enter the element of %d node");
//         scanf("%d",&c);

//         itr->next=creatsingli(c);
//         itr= itr->next;
//     }
//     itr->next=NULL;
// }
   




// void singli(){





    
// }
      
// //define doubly node

// struct doublnode{
//     int data;
//     struct doublenode* next;
//     struct doublenode* prev;
// };

// void doubly(){

//     struct doublnode* createrdoublynode(int val){

//         struct doublnode* temp=(struct doublnode*)malloc(sizeof(struct doublnode));
        
//         if (temp==NULL){
//             printf("memory allocation failed ");
//             return 0;
//         }

//         temp->data=val;
//         temp->next=NULL;
//         temp->prev=NULL;

//         return temp;
//     }


//     void printdoubly(struct doublnode** head){

//         struct doublnode* temp=(*head);

//         if(temp->next== NULL){
//             printf("the list is empty");
//         }

//         while(temp->next!=NULL){
//             printf("%d",temp->data);

//         }

//     }

//     };


// //function for choice of linked list

// void displaylinkedlist(int val){

//     printf("SELLECT THE KIND OF LINKED LIST YOU WANT\n");
//     printf("1. Singli Linked list\n");
//     printf("2. Doubli Linked list\n");
//     printf("3. Singli Circular Linked list\n");
//     printf("4. Doubli Circular Linked list\n");

// }

// //function for type of operation

// void displayoperation(){
//     printf("SELLECT THE OPERATION YOU WANT TO PERFORM\n");
//     printf("1. Insertion\n");
//     printf("2. Deletion\n");
//     printf("3. Reverse\n");
//     printf("4. Find\n");
// }



// main function


int main(){

    int a,b,c;

    printf("Enter the number of nodes");
    scanf("%d",&a);

    printf("enter the element of 1st node");
    scanf("%d",&b);

    struct node* head1=creatsingli(b);
    struct node* itr= head1;

    for(int i=2;i<=a;i++){

        printf("enter the element of %d node\n",i);
        scanf("%d",&c);

        itr->next=creatsingli(c);
        itr= itr->next;
    }
    itr->next=NULL;

    printsingl(&head1);
    insatbeg1(1);





    // int a,b,c;


    // printf("enter the no of nodes\n");
    // scanf("%d",&a);

    // printf("enter the element 1\n");
    // scanf("%d",&c);

    // struct node* head=creatnode(c);
    // struct node* itr=head;

    // for (int i = 2; i <=a ; i++)
    // {
    //     printf("enter the element %d\n",i);
    //     scanf("%d",&b);
    //     itr->next = creatnode(b);
    //     itr = itr->next;
    // }
    // itr->next = NULL;

    // printlist(&head);

}