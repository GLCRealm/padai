#include<stdio.h>
#include<stdlib.h>


//DEFINING THE NODE

struct node{
    int data;
    struct node* next;
};



//FUNCTION TO CREATE THE NODE

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



//FUNCTION TO PRINT THE LIST

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



//FUNCTION FOR INSERTING NODE AT END

void instertatend(struct node ** head,int val){

    struct node* temp=(struct node*)malloc(sizeof(struct node));

    struct node*itr=(*head);

    while(itr->next!=NULL){
        itr=itr->next;
    }

    itr->next=temp;
    temp->data=val;
    temp->next=NULL;
}



//FUNCTION FOR INSERTING NODE AT START

void instertatbegain(struct node ** head,int val){

    struct node* temp=(struct node*)malloc(sizeof(struct node));

    temp->next=(*head);
    temp->data=val;
    (*head)=temp;
}



//FUNCTION FOR INSERTING NODE AFTER A NODE

void insertaftervalue(struct node**head,int num,int val){
    struct node* temp=(struct node*)malloc(sizeof(struct node));

    struct node* itr=(*head);

    while (itr->data!=num){
        itr=itr->next;
    }

    temp->next=itr->next;
    itr->next=temp;
    temp->data=val;

}



//FUNCTION FOR INSERTING NODE BEFORE A NODE

void insertbefourvalue(struct node**head,int num,int val){
    struct node* temp=(struct node*)malloc(sizeof(struct node));

    struct node* itr=(*head);

    while (itr->next->data||itr->data!=num){
        itr=itr->next;
    }

    if((*head)==itr){
        temp->next=(*head);
        temp->data=val;
        (*head)=temp;
    }

    temp->next=itr->next;
    itr->next=temp;
    temp->data=val;

}



//FUNCTION FOR INSERTING NODE AT A PARTICULAR INDEX

void insertatindex(struct node ** head,int num,int val){

    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    struct node * itr =(*head);

    for(int i=0;i<num-1;i++){
        itr=itr->next;
    }


    if(itr==NULL){
        printf("this is not possible as the list dont have these many nodes ");
    }


    temp->next=itr->next;
    itr->next=temp;

    if(num==0){
        temp->data=(*head)->data;
        (*head)->data=val;

    }




}



//MAIN FUNCTION

int main(){

    //CREATION OF NODES

    struct node*head=createnode(0);
    struct node*itr=head;

    head->next=createnode(10);
    head->next->next=createnode(20);
    head->next->next->next=createnode(30);
    head->next->next->next->next=createnode(40);
    head->next->next->next->next->next=createnode(50);

    //OPERATIONS ARE BEING PERFORMED

    instertatend(&head,60);
    instertatbegain(&head,-10);
    insertaftervalue(&head,20,25);
    insertbefourvalue(&head,-10,5);
    insertatindex(&head,0,6);
    printlist(&head);
}