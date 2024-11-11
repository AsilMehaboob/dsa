#include<stdio.h>

int partition(int arr[],int first,int last){
    int pivot=arr[last];
    int i=first-1;

    for(int j=first;j<last;j++){
        if(arr[j]<=pivot){
            i++;
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }

    int temp=arr[i+1];
    arr[i+1]=arr[last];
    arr[last]=temp;

    return i+1;
}


void quicksort(int arr[],int first,int last){
    if(first<last){
    int index=partition(arr,first,last);
    quicksort(arr,first,index-1);
    quicksort(arr,index+1,last);
}
}

void main(){
    int n;
    printf("Enter total");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    
    quicksort(arr,0,n-1);

    for(int i=0;i<n;i++)
        printf("%d",arr[i]);

}