#include<stdio.h>
#include<stdlib.h>



struct node{
    int data;
    struct node* next;
};



struct node *creatnode(int val){
    struct node*temp=(struct node*)malloc(sizeof(struct node));

    if(temp==NULL){
        printf("empty list");
        return 0;
    }

    temp->data=val;
    temp->next=NULL;
    return temp;
}



void printlist(struct node** head){
    struct node *temp=(*head);
    if(!head){
        printf("list is empty");
        return;
    }

    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;

    }
    printf("\n");

};



void findmax(struct node**head){
    int max=(*head)->data;
    struct node* itr=(*head)->next;

    while(itr!=NULL){

        if(itr->data > max)
            max=itr->data;
        itr=itr->next ;
    }
    printf("\nthe biggest data in linked list is %d",max);
    
}

void findmin(struct node**head){
    int max=(*head)->data;
    struct node* itr=(*head)->next;

    while(itr!=NULL){

        if(itr->data < max)
            max=itr->data;
        itr=itr->next ;
    }
    printf("\nthe smallest data in linked list is %d\n",max);
    
}





void removesmallest(struct node ** head){

    int max=(*head)->data;
    struct node* itr=(*head)->next;

    while(itr!=NULL){

        if(itr->data < max)
            max=itr->data;
        itr=itr->next ;
    }

    itr=(*head);
    
    while(itr->next!=NULL&&itr->next->data!=max){
        itr=itr->next;
    }

    if((*head)!=NULL&&(*head)->data==max){
        struct node* temp=(*head);
        (*head)=(*head)->next;
        free(temp);
    }

    else if(itr->next!=NULL){
        struct node* temp=itr->next;
        itr->next=itr->next->next;
        free(temp);
    }
    
    else if (itr->next->next=NULL){
        struct node* temp=itr->next;
        itr->next=NULL;
        free(temp);
    }
    
    itr=(*head);

    while(itr!=NULL){
        printf("%d\t",itr->data);
        itr=itr->next;
    }
    printf("\n");
    
}



void removebiggest(struct node ** head){

    int max=(*head)->data;
    struct node* itr=(*head)->next;

    while(itr!=NULL){

        if(itr->data > max)
            max=itr->data;
        itr=itr->next ;
    }

    itr=(*head);
    
    while(itr->next!=NULL&&itr->next->data!=max){
        itr=itr->next;
    }

    if((*head)!=NULL&&(*head)->data==max){
        struct node* temp=(*head);
        (*head)=(*head)->next;
        free(temp);
    }

    else if(itr->next!=NULL){
        struct node* temp=itr->next;
        itr->next=itr->next->next;
        free(temp);
    }
    
    else if (itr->next->next=NULL){
        struct node* temp=itr->next;
        itr->next=NULL;
        free(temp);
    }
    
    itr=(*head);

    while(itr!=NULL){
        printf("%d\t",itr->data);
        itr=itr->next;
    }
    printf("\n");
    
}






int main(){
    int a,b,c;


    printf("enter the no of nodes\n");
    scanf("%d",&a);

    printf("enter the element 1\n");
    scanf("%d",&c);

    struct node* head=creatnode(c);
    struct node* itr=head;

    for (int i = 2; i <=a ; i++)
    {
        printf("enter the element %d\n",i);
        scanf("%d",&b);
        itr->next=creatnode(b);
        itr=itr->next;
    }
    itr->next=NULL;


    printlist(&head);
    findmax(&head);
    findmin(&head);
    removesmallest(&head);
    removebiggest(&head);
}