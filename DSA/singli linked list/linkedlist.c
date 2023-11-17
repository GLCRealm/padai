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

int main(){
    
    struct node*head=createnode(0);
    struct node*itr=head;

    head->next=createnode(10);
    head->next->next=createnode(20);
    head->next->next->next=createnode(30);
    head->next->next->next->next=createnode(40);
    head->next->next->next->next->next=createnode(50);

    printlist(&head);
}