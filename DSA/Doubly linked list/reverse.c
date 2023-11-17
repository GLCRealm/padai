#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* createnode(int val){

    struct node* temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("memory allocation failed");
    }

    temp->data=val;
    temp->next=NULL;
    temp->prev=NULL;
};






void printlist(struct node**head){

    struct node*itr=(*head);

    while(itr!=NULL){
        printf("%d\t",itr->data);
        itr=itr->next;
    }

}

void insertatend(struct node**head,struct node* newptr){
    if(*head==NULL)
        *head=newptr;
    else
    {
        struct node* itr=*head;
        while(itr->next!=NULL)
        {
            itr=itr->next;
        }
        itr->next=newptr;
        newptr->prev=itr;
    }
}


void reverse(struct node **head){

    struct node* itr=(*head);

    if(!head){
        printf("the list is empty");
        return;
    }

    while(itr->next!=NULL){
        //printf("%d\t",itr->data);
        itr=itr->next;
    }
    while(itr!=NULL){
        printf("%d\t",itr->data);
        itr=itr->prev;
    }
    printf("\n");
};


int main(){
    struct node*head=NULL;
    struct node* newptr=createnode(0);
    insertatend(&head,newptr);

    newptr=createnode(10);
    insertatend(&head,newptr);

    newptr=createnode(20);
    insertatend(&head,newptr);

    newptr=createnode(30);
    insertatend(&head,newptr);

    newptr=createnode(40);
    insertatend(&head,newptr);

    newptr=createnode(50);
    insertatend(&head,newptr);

    

    printlist(&head);
    reverse(&head);
}

