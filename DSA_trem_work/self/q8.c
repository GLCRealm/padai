#include<stdio.h>
#include<stdlib.h>

struct node{
    int coff;
    struct node* next;
};

struct node* createnode(int val){

    struct node*temp=(struct node*)malloc(sizeof(struct node));

    if(temp== NULL){
        printf("memory allocation failed\n");
        return 0;
    }

    temp->coff=val;
    //temp->exp=exp;
    temp->next= NULL;
    return temp;
}

void printlist(struct node **head,int a){

    struct node* itr=(*head);

    if(!(*head)){
        printf("the list is empty\n");
        return;
    }

    for(int i=a;i>=0;i--){
        printf("%dx^%d\t",itr->coff,i);
        itr=itr->next;
    }
    printf("\n");
};

void insertnodes(struct node ** head,int a){
    int b;
    printf("enter the cofficient of %d power of x :-\n",a);
    scanf("%d",&b);
    (*head)=createnode(b);
    struct node*itr=(*head);

    for(int i=a-1;i>=0;i--){
        printf("enter the cofficient of %d power of x :-\n",i);
        int c;
        scanf("%d",&c);
        itr->next=createnode(c);
        itr=itr->next;
    }
}


void polyadd(struct node** head,struct node **head2,int a,int b){

    struct node*itr=(*head);
    struct node*itr2=(*head2);
    struct node* newhead=NULL;
    struct node * newheaditr=newhead;
    int c;

    if(b>a){
        newhead=itr;
        itr=itr2;
        itr2=newhead;
        c=a;
        a=b;
        b=c;
        newhead=NULL;
    }

    if(a>b){
        c=a-b;
        for(int i=0;i<c;i++){ // bring itr of longer list to equal
            if(!newheaditr){
                newheaditr=createnode(itr->coff);
                newhead=newheaditr;
            }
            else{
            newheaditr->next=createnode(itr->coff);
            newheaditr=newheaditr->next;
            }
            itr=itr->next;
        }
    }

    //print the uselss value
    while(itr!=NULL){
        if(!newheaditr){
            newheaditr=createnode(itr->coff+itr2->coff);
            newhead=newheaditr;
        }
        else{
        newheaditr->next=createnode(itr->coff+itr2->coff);
        newheaditr=newheaditr->next;
        }
        itr=itr->next;
        itr2=itr2->next;
    }

    printlist(&newhead,a);
}



int main(){

    //list
    struct node* head=NULL;
    printf("Enetr the highest power of x in first list:-\n");
    int a;
    scanf("%d",&a);
    insertnodes(&head,a);   

    //second list
    struct node* head2=NULL;
    printf("Enetr the highest power of x in seecond list:-\n");
    int b;
    scanf("%d",&b);
    insertnodes(&head2,b); 

    //print
    printf("The original expressions are :-\n");
    printlist(&head,a);
    printlist(&head2,b);

    printf("\nThe added expression is:-\n");
    polyadd(&head,&head2,a,b);

}