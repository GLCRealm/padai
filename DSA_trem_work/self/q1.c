#include <stdio.h>
#include <stdlib.h>

// Struct for product information
struct ProductInfo {
    char Product_Id;
    char Product_Name[100];
    int Total_sale;
    char Product_Grade;
};

// Node structure
struct node {
    struct ProductInfo data;
    struct node* next;
};

// Queue structure
struct queue {
    int size;
    struct node* front, *rear;
};

// Function to initialize the queue
void initialise(struct queue* q) {
    q->size = 0;
    q->front = q->rear = NULL;
}

// Function to create a new node with product information
struct node* createnode(struct ProductInfo val) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}

// Function to enqueue a product into the queue
void enque(struct queue* q, struct ProductInfo val) {
    struct node* temp = createnode(val);

    if (!(q->front)) {
        q->front = temp;
        q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }

    q->size++;
    printf("Enqueued:\n");
}

// Function to dequeue a product from the queue
void deque(struct queue* q) {
    if (!(q->front)) {
        printf("Queue underflow\n");
        return;
    }

    struct node* temp = q->front;
    q->front = q->front->next;
    free(temp);
    q->size--;
    printf("Dequeued:\n");
}

// Function to print the products in the queue
void print(struct queue* q) {
    if (!(q->front)) {
        printf("Queue underflow\n");
        return;
    }

    struct node* itr = q->front;

    while (itr != NULL) {
        printf("Product Id: %c, Name: %s, Total Sale: %d, Grade: %c\n",
               itr->data.Product_Id, itr->data.Product_Name,
               itr->data.Total_sale, itr->data.Product_Grade);
        itr = itr->next;
    }

    printf("\n");
}

int main() {
    struct queue q1;
    initialise(&q1);

    // Example products
    struct ProductInfo product1 = {'A', "Product A", 100, 'A'};
    struct ProductInfo product2 = {'B', "Product B", 150, 'B'};
    struct ProductInfo product3 = {'C', "Product C", 200, 'C'};

    // Enqueue products
    enque(&q1, product1);
    enque(&q1, product2);
    enque(&q1, product3);

    // Print the queue
    print(&q1);

    // Dequeue a product
    deque(&q1);

    // Print the updated queue
    print(&q1);

    return 0;
}
