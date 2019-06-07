#include<stdio.h>
#include<stdlib.h>
struct tree
{
    int data;
    struct tree *left,*right;
};
int append(struct tree **root,int data)
{
    struct tree *temp,*n;
    temp=*root;
    n=(struct tree*)malloc(sizeof(struct tree));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    if(*root == NULL)
    {
        *root=n;
    }
    else
    {
        while(temp != NULL)
        {
            if(data > temp->data)
            {
                temp=temp->right;
            }
            else if(data < temp->data)
            {
                temp=temp->left;
            }
        }
        temp=n;
        printf("Appended..!!");
    }
}
int display(struct tree *root)
{

   if(root!=NULL)
    {
        display(root->left);
        display(root->right);
        printf("%d",root->data);
    }
}
int main()
{
    int data;
    struct tree *root,*start;
    root=NULL;
    do{
        scanf("%d",&data);
        if(data==-1)
            break;
        append(&root,data);
    }while(1);
    //start = *root;
    display(root);
    return 0;
}