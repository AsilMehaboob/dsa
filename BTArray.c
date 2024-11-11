#include<stdio.h>
#define max 100

int tree[max];

void initialise(){
    for(int i=0;i<max;i++)
        tree[i]=-1;
}

void addnode(int index){
    int val,ch;
    if(index>max){
        printf("Out of Bounds");
    }   


    printf("Enter Data");
    scanf("%d",&val);

    tree[index]=val;
    

    printf("Do you want to enter left node?:(1/0)");
    scanf("%d",&ch);

    if(ch==1)
        addnode(2*index+1);
    
    printf("Do you want to enter right node?:(1/0)");
    scanf("%d",&ch);

    if(ch==1)
        addnode(2*index+2);
}


void preorder(int index){

    if(index>=max||tree[index]==-1)
        return;
    printf("%d",tree[index]);
    preorder(2*index+1);
    preorder(2*index+2);
}

void postorder(int index){
    if(index>=max||tree[index]==-1)
        return;

    postorder(2*index+1);
    postorder(2*index+2);
    printf("%d",tree[index]);
}


void inorder(int index){
    if(index>=max||tree[index]==-1)
        return;
    
    inorder(2*index+1);
    printf("%d",tree[index]);
    inorder(2*index+2);

}





void main(){
    int choice,index;

    initialise();

    do{
        printf("\n--- Binary Tree Menu ---\n");
        printf("1. Add Node\n");
        printf("2. Preorder Traversal\n");
        printf("3. Inorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);


        switch (choice)
        {
        case 1:
            
            addnode(0);
            break;
        
        case 2:
            printf("Preorder Traversal");
            preorder(0);
            break;

        case 3:
                printf("Inorder Traversal: ");
                inorder(0);
                printf("\n");
                break;

            case 4:
                printf("Postorder Traversal: ");
                postorder(0);
                printf("\n");
                break;

            case 5:
                printf("Exiting program.\n");
                break;
        default:
            break;
        }
    }while(choice!=5);
}