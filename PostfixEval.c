#include<stdio.h>
#define max 100

int stack[max],top=-1,oper1,oper2,result;

void push(int item){
    if(top==max-1){
        printf("Overflow");
    }
    else{
        top++;
        stack[top]=item;
    }
}


int pop(){
    if(top==-1){
        printf("Underflow");
    }
    else{
        int data=stack[top];
        top--;
        return data;
    }
}


int eval(char *expression){
    int i=0,result;
    char symbol=expression[i];
    while(symbol!='\0'){
        if(symbol>='0'&&symbol<='9'){
            int num=symbol-'0';
            push(num);
        }
        else{
            oper2=pop();
            oper1=pop();
            switch (symbol)
            {
            case '+':
                result=oper1+oper2;
                break;
            case '-':
                result=oper1-oper2;
                break;
            case '/':
                result=oper1/oper2;
                break;
            case '*':
                result=oper1*oper2;
                break;
            case '^':
                result=oper1^oper2;
                break;
    
            default:
                break;
            }
            push(result);
        }
        i++;
        symbol=expression[i];
    }
    result=pop();
    return result;
}


void main(){
    char expression[max];
    printf("Enter expression");
    scanf("%s",expression);

    int result=eval(expression);
    printf("%d",result);
}