#include<stdio.h>

void bubblesort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}



void main(){

    int n,arr[100];
    printf("Enter Size:");
    scanf("%d",&n);
    printf("Enter Array:");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    bubblesort(arr,n);

    printf("Sorted Array:");
    for(int i=0;i<n;i++)
        printf("%d",arr[i]);
}