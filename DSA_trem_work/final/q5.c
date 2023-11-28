#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* createnode(int val){

    struct node*temp=(struct node*)malloc(sizeof(struct node));

    if(temp== NULL){
        printf("memory allocation failed\n");
        return 0;
    }

    temp->data=val;
    temp->next= NULL;
    return temp;
}

void printlist(struct node **head){

    struct node* itr=(*head);

    if(!head){
        printf("the list is empty");
        return;
    }

    while(itr!=NULL){
        printf("%d\t",itr->data);
        itr=itr->next;
    }
    printf("\n");
};

void rearrange(struct node ** head){
    struct node *itr=(*head);
    struct node *ptr=(*head);
    struct node *nextnode;

    //fast pointer

    while(ptr!=NULL&&ptr->next!=NULL){
        itr=itr->next; // now my itr is at middle of linked list
        ptr=ptr->next->next;
    }
    ptr=NULL;


    //reverse the linked list

    while (itr != NULL) {
        nextnode = itr->next;
        itr->next = ptr;
        ptr = itr;
        itr = nextnode;
    }

    //remove last element from itr
    itr=(*head);
    while(itr->next->next != NULL){
        itr=itr->next;
    }
    itr->next =NULL;

    //print the arranged linked list
    itr=(*head);
    printf("The arranged list is :-\n");
    while(ptr!=NULL||itr!=NULL){
        if(itr!=NULL){
            printf("%d\t",itr->data);
            itr=itr->next;
        }

        if(ptr!=NULL) {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }

    }
    printf("\n");

}

void insertnodes(struct node ** head,int a){

    printf("enter the 1 element for linked list :-\n");
    int b;
    scanf("%d",&b);
    (*head)=createnode(b);
    struct node*itr=(*head);

    for(int i=2;i<=a;i++){
        printf("enter the %d element for linked list :-\n",i);
        int c;
        scanf("%d",&c);
        itr->next=createnode(c);
        itr=itr->next;
    }
}

int main(){
    
    //list
    struct node* head=NULL;
    printf("enetr the no of elements in list:-\n");
    int a;
    scanf("%d",&a);
    insertnodes(&head,a);

    printf("The original list is :-\n");
    
    //print
    printlist(&head);

    //rearrange
    rearrange(&head);

}