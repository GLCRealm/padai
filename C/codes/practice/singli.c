#include <stdio.h>
#include <stdlib.h>



struct node{
    int data;
    struct node* next;
};




struct node* creatnode(int val){

    struct node*newnode=(struct node *) malloc(sizeof(struct node));

    if(newnode==NULL){
        printf("memory error\n");
        return NULL;
    }
    newnode->data=val;
    newnode->next=NULL;
    return newnode;
}



void printlist(struct node** head){

    struct node*irl = (*head);
    while(irl){
        printf("%d \t",irl->data);
        irl=irl->next;
    }

}



int main(){
    int a,c,i;
    
    printf("SINGLI LINKED LIST\n\n");
    printf("enter number of nodes you want\n");
    scanf("%d",&a);

    printf("enter the data for node 1\n",i);
    scanf("%d",&c);

    struct node* head=creatnode(a);

    for(i=2;i<=a;i++){
        int b;
        struct node* irl=(head);
        printf("enter the data for node %d\n",i);
        scanf("%d",&b);
        
        irl->next=creatnode(b);




    }

    
    printlist(&head);

}