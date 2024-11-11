#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int power;
    struct node *next;
};

struct node* createnode(int c, int p) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->coeff = c;
    newnode->power = p;
    newnode->next = NULL;
    return newnode;
}

void insert(struct node **head,int c,int p){
    struct node* newnode=createnode(c,p);
    if(*head==NULL||(*head)->power<p){
        newnode->next=*head;
        *head=newnode;
    }

}


void display(struct node* head) {
    struct node *curr = head;
    while (curr != NULL) {
        printf("%dx^%d", curr->coeff, curr->power);
        if (curr->next != NULL)
            printf(" + ");
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    struct node* poly1 = NULL;
    struct node* poly2 = NULL;
    struct node* result = NULL;
    int choice, coeff, power;

    do {
        printf("\nMenu:\n");
        printf("1. Insert term in Polynomial 1\n");
        printf("2. Insert term in Polynomial 2\n");
        printf("3. Add Polynomials\n");
        printf("4. Display Polynomial 1\n");
        printf("5. Display Polynomial 2\n");
        printf("6. Display Resultant Polynomial\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter coefficient and power: ");
                scanf("%d %d", &coeff, &power);
                insert(&poly1, coeff, power);
                break;

            case 2:
                printf("Enter coefficient and power: ");
                scanf("%d %d", &coeff, &power);
                insert(&poly2, coeff, power);
                break;

            case 3:
                result = add(poly1, poly2);
                printf("Polynomials added successfully!\n");
                break;

            case 4:
                printf("Polynomial 1: ");
                display(poly1);
                break;

            case 5:
                printf("Polynomial 2: ");
                display(poly2);
                break;

            case 6:
                printf("Resultant Polynomial: ");
                display(result);
                break;

            case 7:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
