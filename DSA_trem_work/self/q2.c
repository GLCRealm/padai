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
    printf("The First list is :-\n");
    while(itr!=NULL){
        printf("%d\t",itr->data);
        itr=itr->next;
    }
    printf("\n");
};

void printlist2(struct node **head2){

    struct node* itr=(*head2);

    if(!head2){
        printf("the list is empty");
        return;
    }
    printf("The Second list is :-\n");
    while(itr!=NULL){
        printf("%d\t",itr->data);
        itr=itr->next;
    }
    printf("\n");
};

void merg(struct node**head,struct node**head2){
    struct node* itr=(*head);
    struct node* itr2=(*head2);
    struct node *ptr;


    ptr=createnode(itr->data);

    struct node*second=ptr;
    struct node *first =ptr; 
    itr=itr->next;

    while(itr||itr2){

        if(itr2!=NULL){
            second->next=createnode(itr2->data);
            itr2=itr2->next;
            second=second->next;
            first=first->next;
        }

        if(itr!=NULL){
            first->next=createnode(itr->data);
            itr=itr->next;
            first =first->next;
            second=second->next;
        }
    }
    printf("The Merge list is :-\n");
    while(ptr!=NULL){
        printf("%d \t",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

int main() {
    
    struct node*head=createnode(0);
    struct node*itr=head;

    struct node*head2=createnode(5);
    struct node*itr2=head2;

    head->next=createnode(10);
    head->next->next=createnode(20);
    head->next->next->next=createnode(30);
    head->next->next->next->next=createnode(40);
    head->next->next->next->next->next=createnode(50);
    
    head2->next=createnode(15);
    head2->next->next=createnode(25);
    head2->next->next->next=createnode(35);
    head2->next->next->next->next=createnode(45);
    head2->next->next->next->next->next=createnode(55);

    printlist(&head);
    printlist2(&head2);

    merg(&head,&head2);
}