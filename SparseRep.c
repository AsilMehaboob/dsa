#include<stdio.h>

int sr[100][3],s[100][3];

void sparse(int s[][3],int c,int r){
    sr[0][0]=r;
    sr[0][1]=c;
    int k=1;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(s[i][j]!=0){
                sr[k][0]=i;
                sr[k][1]=j;
                sr[k][2]=s[i][j];
                k++;
            }
        }
    }
    sr[0][2]=k-1;

    for(int i=0;i<k;i++){
        for(int j=0;j<3;j++){
            printf("%d",sr[i][j]);
        }
        printf("\n");
    }
}

void main(){
    int r,c;
    printf("Enter number of rows:");
    scanf("%d",&r);
    printf("Enter number of cols:");
    scanf("%d",&c);

    printf("Enter Elements");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&s[i][j]);
        }
    }

    sparse(s,c,r);
}