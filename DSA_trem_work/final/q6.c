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

    if(!(*head)){
        printf("the list is empty");
        return;
    }

    while(itr!=NULL){
        printf("%d\t",itr->data);
        itr=itr->next;
    }
    printf("\n");
};

void pos_neg(struct node** head){
    struct node * itr=(*head);
    struct node * p =NULL;
    struct node *n =NULL;

    if(itr->data>=0){
        p=itr;
        itr=itr->next;

        while(n==NULL){
            if(itr->data<0){
                n=itr;
                break;
            }
            itr=itr->next;
        }
    }
    else{ 
        n=itr; 
        itr=itr->next;

        while(p==NULL){
            if(itr->data>=0){
                p=itr;
                break;
            }
            itr=itr->next;
        }
    }
    itr=(*head);
    
    struct node*ptemp=p;
    struct node*ntemp=n;
    while(itr!=NULL){

        if(itr==n){
            itr=itr->next;
            if(itr==p){
                itr=itr->next;
            }
        }

        if(itr==p){
            itr=itr->next;
            if(itr==n){
                itr=itr->next;
            }
        }

        if(itr->data>=0){
            ptemp->next=itr;
            ptemp=ptemp->next;
        }
        

        if(itr->data<0){
            ntemp->next=itr;
            ntemp=ntemp->next;  
                     
        }
        
        itr=itr->next;
    }

    printf("\n:::The seperated lists are:::\n\n");
    printf("The positive lists is:-\n");

    while(p!=ptemp->next){
        printf("%d\t",p->data);
        p=p->next;
    }

    printf("\n");
    printf("The negative lists is:-\n");

    while(n!=ntemp->next){
        printf("%d\t",n->data);
        n=n->next;
    }
    printf("\n");
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

    //list
    struct node* head=NULL;
    printf("enetr the no of elements in list:-\n");
    int a;
    scanf("%d",&a);
    insertnodes(&head,a);    

    //print
    printf("The original list is :-\n");
    printlist(&head);

    pos_neg(&head);

}