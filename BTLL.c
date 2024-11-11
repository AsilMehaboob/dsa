#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

struct node* create(int data) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->key = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}


struct node* search(struct node *root, int item) {
    if (root == NULL || root->key == item) {
        if (root != NULL)
            printf("Node exists\n");
        else
            printf("Node not found\n");
        return root;
    }
    else if (item < root->key)
        return search(root->left, item);
    else
        return search(root->right, item);
}


struct node* findmin(struct node* root) {
    struct node* temp = root;
    while (temp->left != NULL)
        temp = temp->left;
    return temp;
}

struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        return create(data);
    }
    else if (data < root->key) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }
    return root;
}

struct node* delete(struct node *root, int data) {
    if (root == NULL) {
        printf("Node not found\n");
        return root;
    }
    else if (data < root->key) {
        root->left = delete(root->left, data);
    }
    else if (data > root->key) {
        root->right = delete(root->right, data);
    }
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct node* temp = findmin(root->right);
        root->key = temp->key;
        root->right = delete(root->right, temp->key);
    }
    return root;
}

void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main() {
    int choice, data;

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
                scanf("%d", &data);
                root = insert(root, data);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                root = delete(root, data);
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &data);
                search(root, data);
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
