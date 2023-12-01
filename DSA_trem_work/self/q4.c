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

void diff(struct node**head,struct node ** head2){
    struct node* itr=(*head);
    struct node* itr2=(*head2);
    int a=0,b=0;

    while(itr!=NULL||itr2!=NULL){

        if(itr!=NULL){
            a=a*10+itr->data;
            itr=itr->next;
        } 
        
        if(itr2!=NULL){
            b=b*10+itr2->data;
            itr2=itr2->next;
        }
    }

    printf("%d\n",a-b);

}

int main(){
    //list1
    struct node*head=createnode(8);
    struct node*itr=head;

    head->next=createnode(9);
    head->next->next=createnode(7);

    //list2
    struct node*head2=createnode(1);
    struct node*itr2=head2;

    head2->next=createnode(4);
    head2->next->next=createnode(5);

    printlist(&head);
    printlist(&head2);
    diff(&head,&head2);

}