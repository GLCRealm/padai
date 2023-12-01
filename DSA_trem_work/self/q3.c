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

struct node* createnode2(){

    struct node*temp=(struct node*)malloc(sizeof(struct node));

    if(temp== NULL){
        printf("memory allocation failed\n");
        return 0;
    }

    //temp->data=val;
    temp->next= NULL;
    return temp;
}

void arrange(struct node **head,int val){

    struct node * itr=(*head);
    struct node * ptr=(*head);
    int count=0;
    struct node* newnode=createnode2();

    while(ptr!=NULL){
        count++;
        ptr=ptr->next;
    }
    ptr=newnode;

    for(int i=1;i<count;i++){
        ptr->next=createnode2();
        ptr=ptr->next;
    }
    ptr=newnode;

    while(itr!=NULL){
        if(itr->data<val){
            ptr->data=itr->data;
            ptr=ptr->next;
        }
        itr=itr->next;
    }
    itr=(*head);
    
    //this loop will help to all numbers which are bigger orequal
    while(itr!=NULL){
        
        if(itr->data==val){
            ptr->data=val;
            ptr=ptr->next;
            itr=itr->next;
        }

        if(itr->data>val){
            ptr->data=itr->data;
            ptr=ptr->next;
        }
        itr=itr->next;
    }
    itr=(*head);

    ptr=newnode;
    printf("the Arranged linkedlist is :-\n");
    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");

}

void printlist(struct node **head){

    struct node* itr=(*head);

    if(!head){
        printf("the list is empty");
        return;
    }

    printf("the Original linked list is :-\n");

    while(itr!=NULL){
        printf("%d\t",itr->data);
        itr=itr->next;
    }
    printf("\n");
};

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
    
    struct node*head=NULL;
    int a;

    printf("Enter the no of elements in list:-\n");
    scanf("%d",&a);
    insertnodes(&head,a);

    printf("enter the Partition number (V):-\n");
    scanf("%d",&a);

    printlist(&head);
    arrange(&head,a);
}