#include<stdio.h>

int front = -1;
int rear = -1;
int size = 10;
int queue[10];

void enqueue(int val){
    if((rear+1)%size==front){
        printf("Overflow");
    }
    if(front==-1&&rear==-1){
        front = 0;
        rear = 0;
        queue[rear] = val;
    }
    else{
        rear = (rear + 1) % size;
        queue[rear] = val;

    }
}

int dequeue(){
    int del_ele;
    if(front==-1&&rear==-1){
        printf("Underflow");
        return 0;
    }
    if(front==rear){
        del_ele = queue[front];
        front = -1;
        rear = -1;
        return del_ele;
    }
    else{
        del_ele = queue[front];
        front = (front + 1) % size;
        return del_ele;
    }
}
void display(){
    int i;
    i = front;
    printf("ELEMENTS ARE : \n");
    while(i!=rear){
        printf("%d-->", queue[i]);
        i = (i + 1) % size;
    }
    printf("%d", queue[rear]);
    printf("\n");
}

int main(){
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    display();
    int d=dequeue();
    printf("element deleted is: %d", d);
    enqueue(7);
    display();

    return 0;
}