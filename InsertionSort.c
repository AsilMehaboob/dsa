#include<stdio.h>

void insertionsort(int arr[],int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;

        while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }

        arr[j+1]=key;
    }
}

void main(){

    int n,arr[100];
    printf("Enter Size:");
    scanf("%d",&n);
    printf("Enter Array:");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    insertionsort(arr,n);

    printf("Sorted Array:");
    for(int i=0;i<n;i++)
        printf("%d",arr[i]);
}