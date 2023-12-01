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

void insert(struct node** head, int val){
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp -> data = val;
    // temp -> next = NULL;
    if(!(*head)){
        temp->next = NULL;
        *head = temp;

        return;     
    }
    temp->next = (*head);
    (*head) = temp;
    return;
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

    printf("\nThe seperated lists are:-\n\n");
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

int main(){

    struct node*head=createnode(1);
    struct node*itr=head;
    insert(&head, -2);
    insert(&head, 2);
    insert(&head, -5);
    insert(&head, -3);
    insert(&head, 9);
    insert(&head, 25);
    insert(&head, 91);
    insert(&head, -546);
    printf("The original list is :-\n");
    printlist(&head);

    pos_neg(&head);

}