#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
int append(struct node **headadd,int data)
{
    struct node *temp,*n;
    temp=*headadd;
    n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->link=NULL;
    if(*headadd==NULL)
        *headadd=n;
    else
    {
        while(temp->link!=NULL)
        {
            temp=temp->link;
        }
        temp->link=n;
    }
}
int display(struct node **head)
{
    struct node *start;
    start=*head;
    while(start!=NULL)
    {
        printf(" %d",start->data);
        start=start->link;
    }
}
void dup_delete(struct node **head)
{
    struct node *p, *q, *prev, *temp;
 
    p = q = prev = *head;
    q = q->link;
    while (p != NULL)
    {
       
        while (q != NULL && q->data != p->data)
        {
            prev = q;
            q = q->link;
        }
        if (q == NULL)
        {
            p = p->link;
            if (p != NULL)
            {
                q = p->link;
            }
        }
        else if (q->data == p->data)
        {
            prev->link = q->link;
            temp = q;
            q = q->link;
            free(temp);
        }
    }
}
int main()
{
    struct node *head;
    head=NULL;
    int data;
    do{
        printf("Enter the student roll number:");
        scanf("%d",&data);
        if(data==-1)
            break;
        append(&head,data);
    }while(1);
    dup_delete(&head);
    printf("\nThe assigned roll numbers are:\n");
    display(&head);
    
    return 0;
}