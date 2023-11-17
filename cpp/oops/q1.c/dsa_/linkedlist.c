#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node* next;
};


struct node* createnode(struct node * head,int val){

    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode=head;

    if(head==NULL){
        newnode -> data= val;
        newnode -> next =NULL;
        return newnode;
    }


    
};

void printlist(struct node* head){

    struct node* current=head;
    while(current!=NULL){
        printf("%d",current->data);
        printf("\t");
        current=current->next;
    }

};




int main(){

    struct node* head=NULL;

    createnode(head,0);
    createnode(head,5);
    createnode(head,10);
    createnode(head,15);
    createnode(head,20);
    printlist(head);

    
}