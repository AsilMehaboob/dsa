#include<stdio.h>
#include<stdlib.h>

struct node{
    int key;
    struct node *left;
    struct node *right;
};

struct node *root=NULL;

struct node* create(int data){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));

    newnode->key=data;
    newnode->left=newnode->right=NULL;
    if(root==NULL)
        root=newnode;

    return newnode;
}

struct node* findmin(struct node *root){
    struct node *temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

struct node* search(struct node *root,int item){
    if(root->key==item){
        printf("Node Exists");
        return root;
    }
    else if(item<root->key)
        return search(root->left,item);
    else
        return search(root->right,item);
}

struct node* insertion(struct node* root,int item){
    if(root==NULL)
        return create(item);
    else if(item<root->key){
        root->left=insertion(root->left,item);
    }
    else 
        root->right=insertion(root->right,item);

    return root;
}

struct node* delete(struct node* root,int item){
    if(root==NULL){
        return root;
    }
    else if(item<root->key){
        root->left=delete(root->left,item);
    }
    else if(item>root->key){
        root->right=delete(root->right,item);
    }
    else{
        if(root->left==NULL&&root->right==NULL){
            free(root);
            root=NULL;
            return root;
        }
        else if(root->left==NULL){
            struct node* temp=root;
            root=root->right;
            free(temp);
            return root;
        }
        else if(root->right==NULL){
            struct node* temp=root;
            root=root->left;
            free(temp);
            return root;
        }
        else{
            struct node* temp=findmin(root->right);
            root->key=temp->key;
            root->right=delete(root->right,temp->key);
            return root;
        }
    }
}


void preorder(struct node *root){
    if(root!=NULL){
        printf("%d",root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root){
    if(root!=NULL){

        postorder(root->left);
        postorder(root->right);
        printf("%d",root->key);
    }
}

void inorder(struct node *root){
    if(root!=NULL){

        inorder(root->left);
        printf("%d",root->key);
        inorder(root->right);
    }
}


int main() {
    int choice, item;

    do {
        printf("\n--- Binary Tree Menu ---\n");
        printf("1. Insert a Node\n");
        printf("2. Delete a Node\n");
        printf("3. Search a Node\n");
        printf("4. Preorder Traversal\n");
        printf("5. Inorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &item);
                root = insertion(root, item);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &item);
                root = delete(root, item);
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &item);
                search(root, item);
                break;

            case 4:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 5:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 6:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 7:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}