#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * next;
};





struct node* creatnode(int val){

    struct node* newnode=(struct node*) malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("memory error/n");
        return NULL;
    }
    newnode->data=val;
    newnode ->next=NULL;
    return newnode;

}




void insertatbegin(struct node **head,int val){
    struct node* temp = creatnode(val);
    if(!(*head)){          //if (*head) = NULL
        *head = temp;
        return;
    }
    temp->next = (*head);
    (*head) = temp;
    return;

}


void atindex(struct node**head,int val,int a){

    struct node *irl=(*head);
    struct node* temp= creatnode(val);
    int i=0;

    for(;i<a-1;i++){
        irl=irl ->next;
    }

    temp->next = irl->next;
    irl->next=temp;
    return;


}


void insertatend(struct node **head,int val){
    struct node *temp = creatnode(val);
    if(*head==NULL){
        *head = temp;
        return;
    }
    struct node *itr=(*head);
    while(itr->next != NULL){
        itr = itr-> next;
    }
    itr -> next = temp;
    return;
}




void insertaftervalue(struct node **head,int val,int a){
    struct node *irl=(*head);
    struct node* temp=creatnode(val);

    if(irl==NULL){
        irl->next=temp;
    }

    while(irl->data != a){
        irl=irl ->next;
    }
    temp->next = irl->next;
    irl->next=temp;
    return;
}





void insertbeforevalue(struct node **head,int val,int a){
    struct node *irl=(*head);
    struct node* temp=creatnode(val);

    if(irl==NULL){
        irl->next=temp;
    }

    while(irl->next->data != a){
        irl=irl ->next;
    }
    temp->next = irl->next;
    irl->next=temp;
    return;
}




void printlist(struct node **head){

    struct node *itr= (*head);

    while(itr){
        printf("%d \t",itr->data);
        itr = itr->next;
    }
}





int main() {

    int a;
    printf("enter the number for first input\n");
    scanf("%d",&a);


    struct node* head=creatnode(a);
    printf("the value is %d\n",head->data);


    for(int i = 0; i<11;i++){
        insertatend(&head, i);
    }
    printlist(&head);





    int b;
    int c;
    int d;

    //  printf("\nenetr the value after which you want to insert new node \n");
    //  scanf("%d",&c);

    //  printf("enetr the value which you want to insert in new node \n");
    //  scanf("%d",&b);

    //  insertbeforevalue(&head,b,c);

    //  printlist(&head);


    printf("\nenetr the index where you want new node \n");  //c = index
    scanf("%d",&c);

    printf("enetr the value which you want to insert in new node \n");      // data of node
    scanf("%d",&b);

    atindex(&head,b,c);

    printlist(&head);


}