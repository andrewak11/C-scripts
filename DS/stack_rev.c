#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void append(struct node **headadd,int data)
{
    struct node *temp,*n;
    temp=*headadd;
    n=(struct node*)malloc(sizeof(struct node));
    n->data =data;
    n->link=NULL;
    if(*headadd == NULL)
    {
        *headadd =n;
    }
    else
    {
            n->link=*headadd;
            *headadd=n;
    }
}
void stack_reverse(struct node **head, struct node **head_next)
{
    struct node *temp;
 
    if (*head_next != NULL)
    {
         temp = (*head_next)->link;
        (*head_next)->link = (*head);
        *head = *head_next;
        *head_next = temp;
        stack_reverse(head, head_next);
    }
}
int delete(struct node **head,int n)
{
    struct node *start;
    if(*head==NULL)
        return 0;
    start =*head;
        *head=start->link;
        start=start->link;
}
int display(struct node **head)
{
    struct node *start;
    //start=(struct node*)malloc(sizeof(struct node));
    if(*head == NULL)
        return 0;
    start=*head;
    while(start!=NULL)
    {
        printf(" %d",start->data);
        start=start->link;
    }
}
int main()
{
    
    //write code here...
    struct node *head;
    head=NULL;
    int data,a=0;
    do{
        scanf("%d",&data);
        if(data==-1)
            break;
        append(&head,data);
      }while(1);
    display(&head);
    printf("\nAfter reverse recursion..\n");
    stack_reverse(&head,&head->link);
    display(&head);
    return 0;
}