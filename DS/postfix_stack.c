#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct postfix
{
    int *a;
    char *c;
    int sum;
    int top;
}s;
void initpostfix()
{
    s.top=-1;
    s.sum=0;
}
void setexpr()
{
    printf("Enter postfix expression to be evaluated:\n");
    scanf("%s",s.c);
}
int push(int a)
{
    if(s.top == 50)
    {
        printf("Stack is full");
    }
    else
    {
        s.top++;
        *(s.a+s.top)=a;
    }
}
int pop()
{
    if(s.top == -1)
        printf("Stack is empty");
    else
    {
        int r = *(s.a+s.top);
        s.top--;
        return r;
    }
}
void calculate()
{
    int i,x,y;
    for(i=0;*(s.c+i)!='\0';i++)
    {
        if(*(s.c+i)=='+')
        {
            x =pop();
            y = pop();
            s.sum = x+y;
            push(s.sum);
        }
        else if(*(s.c+i)=='-')
        {
            x =pop();
            y = pop();
            s.sum = x-y;
            push(s.sum);
        }
        else if(*(s.c+i)=='*')
        {
            x =pop();
            y = pop();
            s.sum = x*y;
            push(s.sum);
        }
        else if(*(s.c+i)=='/')
        {
            x =pop();
            y = pop();
            s.sum = x/y;
            push(s.sum);
        }
        else
            push(*(s.c+i)-'0');
    }
}
void show()
{
    printf("Result is: %d",*(s.a+s.top));
    
}
int main()
{
    s.a=(int*)malloc(50*sizeof(int));
    s.c=(char*)malloc(50*sizeof(char));
    initpostfix();
    setexpr();
    calculate();
    show();
    return 0;
}