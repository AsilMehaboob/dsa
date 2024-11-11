#include<stdio.h>

int binarysearch(int arr[],int n,int target){
    int left=0,right=n-1,mid;
    int flag;
    while(left<right){
        mid=(left+right)/2;

        if(arr[mid]==target){
            return mid;
            flag=1;
        }
        else if(target<arr[mid]){
            right=mid-1;
        }
        else
            left=mid+1;
    }
    return -1;
}

void main(){
    int arr[]={1,2,3,4,5,6,7,8,9};
    int target;
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("Enter target:");
    scanf("%d",&target);
    int val=binarysearch(arr,n,target);
    if(val!=-1)
        printf("Element found at %d",val);
    else
        printf("not");
}