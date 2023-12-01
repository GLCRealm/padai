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

void delval(struct node**head,int val){

    struct node*itr=(*head);

    //TO DELETE FIRST NODE
    if(itr->data==val){  
        (*head)=itr->next;
    }

    else{
        while (itr){

            if(itr->data!=val){
                itr=itr->next;
            }

            else if(itr->next==NULL){
                itr->prev->next=NULL;
                itr->prev=NULL;
            }

            // TO DELETE ANY NODE IN BETWEEN

            else{
                itr->prev->next=itr->next;
                itr->next->prev=itr;
            }

        }

        // TO DELETE LAST NODE

        if(itr==NULL){
            printf("linked list dosnt contain this value");
        }


    }
}

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


    delval(&head,20);

    printlist(&head);
}

