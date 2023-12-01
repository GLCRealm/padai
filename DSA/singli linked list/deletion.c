#include<stdio.h>
#include<stdlib.h>


//DEFINING THE NODE

struct node{
    int data;
    struct node* next;
};



//FUNCTION TO CREATE THE NODE

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



//FUNCTION TO PRINT THE LIST

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



//FUNCTION FOR INSERTING NODE AT END

void deleteatend(struct node ** head){

    struct node*itr=(*head);

    while(itr->next->next!=NULL){
        itr=itr->next;
    }

    itr->next=NULL;
}



//FUNCTION FOR DELETING THE STARTING NODE

void deleteatbegain(struct node ** head){

    struct node * itr=(*head);

    (*head)=itr->next;
}



//FUNCTION TO DELETE A NODE WITH PARTICULAR VALUE

void deleteatvalue(struct node**head,int num){

    struct node* itr=(*head);

    while (itr->next->data!=num){
        itr=itr->next;
    }

    itr->next=itr->next->next;


}



//FUNCTION FOR DELETING NODE AFTER A NODE

void deleteaftervalue(struct node**head,int num){

    struct node* itr=(*head);

    while (itr->data!=num){
        itr=itr->next;
    }

    itr->next=itr->next->next;

}



//FUNCTION FOR DELETION NODE BEFORE A NODE

void deletebefourvalue(struct node**head,int num){

    struct node* itr=(*head);

    if(itr->data==num){
        printf("NO NODE BEFOUR 1ST NODE SO DELETION IS NOT POSSIBLE...\n");
    }


    else{

    while (itr->next->data!=num){

        itr=itr->next;
    }

    itr->data=itr->next->data;
    itr->next=itr->next->next;

    }

}



//FUNCTION FOR DELETING NODE AT A PARTICULAR INDEX

void deleteatindex(struct node ** head,int num){

    struct node * itr =(*head);

    for(int i=0;i<num-1;i++){
        itr=itr->next;
    }

    if(num==0){
        itr->data=itr->next->data;
        itr->next=itr->next->next;

    }

    else{
        itr->next=itr->next->next;
    }

}



//MAIN FUNCTION

int main(){

    //CREATION OF NODES

    struct node*head=createnode(0);
    struct node*itr=head;

    head->next=createnode(10);
    head->next->next=createnode(20);
    head->next->next->next=createnode(30);
    head->next->next->next->next=createnode(40);
    head->next->next->next->next->next=createnode(50);

    //OPERATIONS ARE BEING PERFORMED

    //deleteatend(&head);
    //deleteatbegain(&head);
    //deleteatvalue(&head,20);
    //deleteaftervalue(&head,30);
    //deletebefourvalue(&head,50);
    deleteatindex(&head,0);
    printlist(&head);
}