#include<stdio.h>
#include<string.h>
#define size 20

typedef struct customer{
    char name[50];
} cus;

int front=-1, rear=-1;
cus queue[size];

void enqueue(cus name){
    if(rear==size-1){
        printf("Queue is full, No more customer can be added\n");
    }
    else if(front==-1&&rear==-1){
        front = rear = 0;
        queue[rear] = name;
    }
    else{
        rear++;
        queue[rear] = name;
    }

}

void dequeue(){
    if(front==-1&&rear==-1){
        printf("queue is empty, No customers to serve\n");
    }
    else if(front==rear){
        front = rear = -1;
    }
    else{
        printf("%s is remove\n", queue[front].name);
        front++;
    }

}

void peek(){
    if(front==-1&&rear==-1){
        printf("queue is empty,No customer in line");
    }
    else{
        printf("%s is at the front of the queue\n", queue[front].name);
    }
}

void display(){
    if(front==-1&&rear==-1){
        printf("queue is empty, No customers in line");
    }
    else{
        printf("Current customers in the queue:\n");
        for (int i = front; i <= rear;i++){
            printf("%s  ", queue[i].name);
        }
        printf("\n");
    }
}

int main(){
   
    int choice;
    cus customer_name;

    while (1) {
        printf("\nCustomer Service Queue Management System\n");
        printf("1. Add Customer to Queue (Enqueue)\n");
        printf("2. Serve Customer (Dequeue)\n");
        printf("3. View Front Customer (Peek)\n");
        printf("4. Display All Customers in Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter customer name: ");
            scanf("%s", &customer_name.name);
            enqueue(customer_name);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting the system.\n");
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}