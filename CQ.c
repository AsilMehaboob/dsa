#include<stdio.h>
#define size 5

int q[size],front=-1,rear=-1;

void enqueue(int item){
    if((rear+1)%size==front){
        printf("Overflow");
    }
    else if(front == -1 && rear ==-1){
        front=rear=0;
        q[rear]=item;
    }
    else{
        rear=(rear+1)%size;
        q[rear]=item;
    }
}

void dequeue(){
    int data;
    if(front==-1){
        printf("Underflow");
    }
    else if(front==rear){
        data=q[front];
        front=rear=-1;
    }
    else{
        data=q[front];
        front=(front+1)%size;
    }
}

void display(){
    for(int i=front;i!=rear;i=(i+1)%size){
        printf("%d",q[i]);
    }
    printf("%d",q[rear]);
}


int main() {
    int choice, item;

    do {
        printf("\nCircular Queue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}