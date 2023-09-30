#include <stdio.h>
#include<stdlib.h>



struct nd{
    int data;
    struct nd* next;

};




struct nodedouble {
    int data;
    struct nodedouble* next;
    struct nodedouble* prev;
};





struct stackarray {
    int *arr;
    int capacity, size, top;
};





struct liststack {
    struct nd* head;
    int size;
}s1;




struct queue {
    int *arr;
    int capacity, front, rear,size;
};



void insertatbeginsinglylinked(struct nd** head, int val){
    struct nd* ptr = (struct nd*)malloc(sizeof(struct nd));

    ptr->data=val;
    ptr->next=NULL;
    if (!head){

        *head = ptr;
        return;
    }
    ptr -> next=(*head);
    (*head) = ptr;


};





void insertatendsinglylinked(struct nd** head, int val){
    struct nd* ptr = (struct nd*)malloc(sizeof(struct nd));
    ptr->data=val;
    ptr->next=NULL;
    if (!head){
        *head = ptr;
        return;
    }
    struct nd* itr =  *head;
    while(itr->next){
        itr = itr -> next;
    }
    itr->next = ptr;

};





void insertaftersinglylinked(struct nd** head,int k, int val){
    struct nd* ptr = (struct nd*)malloc(sizeof(struct nd));
    ptr->data=val;
    ptr->next=NULL;
    if (!head){
        *head = ptr;
        return;
    }
    struct nd* itr =  *head;
    while(itr->data!=k && (itr->next)){
        itr = itr -> next;
    }
    ptr->next = itr->next;
    itr->next = ptr;

};





void printlistsinglylinked(struct nd** head){
    printf("\n\n");
    if(!head){
        printf("empty\n");
        return;
    }
    struct nd* itr = (*head);
    while(itr!= NULL ){


        printf("%d ",itr->data );
        printf("\t");
        itr = itr->next;

    }
    printf("\n\n");
};





void deletebeginsinglylinked(struct nd** head){
    if((*head)==NULL ||(*head)->next==NULL ){
        (*head) = NULL;
        return;
    }
    (*head) = (*head)-> next;
    return;
}

void deleteatksinglylinked(struct nd** head, int k){
    if((*head)==NULL ||(*head)->next==NULL ){
        (*head) = NULL;
        return;
    }
    struct nd* itr = (*head);
    while((itr -> next )-> data != k ){
        itr = itr -> next;
    }
    itr->next = itr ->next -> next;
    return;
}


void deleteendsinglylinked(struct nd** head){
    if((*head)==NULL ||(*head)->next==NULL ){
        (*head) = NULL;
        return;
    }
    struct nd* itr = (*head);
    while(((itr -> next )-> next ) !=NULL){
        itr = itr -> next;
    }
    itr->next = NULL;
    return;
}


void insertatbegindoublylinked(struct nodedouble** head, int val) {
    struct nodedouble* ptr = (struct nodedouble*)malloc(sizeof(struct nodedouble));
    ptr->data = val;
    ptr->prev = NULL;
    if (!(*head)) {
        ptr->next = NULL;
    } else {
        ptr->next = *head;
        (*head)->prev = ptr;
    }
    *head = ptr;
}

void printlistdoublylinked(struct nodedouble** head){
    if(!(*head)){
        printf("List is empty\n");
        return;
    }
    struct nodedouble* itr = (*head);
    while(itr!= NULL ){


        printf("%d ",itr->data );
        printf("\t");
        itr = itr->next;

    }
};




void insertatenddoublylinked(struct nodedouble** head, int val) {
    struct nodedouble* ptr = (struct nodedouble*)malloc(sizeof(struct nodedouble));
    ptr->data = val;
    ptr->next = NULL;
    if (!(*head)) {
        ptr->prev = NULL;
        *head = ptr;
        return;
    }
    struct nodedouble* itr = *head;
    while (itr->next) {
        itr = itr->next;
    }
    itr->next = ptr;
    ptr->prev = itr;
}





void insertafterdoublylinked(struct nodedouble** head, int k, int val) {
    struct nodedouble* ptr = (struct nodedouble*)malloc(sizeof(struct nodedouble));
    ptr->data = val;
    ptr->next = NULL;
    ptr->prev = NULL;
    if (!(*head)) {
        printf(" empty\n");
        return;
    }
    struct nodedouble* itr = *head;
    while (itr->data != k && itr->next) {
        itr = itr->next;
    }
    ptr->next = itr->next;
    ptr->prev = itr;
    if (itr->next) {
        itr->next->prev = ptr;
    }
    itr->next = ptr;
}





struct nodedouble* createdoublenode(int data) {
    struct nodedouble* ptr = (struct nodedouble*)malloc(sizeof(struct nodedouble));
    if (ptr == NULL) {
        printf("memory does not allocate\n");
        return NULL;
    }
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;
    return ptr;
}






void deletebegindoublylinked(struct nodedouble** head) {
    if (!head || !(*head)) {
        printf("empty\n");
        return;
    }
    struct nodedouble* ptr = *head;
    *head = (*head)->next;
    if (*head) {
        (*head)->prev = NULL;
    }
    free(ptr);
}





void deleteenddoublylinked(struct nodedouble** head) {
    if (!head || !(*head)) {
        printf("empty\n");
        return;
    }
    struct nodedouble* itr = (*head);
    while (itr->next != NULL) {
        itr = itr->next;
    }
    if (itr->prev) {
        itr->prev->next = NULL;
    } else {
        *head = NULL;
    }
    free(itr);
}





void deleteatkdoublylinked(struct nodedouble** head, int k) {
    if (!head || !(*head)) {
        printf("empty\n");
        return;
    }
    struct nodedouble* itr = (*head);
    while (itr != NULL && itr->data != k) {
        itr = itr->next;
    }
    if (!itr) {
        printf("Element %d does not exist\n", k);
        return;
    }
    if (itr->prev) {
        itr->prev->next = itr->next;
    } else {
        *head = itr->next;
    }
    if (itr->next) {
        itr->next->prev = itr->prev;
    }
    free(itr);
}





void insertatbegincircularlylinked(struct nodedouble** head, int val) {
    struct nodedouble* ptr = (struct nodedouble*)malloc(sizeof(struct nodedouble));
    ptr->data = val;
    if (!(*head)) {
        ptr->next = ptr;
        ptr->prev = ptr;
    } else
    {
        ptr->next = *head;
        ptr->prev = (*head)->prev;
        (*head)->prev->next = ptr;
        (*head)->prev = ptr;
    }
    *head = ptr;
}









void printlistcircularlylinked(struct nodedouble** head) {
    if (!(*head)) {
        printf("empty\n");
        return;
    }
    struct nodedouble* itr = (*head);
    do {
        printf("%d ", itr->data);
        printf("\t");
        itr = itr->next;
    } while (itr != (*head));
    printf("\n");
}







void insertatendcircularlylinked(struct nodedouble** head, int val) {
    struct nodedouble* ptr = (struct nodedouble*)malloc(sizeof(struct nodedouble));
    ptr->data = val;
    if (!(*head)) {
        ptr->next = ptr;
        ptr->prev = ptr;
        *head = ptr;
        return;
    }
    struct nodedouble* last = (*head)->prev;
    ptr->next = *head;
    ptr->prev = last;
    last->next = ptr;
    (*head)->prev = ptr;
}

void insertaftercircularlylinked(struct nodedouble** head, int k, int val) {
    struct nodedouble* ptr= (struct nodedouble*)malloc(sizeof(struct nodedouble));
    ptr->data = val;
    if (!(*head)) {
        printf("empty\n");
        return;
    }
    struct nodedouble* itr = *head;
    while (itr->data != k && itr->next != (*head)) {
        itr = itr->next;
    }
    ptr->next = itr->next;
    ptr->prev = itr;
    itr->next->prev = ptr;
    itr->next = ptr;
}






void deletebegincircularlylinked(struct nodedouble** head) {
    if (!(*head)) {
        printf("empty\n");
        return;
    }
    struct nodedouble* ptr = *head;
    if (ptr->next == ptr) {
        *head = NULL;
    } else {
        ptr->next->prev = ptr->prev;
        ptr->prev->next = ptr->next;
        *head = ptr->next;
    }
    free(ptr);
}




void deleteendcircularlylinked(struct nodedouble** head) {
    if (!(*head)) {
        printf("empty\n");
        return;
    }
    struct nodedouble* ptr = *head;
    if (ptr->next == ptr) {
        *head = NULL;
    } else {
        ptr = ptr->prev;
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
    }
    free(ptr);
}





void deleteatkcircularlylinked(struct nodedouble** head, int k) {
    if (!(*head)) {
        printf("empty\n");
        return;
    }
    struct nodedouble* ptr = *head;
    while (ptr->data != k && ptr->next != (*head)) {
        ptr = ptr->next;
    }
    if (ptr->data != k) {
        printf("Element %d does not found\n", k);
        return;
    }
    if (ptr->next == ptr) {
        *head = NULL;
    } else {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        if (ptr == *head) {
            *head = ptr->next;
        }
    }
    free(ptr);
}







void pusharr(struct stackarray *s1, int val) {
    if (s1->size == s1->capacity) {
        printf("Overflow\n");
        return;
    }
    s1->top++;
    s1->arr[s1->top] = val;
    s1->size++;
}




int sizearr(struct stackarray* s1){
    if (s1->top == -1) {
        printf("empty\n");
        return -1;
    }
    return s1->size;
}





int poparr(struct stackarray *s1) {
    if (s1->top == -1) {
        printf("Underflow\n");
        return -1;
    }
    int val = s1->arr[s1->top];
    s1->top--;
    s1->size--;
    return val;
}




void printstackarr(struct stackarray *s1) {
    if (s1->top == -1) {
        printf("Stack\n");
        return;
    }
    for (int i = 0; i <= s1->top; i++) {
        printf("%d\t", s1->arr[i]);
    }
    printf("\n");
}





int toparr(struct stackarray *s1) {
    if (s1->top == -1) {
        printf("Stack\n");
        return -1;
    }
    int top = s1->arr[s1->top];
    return top;
}




void initialisearr(struct stackarray *s1, int cap) {
    s1->capacity = cap;
    s1->size = 0;
    s1->top = -1;
    s1->arr = (int *)malloc(sizeof(int) * cap);
}


void initialiseliststack(struct liststack* s1) {
    s1->head= NULL;
    s1->size = 0;

    return ;

}
void pushliststack(struct liststack *s1, int val) {
    struct nd* ptr = (struct nd*)malloc(sizeof(struct nd));
    ptr ->data =val ;
    ptr->next = s1->head;
    s1->head = ptr;
    s1->size++;
}

int popliststack(struct liststack *s1) {
    if(s1->size == 0){
        printf("empty \n");
        return 0;
    }
    int val = s1->head->data;
    s1->head = s1->head->next;
    s1->size--;
    return val;

}

void printliststack(struct liststack *s1) {
    if (s1->size == 0){
        printf("empty .\n ");
        return ;

    }
    struct nd* ptr = s1->head;
    while(ptr){
        printf("%d  \t", ptr->data);
        ptr= ptr->next;
    }
    printf("\n");
}

int topliststack(struct liststack *s1) {
    if(s1->size == 0){
        printf("empty liststack. \n");
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



struct queue* initialisequeue(int cap) {
    struct queue* ptr = (struct queue*)malloc(sizeof(struct queue));
    ptr->capacity=cap;

    ptr->front = -1;
    ptr->rear = -1;
    ptr -> size = 0;
    ptr->arr = (int *)malloc(sizeof(int) * cap);
    return ptr;
}

void enque(struct queue* q1, int value){
    if(q1->size == q1->capacity){
        printf("Queue is full\n");
        return ;
    }
    q1->arr[q1->rear] = value;
    q1->rear = (q1->rear + 1)% q1->capacity;

    q1->size++;

}

int deque(struct queue*q1){
    if(q1->size ==0){
        printf("queue empty");
        return 0;

    }
    int val = (q1->arr[q1->front]);
    q1-> front = (q1->front + 1)%q1->capacity;
    q1->size--;
    return val;
}

void printqueue(struct queue* q1) {
    if (q1->size ==0) {
        printf("queue empty\n");
        return;
    }
    int i = q1->front;
    do {
        printf("%d ", q1->arr[i]);
        i = (i + 1) % q1->capacity;
    } while (i != (q1->rear + 1) % q1->capacity);
    printf("\n");
}





int main(){





    struct nd* head = NULL;
    struct nodedouble* dhead = NULL;
    struct stackarray s1;
    struct liststack s2;
    int choice,val;



    printf("enter your choice\n");
    printf("Press 1 for LINKED LISTS \n");
    printf("Press 2 for STACKS\n");




    int a;
    scanf("%d",&a);


    switch(a){
        case(1):
            //            linked_lists();
            printf("Press 1 for  SINGLY LINKED LISTS ::\n");

            printf("Press 2 for  DOUBLY LINKED LISTS ::\n");
            printf("Press 3 for  CIRCULAR LINKED LISTS ::\n");
            int b;
            scanf("%d",&b);

            switch (b){
                case 1:

                    while (1) {
                        printf("\nMenu:\n");
                        printf("1. Insert at the beginning\n");
                        printf("2. Insert at the end\n");
                        printf("3. Insert after a node\n");
                        printf("4. Delete from the beginning\n");
                        printf("5. Delete from the end\n");
                        printf("6. Delete a node\n");
                        printf("7. Print the list\n");
                        printf("8. Exit\n");
                        printf("Enter your choice: ");
                        scanf("%d", &choice);

                        switch (choice) {
                            case 1:
                                printf("Enter the value which want to insert: ");
                                int val;
                                scanf("%d", &val);
                                insertatbeginsinglylinked(&head, val);
                                break;

                            case 2:
                                printf("Enter the value which want to insert: ");
                                scanf("%d", &val);
                                insertatendsinglylinked(&head, val);
                                break;

                            case 3:
                                printf("Enter the value which want to insert after: ");
                                int k;
                                scanf("%d", &k);
                                printf("Enter the value which want to insert: ");
                                scanf("%d", &val);
                                insertaftersinglylinked(&head, k, val);
                                break;

                            case 4:
                                deletebeginsinglylinked(&head);
                                break;

                            case 5:
                                deleteendsinglylinked(&head);
                                break;

                            case 6:
                                printf("Enter the value which want to delete: ");
                                scanf("%d", &k);
                                deleteatksinglylinked(&head, k);
                                break;

                            case 7:
                                printlistsinglylinked(&head);
                                break;

                            case 8:
                                return 0;

                            default:
                                printf("Invalid choice, try again\n");
                        }
                    }

                case 2:

                    while (1) {
                        printf("\nMenu:\n");
                        printf("1. Insert at the beginning\n");
                        printf("2. Insert at the end\n");
                        printf("3. Insert after a node\n");
                        printf("4. Delete from the beginning\n");
                        printf("5. Delete from the end\n");
                        printf("6. Delete a node\n");
                        printf("7. Print the list\n");
                        printf("8. Exit\n");
                        printf("Enter your choice: ");
                        scanf("%d", &choice);

                        switch (choice) {
                            case 1:
                                printf("Enter the value which want to insert: ");
                                int val;
                                scanf("%d", &val);
                                insertatbegindoublylinked(&dhead, val);
                                break;

                            case 2:
                                printf("Enter the value which want to insert: ");
                                scanf("%d", &val);
                                insertatenddoublylinked(&dhead, val);
                                break;

                            case 3:
                                printf("Enter the value which want to insert after: ");
                                int k;
                                scanf("%d", &k);
                                printf("Enter the value which want to insert: ");
                                scanf("%d", &val);
                                insertafterdoublylinked(&dhead, k, val);
                                break;

                            case 4:
                                deletebegindoublylinked(&dhead);
                                break;

                            case 5:
                                deleteenddoublylinked(&dhead);
                                break;

                            case 6:
                                printf("Enter the value which want to delete: ");
                                scanf("%d", &k);
                                deleteatkdoublylinked(&dhead, k);
                                break;

                            case 7:
                                printlistdoublylinked(&dhead);
                                break;

                            case 8:
                                return 0;

                            default:
                                printf("Invalid choice, try again\n");
                        }
                    }


                case 3:

                    while (1) {
                        printf("\nMenu:\n");
                        printf("1. Insert at the beginning\n");
                        printf("2. Insert at the end\n");
                        printf("3. Insert after a node\n");
                        printf("4. Delete from the beginning\n");
                        printf("5. Delete from the end\n");
                        printf("6. Delete a node\n");
                        printf("7. Print the list\n");
                        printf("8. Exit\n");
                        printf("Enter your choice: ");
                        scanf("%d", &choice);

                        switch (choice) {
                            case 1:
                                printf("Enter the value which want to insert: ");
                                int val;
                                scanf("%d", &val);
                                insertatbegincircularlylinked(&dhead, val);
                                break;

                            case 2:
                                printf("Enter the value  which want to insert: ");
                                scanf("%d", &val);
                                insertatendcircularlylinked(&dhead, val);
                                break;

                            case 3:
                                printf("Enter the value which want to insert after: ");
                                int k;
                                scanf("%d", &k);
                                printf("Enter the value which want to insert: ");
                                scanf("%d", &val);
                                insertaftercircularlylinked(&dhead, k, val);
                                break;

                            case 4:
                                deletebegincircularlylinked(&dhead);
                                break;

                            case 5:
                                deleteendcircularlylinked(&dhead);
                                break;

                            case 6:
                                printf("Enter the value which want to delete: ");
                                scanf("%d", &k);
                                deleteatkcircularlylinked(&dhead, k);
                                break;

                            case 7:
                                printlistcircularlylinked(&dhead);
                                break;

                            case 8:
                                return 0;

                            default:
                                printf("Invalid choice. try again.\n");
                        }
                    }

            }



        case 2:


            // stack
            printf("Press 1 for ARRAY STACK : \n");
            printf("Press 2 for LINKED LIST STACK : \n");
            int x;
            scanf("%d",&x);

            switch (x)
            {

                case 1:
                    printf("Enter the length of stackarray : \n");
                    int cap;
                    scanf("%d",&cap);
                    initialisearr(&s1,cap);
                    while (1) {

                        printf("Enter 1 for PUSH : \n");
                        printf("Enter 2 for POP : \n");
                        printf("Enter 3 for TOP : \n");
                        printf("Enter 4 to PRINT STACK : \n");
                        printf("Enter 5 to SIZE : \n");
                        printf("Enter 6 to Exit : \n");
                        scanf("%d",&choice);
                        switch (choice)
                        {
                            case 1:
                                printf("Enter the value which you want to push :");
                                scanf("%d",&val);
                                pusharr(&s1,val);
                                break;
                            case 2:

                                printf("\n");
                                int poppedvalue = poparr(&s1);
                                printf("popped value : %d \n",poppedvalue);
                                break;


                            case 3:
                                printf("\n");
                                int top = toparr(&s1);
                                printf("TOP of the stack is : %d \n", top);
                                break;
                            case 4:
                                printstackarr(&s1);
                                break;
                            case 5:
                                printf("\n");
                                int size = sizearr(&s1);
                                printf("\n");
                                printf("Size of stack is %d \n\n",size);
                                break;
                            case 6:
                                return 0;
                            default:
                                printf("\n\n invalid choice , try again : \n\n");





                        }
                    }

                case 2:

                    initialiseliststack(&s2);
                    while (1) {

                        printf("Enter 1 for PUSH : \n");
                        printf("Enter 2 for POP : \n");
                        printf("Enter 3 for TOP : \n");
                        printf("Enter 4 to PRINT STACK : \n");
                        printf("Enter 5 to SIZE : \n");
                        printf("Enter 6 to Exit : \n");
                        scanf("%d",&choice);
                        switch (choice)
                        {
                            case 1:
                                printf("Enter the valueyou want to push :");
                                scanf("%d",&val);
                                pushliststack(&s2,val);
                                break;
                            case 2:

                                printf("\n");
                                int poppedvalue = popliststack(&s2);
                                printf("popped value : %d \n",poppedvalue);
                                break;


                            case 3:
                                printf("\n");
                                int top = topliststack(&s2);
                                printf("TOP of the stack is : %d \n", top);
                                break;
                            case 4:
                                printliststack(&s2);
                                break;
                            case 5:
                                printf("\n");
                                int size = sizeliststack(&s2);
                                printf("\n");
                                printf("Size of stack is %d \n\n",size);
                                break;
                            case 6:
                                return 0;
                            default:
                                printf("\n\n invalid choice , try again : \n\n");





                        }
                    }



            }





    }
}
//
//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAX_SIZE 100
//
//
//struct Queue {
//    int arr[MAX_SIZE];
//    int front, rear;
//};
//
//
//void initialize(struct Queue *queue) {
//    queue->front = -1;
//    queue->rear = -1;
//}
//
//
//int isEmpty(struct Queue *queue) {
//    return (queue->front == -1 && queue->rear == -1);
//}
//
//
//int isFull(struct Queue *queue) {
//    return (queue->rear == MAX_SIZE - 1);
//}
//
//
//void enqueue(struct Queue *queue, int data) {
//    if (isFull(queue)) {
//        printf("full.  enqueue.\n");
//        return;
//    } else if (isEmpty(queue)) {
//        queue->front = queue->rear = 0;
//    } else {
//        queue->rear++;
//    }
//    queue->arr[queue->rear] = data;
//}
//
//
//int dequeue(struct Queue *queue) {
//    int data;
//    if (isEmpty(queue)) {
//        printf("empty.  dequeue.\n");
//        return -1; //
//    } else if (queue->front == queue->rear) {
//        data = queue->arr[queue->front];
//        queue->front = queue->rear = -1;
//    } else {
//        data = queue->arr[queue->front];
//        queue->front++;
//    }
//    return data;
//}

//int main() {
//    struct Queue queue;
//    initialize(&queue);
//
//    enqueue(&queue, 1);
//    enqueue(&queue, 2);
//    enqueue(&queue, 3);
//
//    printf("Dequeued element: %d\n", dequeue(&queue));
//    printf("Dequeued element: %d\n", dequeue(&queue));
//
//    enqueue(&queue, 4);
//
//    printf("Dequeued element: %d\n", dequeue(&queue));
//    printf("Dequeued element: %d\n", dequeue(&queue));
//
//    return 0;
//}



//
//#include <stdio.h>
//#include <stdlib.h>
//
//
//struct Node {
//    int data;
//    struct Node* next;
//};
//
//
//struct Queue {
//    struct Node* front;
//    struct Node* rear;
//};
//
//struct Queue* createQueue() {
//    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
//    if (!queue) {
//        perror("Memory is not allocated, failed");
//        exit(EXIT_FAILURE);
//    }
//    queue->front = queue->rear = NULL;
//    return queue;
//}
//
//
//int isEmpty(struct Queue* queue) {
//    return (queue->front == NULL);
//}
//
//
//void enqueue(struct Queue* queue, int data) {
//    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//    if (!newNode) {
//        perror("Memory is not allocated, failed");
//        exit(EXIT_FAILURE);
//    }
//    newNode->data = data;
//    newNode->next = NULL;
//
//    if (isEmpty(queue)) {
//        queue->front = queue->rear = newNode;
//    } else {
//        queue->rear->next = newNode;
//        queue->rear = newNode;
//    }
//}
//
//
//int dequeue(struct Queue* queue) {
//    if (isEmpty(queue)) {
//        printf(" empty. Cannot dequeue.\n");
//        return -1; //
//    }
//
//    struct Node* temp = queue->front;
//    int data = temp->data;
//    queue->front = queue->front->next;
//    free(temp);
//
//    return data;
//}
//
//int main() {
//    struct Queue* queue = createQueue();
//
//    enqueue(queue, 1);
//    enqueue(queue, 2);
//    enqueue(queue, 3);
//
//    printf("Dequeued element: %d\n", dequeue(queue));
//    printf("Dequeued element: %d\n", dequeue(queue));
//
//    enqueue(queue, 4);
//
//    printf("Dequeued element: %d\n", dequeue(queue));
//    printf("Dequeued element: %d\n", dequeue(queue));
//
//    return 0;
//}
//



