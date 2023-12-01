#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node* next;

};
struct liststack {
    struct node* head;
    int size;
}s1;

void initialiseliststack(struct liststack* s1) {
    s1->head= NULL;
    s1->size = 0;

    return ;

}

void pushliststack(struct liststack *s1, int val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp ->data =val ;
    temp->next = s1->head;
    s1->head = temp;
    s1->size++;
}

int popliststack(struct liststack *s1) {
    if(s1->size == 0){
        printf("empty liststack \n");
        return 0;
    }
    int val = s1->head->data;
    s1->head = s1->head->next;
    s1->size--;
    return val;

}

void printliststack(struct liststack *s1) {
    if (s1->size == 0){
        printf("empty liststack\n ");
        return ;

    }
    struct node* temp = s1->head;
    while(temp){
        printf("%d  \t", temp->data);
        temp= temp->next;
    }
    printf("\n");
}

int topliststack(struct liststack *s1) {
    if(s1->size == 0){
        printf("empty liststack \n");
        return 0;
    }
    return s1->head->data;

}
int sizeliststack(struct liststack *s1){
    if(s1->size == 0){
        printf("empty liststack \n");
        return 0;
    }
    return   s1-> size;
}
int main() {
    struct liststack s1;
    initialiseliststack(&s1);
    printliststack(&s1);

    for(int i=0; i < 10; i++){
        pushliststack(&s1, i);
    }
    printliststack(&s1);

    int popped = popliststack(&s1);
    printf("popped value %d \n",popped);
    printliststack(&s1);

    printf("top = %d \n", topliststack(&s1));

    return 0;
}

