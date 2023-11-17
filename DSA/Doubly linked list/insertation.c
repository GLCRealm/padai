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

/*

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

*/

void printlist(struct node**head){

    struct node*itr=(*head);

    while(itr!=NULL){
        printf("%d\t",itr->data);
        itr=itr->next;
    }

}

void insertatbegain(struct node**head,int val){
    struct node*itr=(*head);

    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;

    temp->next=itr;
    temp->prev=NULL;
    itr->prev=temp;
    (*head)=temp;
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

void insertaftervalue(struct node**head,int num,int val){
    
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    struct node*itr=(*head);

    while(itr->data!=num){
        itr=itr->next;
    }

    if(itr->next==NULL){
        temp->prev=itr;
        temp->next=NULL;
        itr->next=temp;
    }
    else{
    temp->next=itr->next;
    temp->prev=itr;
    temp->next->prev=temp;
    itr->next=temp;

}
}

/*
void insetrbefourvalue(struct node**head,int num,int val){
    struct node*itr=(*head);

    struct node* temp=(struct node*)malloc(sizeof(struct node));

    temp->data=val;
    temp->next=NULL;
    temp->prev=NULL;


    while(itr->data!=num){
        itr=itr->next;
    }

    //temp->data=val;
    temp->next=itr;
    temp->prev=itr->prev;
    itr->prev->next=temp;
    itr->prev=temp;
}

*/

//void insertbefourvalue(struuct node *head,int num, int val)

void insertbefourvalue(struct node**head,int num,int val){
     
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    struct node*itr=(*head);
    
    if(itr->data==num){
        temp->prev=NULL;
        temp->next=itr;
        itr->prev=temp;

        (*head)=temp;
    }




    else{

        while(itr->next->data!=num){
            itr=itr->next;
        }    

        temp->next=itr->next;
        temp->prev=itr;
        temp->next->prev=temp;
        itr->next=temp;

}
}

void insertatindex(struct node ** head,int num,int val){
    
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;

    struct node * itr=(*head);
    
    if(num==0){
        temp->next=itr;
        temp->prev=NULL;
        itr->prev=temp;

        (*head)=temp;
    }
    
    else{

    for(int i=1;i<num;i++){
        itr=itr->next;
    }

    if(itr==NULL){
        printf("linked list dont have %dth index\n",num);
    }

    else if(itr->next==NULL){
        temp->next=NULL;
        temp->prev=itr;
        itr->next=temp;
    }



    else{

    temp->next=itr->next;
    itr->next->prev=temp;
    temp->prev=itr;
    itr->next=temp;
}
}}

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

    /*head->next=createnode(10);

    head->next->next=createnode(20);
    head->next->next->next=createnode(30);
    head->next->next->next->next=createnode(40);*/

    insertatbegain(&head,-10);
    insertaftervalue(&head,30,15);
    insertbefourvalue(&head,30,-20);
    insertatindex(&head,3,-30);


    printlist(&head);
}

