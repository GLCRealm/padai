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
    
    //this loop will help to resolve prob with value which is out of scope
    while(itr!=NULL){
        if(itr->data==val){
            ptr->data=val;
            ptr=ptr->next;
        }
        itr=itr->next;
    }
    itr=(*head);

    while(itr!=NULL){
        if(itr->data>val){
            ptr->data=itr->data;
            ptr=ptr->next;
        }
        itr=itr->next;
    }

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

int main(){
    
    struct node*head=createnode(2);
    struct node*itr=head;
    int a;

    head->next=createnode(4);
    head->next->next=createnode(7);
    head->next->next->next=createnode(3);
    head->next->next->next->next=createnode(9);
    head->next->next->next->next->next=createnode(1);

    printf("enter the Partition number (V):-\n");
    scanf("%d",&a);

    printlist(&head);
    arrange(&head,a);
}