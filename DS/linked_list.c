
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
        while(temp->link != NULL)
        {
            temp=temp->link;
        }
        temp->link=n;
    }
}
int display(struct node **head)
{
    struct node *start;
    if(*head == NULL)
        return 0;
    start=*head;
    while(start!=NULL)
    {
        printf(" %d",start->data);
        start=start->link;
    }
}

int delete_at_beg(struct node **head,int n)
{
    struct node *start;
    if(*head==NULL)
        return 0;
    start =*head;
        *head=start->link;
        start=start->link;
}

int delete_given_element(struct node **head,int n)
{
    struct node *start,*temp;
    start=*head;
    while(start!=NULL)
    {
        if(start->data == n)
            *head=start->link;
        while(start->link->link != '\0')
        {
            if(start->link->data==n)
            {
                temp =start->link;
                start->link=temp->link;
                free(temp);
                return 0;
            }
            start=start->link;
        }
        if(start->link->data==n)
        {
            temp=start->link;
            free(temp);
            start->link =NULL;
        }
    }
}
// SWAP !!!!!!!!!!!!!!!!!
int swap(struct node *a,struct node *b)
{
    int temp=a->data;
    a->data=b->data;
    b->data=temp;
}
//ASCENDING ORDER!!!!!!!!!!!!!!!!!!!!1
int asc(struct node **head)
{
    struct node *start,*temp=NULL;
    int swapped;
    do
    {
        swapped=0;
        start=*head;
        while(start->link!=NULL)
        {
        if(start->data > start->link->data)
        {
            swap(start,start->link);
            swapped=1;
        }
        start=start->link;
        }
        temp=start;
    }while(swapped);
}



int main()
{
    struct node *head;
    head=NULL;
    int data;
    do{
        scanf("%d",&data);
        if(data == -1)
            break;
        append(&head,data);
    }while(1);
    display(&head);
    return 0;
}