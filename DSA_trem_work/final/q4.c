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

void printlist(struct node **head,int a){

    struct node* itr=(*head);

    if(!head){
        printf("the list is empty");
        return;
    }

    printf("the elements of %d list are:-\n",a);

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
    printf("the difference is:- %d\n",a-b);

}

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

    //first list
    struct node* head=NULL;
    printf("enetr the no of elements in 1st list:-\n");
    int a;
    scanf("%d",&a);
    insertnodes(&head,a);

    //second list
    struct node* head2=NULL;
    printf("enetr the no of elements in 2ed list:-\n");
    int b;
    scanf("%d",&b);
    insertnodes(&head2,b);

    //print
    printlist(&head,1);
    printlist(&head2,2);

    //difference
    diff(&head,&head2);

}