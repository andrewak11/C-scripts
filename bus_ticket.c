#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int avail_tickets = 30;
struct node
{
    int tics;
    char name[20];
    struct node *next;
}*start;

void book_tickets()
{
    struct node *temp,*q;
    temp = malloc(sizeof(start));
    printf("enter the name");
    scanf("%s",temp->name);
    printf("enter the no. of tickets");
    scanf("%d",temp->tics);
    if(start == NULL)
    {
        start = temp;
    }
    else
    {
        q = start;
        while(q->next!=NULL)
        {
            q = q->next;
        }
        q->next = temp;
    }
}

void del_tickets()
{
    struct node *temp,*q;
    char n[20];
    temp = malloc(sizeof(start));
    printf("enter name");
    scanf("%s",&n);
    if(start->name == n)
    {
        temp = start;
        start = start->next;
        free(temp);
        return;
    }
    q = start;
    while(q->next->next != NULL)
    {
        if(q->next->name == n)
        {
            temp = q->next;
            q->next = temp->next;
            free(temp);
            return;
        }
        q = q->next;
    }
    if(q->next->name == n)
    {
        temp = q->next;
        free(temp);
        q->next = NULL;
        return;
    }
    printf("%s name not found",n);
}


void main()
{
    int ch=0;
    
    while(1)
    {
        printf("*********************** BUS BOOKING ************************\n");
        printf("available tickets : %d\n",avail_tickets);
        printf("select process:\n1- Book tickets\n2- Delete tickets\n3- Search tickets\n4- exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                book_tickets();
                break;
            case 2:
                del_tickets();
                break;
            // case 3:
            //     search_tickets();
            //     break;
            case 4:
                exit(0);
            default:
                printf("Invalid input..!!!");
        }
    }
}


