#include<stdio.h>
#define n 5
struct pqueue{
    int data;
    int priority;
}pq[n];

int front=-1,rear=-1;

void enqueue(int data,int priority){
    if(rear==n-1)
    {
        printf("overflow");
    }
    else if(rear==-1)
    {
        front=rear=0;
        pq[rear].priority=priority;
        pq[rear].data=data;
        
    }
    else
    {   
        int i;
        for( i=rear;i>=front&&pq[i].priority<=priority;i--)
        {
            pq[i+1]=pq[i];
        }

        pq[i+1].priority=priority;
        pq[i+1].data=data;
        rear++;
    }
}

void dequeue(){
    if(front==-1)
    {
        printf("Empty");
    }
    else if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        front++;
    }
}


void display(){
    if(front==-1)
    {
        printf("EMpety");
    }
    else
    {
        for(int i=front;i<=rear;i++)
        printf("(%d)%d\n",pq[i].priority,pq[i].data);
    }
}


void main()
{
    int choice,data,prio;

    do
    {
        printf("1.Push 2.Pop 3.Display ");
        scanf("%d",&choice);
        switch(choice)
        {

            case 1: printf("element:"); 
                    scanf("%d",&data); 
                    printf("pri:"); 
                    scanf("%d",&prio); 
                    enqueue(data,prio); 
                    break;
            case 2: dequeue(); 
                    break;
            case 3: display(); 
                    break;
            

        }
    }while(choice!=4);
}