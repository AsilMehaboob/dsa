#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* head=NULL;
struct node* tail=NULL;

struct node* create(int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;

    return newnode;
}

void insertfront(int data){
    struct node* newnode=create(data);
    if(head==NULL){
        head=tail=newnode;
    }
    else{
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
}

void insertend(int data){
    struct node* newnode=create(data);
    if(head==NULL){
        head=tail=newnode;
    }
    else{
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
}

void insertspecific(int data,int pos){
    struct node* newnode=create(data);
    struct node* temp=head;
    if(head==NULL){
        head=tail=newnode;
    }
    else{
        if(pos==0)
            insertfront(data);
        else{
            for(int i=0;i<pos-1;i++)
                temp=temp->next;
            
            newnode->next=temp->next;
            newnode->prev=temp;
            temp->next=newnode;
            newnode->next->prev=newnode;
        }
    }
}


void deletefront(){
    if(head==tail)
        head=tail=NULL;
    else{
        struct node* temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
    }
}

void deleteend(){
    if(head==tail)
        head=tail=NULL;
    else{
        struct node* temp=tail;
        tail=tail->prev;
        tail->next=NULL;
        free(temp);
}
}


void deletespecific(int pos){
    struct node* temp=head;
    for(int i=0;i<pos-1;i++)
        temp=temp->next;
    temp->next->prev=temp->prev;
    temp->prev->next=temp->next;
}


void display() {
    struct node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, data, pos;
    while (1) {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Insert at specific position\n");
        printf("4. Delete from front\n");
        printf("5. Delete from end\n");
        printf("6. Delete from specific position\n");
        printf("7. Display list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                insertfront(data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertend(data);1

                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at (starting from 0): ");
                scanf("%d", &pos);
                insertspecific(data, pos);
                break;
            case 4:
                deletefront();
                break;
            case 5:
                deleteend();
                break;
            case 6:
                printf("Enter position to delete from (starting from 0): ");
                scanf("%d", &pos);
                deletespecific(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}