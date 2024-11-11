#include<stdio.h>
#include<stdlib.h>
#define size 10

struct node{
    int data;
    struct node* next;
};

struct hash{
    struct node* chain[size];
    int linearp[size];
};


struct node* createnode(int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

struct hash* createhashtable(){
    struct hash* hashtable=(struct hash*)malloc(sizeof(struct hash));
    for(int i=0;i<size;i++){
        hashtable->chain[i]=NULL;
        hashtable->linearp[i]=-1;
    }
    return hashtable;
}

void insertchaining(struct hash* hashtable,int data){
    int index=data%size;
    struct node* newnode=createnode(data);
    if(hashtable->chain[index]=NULL)
        hashtable->chain[index]=newnode;
    else{
        struct node* temp=hashtable->chaining[index];
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
    }
}

void insertlinearprob(struct hash* hashtable,int data){
    int index=data%size;
    while(hashtable->linearp!=-1){
        index=(index+1)%size;
    hashtable->linearp[index]=data;
    }
}

void displaychain(struct hash* hashtable){
    for(int i=0<size;i++){
        printf("Index %d(Chaining)",i)
        struct node* current=hashtable->chain[i];
        while(current!=NULL){
            printf("%d->",current->data)
            current=current->next;
        }
        printf("NULL")
    }
}

int main() {
 struct hash *hashtable = createhashtable();
 int choice, key;
 do {
 printf("\nMenu:\n");
 printf("1. Insert into Chaining Method\n");
 printf("2. Insert into Linear Probing Method\n");
 printf("3. Display Chaining Method\n");
 printf("4. Display Linear Probing Method\n");
 printf("5. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Enter key to insert using Chaining Method: ");
 scanf("%d", &key);
 insertchaining(hashtable, key);
 break;
 case 2:
 printf("Enter key to insert using Linear Probing Method: ");
 scanf("%d", &key);
 insertlinearprob(hashtable, key);
 break;
 case 3:
 printf("Hash Table using Chaining Method:\n");
 displaychain(hashtable);
 break;
 case 4:
 printf("Hash Table using Linear Probing Method:\n");
 displaylinearprob(hashtable);
 break;
 case 5:
 printf("Exiting the program.\n");
 break;
 default:
 printf("Invalid choice. Please enter a valid option.\n");
 }
 } while (choice != 5);
 return 0;
}