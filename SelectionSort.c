#include<stdio.h>

void selectionsort(int arr[],int n){
    for(int i=0;i<n;i++){
        int min=i;

        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }

        if(min!=i){
            int temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
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

    selectionsort(arr,n);

    printf("Sorted Array:");
    for(int i=0;i<n;i++)
        printf("%d\t",arr[i]);
}