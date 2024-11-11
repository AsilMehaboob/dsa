#include<stdio.h>

struct poly{
    int coeff;
    int exp;
};

struct poly p1[10],p2[10],p3[20];

int readpoly(struct poly p[]){
    int t;
    printf("Enter Numbers of terms in polynomial:");
    scanf("%d",&t);

    for(int i=0;i<t;i++){
        printf("Enter the Coefficient:");
        scanf("%d",&p[i].coeff);
        printf("Enter the Exponent:");
        scanf("%d",&p[i].exp);
    }

    return t;
}


void display(struct poly p[],int t){
    for(int i=0;i<t-1;i++){
        printf("%dx^%d+",p[i].coeff,p[i].exp);
    }
    printf("%dx^%d",p[t-1].coeff,p[t-1].exp);
}


int add(struct poly p1[],struct poly p2[],int t1,int t2){
    int i=0,j=0,k=0;
    while(i<t1&&j<t2){
        if(p1[i].exp==p2[j].exp){
            p3[k].exp=p1[i].exp;
            p3[k].coeff=p1[i].coeff+p2[j].coeff;
            i++;
            j++;
            k++;
        }
        else if(p1[i].exp>p2[j].exp){
            p3[k].exp=p1[i].exp;
            p3[k].coeff=p1[i].coeff;
            i++;
            k++;
        }
        else{
            p3[k].exp=p2[j].exp;
            p3[k].coeff=p2[j].coeff;
            j++;
            k++;
        }
    }

    while(i<t1){
        p3[k].exp=p1[i].exp;
        p3[k].coeff=p1[i].coeff;
        i++;
        k++;
    }

    while(j<t2){
        p3[k].exp=p2[j].exp;
        p3[k].coeff=p2[j].coeff;
        j++;
        k++;
    }


    return k;
}


void main(){

    int t1,t2,t3;
    
    printf("Poly 1:\n");
    t1=readpoly(p1);
    display(p1,t1);
    printf("Poly 2:\n");
    t2=readpoly(p2);
    display(p2,t2);
    
    printf("Add:\n");
    t3=add(p1,p2,t1,t2);
    display(p3,t3);
    
}