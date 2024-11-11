#include<stdio.h>
#include<ctype.h>
#define max 100

char stack[max];
int top=-1;

void push(char item){
    if(top==max-1)
        printf("Overflow");
    else{
        top++;
        stack[top]=item;
    }
}

char pop(){
    if(top==-1)
        printf("Underflow");
    else{
        char data=stack[top];
        top--;
        return data;
    }
}

int precedence(char op){
    switch (op)
    {
    case '^':
        return 3;
        break;
    case '*': case '/': return 2;
    case '+': case '-': return 1;
    
    default:
        return 0;
        break;
    }
}


int isoperator(char ch){
    return ch=='+'||ch=='-'||ch=='/'||ch=='*'||ch=='^';
}

void eval(char *infix,char *postfix){
    int i=0,j=0;
    char temp,ch;

    while((ch=infix[i++])!='\0'){
        if(ch=='(')
            push(ch);
        else if(ch==')'){
            while((temp=pop())!='(')
                postfix[j++]=temp; 
        }
        else if(isoperator(ch)){

            while(top!=-1&&precedence(stack[top])>=precedence(ch)){
                postfix[j++]=pop();
            }
            push(ch);
        }
        else    
            postfix[j++]=ch;
    }
    while(top!=-1){
        postfix[j++]=pop();
    }
    postfix[j]='\0';

}

int main() {
    char infix[max], postfix[max];
    
    printf("Enter infix expression: ");
    scanf("%s", infix);
    
    eval(infix, postfix);
    
    printf("Postfix expression: %s\n", postfix);
    return 0;
}