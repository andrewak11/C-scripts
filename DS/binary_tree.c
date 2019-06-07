#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct BNode 
{
  int data;
  struct BNode *left;
  struct BNode *right;
};

void add_node(struct BNode **root, int value)
{
    struct BNode* new_node;
	new_node = (struct BNode*) malloc(sizeof(struct BNode));
	new_node->data = value;
	new_node->left  = NULL;
	new_node->right = NULL;
    
	if(*root == NULL)
	{
		*root = new_node;
		return;
	}
	
	struct BNode *node = *root;	
	while(1)
	{
		if(node->data > value)
		{
			if(node->left == NULL)
			{
				node->left = new_node;
				return;
			}
			
			node = node->left;
		} 
		else
		{
			if(node->right == NULL)
			{
				node->right = new_node;
				return;
			}
			
			node = node->right;
		}
	}
	
	return;
}

void display_in_order(struct BNode *node)
{
	// Type your code here
  	if(node != NULL)
    {
  	display_in_order(node->left);
  	printf("%d ",node->data);
  	display_in_order(node->right);
    }
}

void display_pre_order(struct BNode *node)
{
	// Type your code here
  	if(node != NULL)
    {
  	printf("%d ",node->data);
  	display_pre_order(node->left);
  	display_pre_order(node->right);
    }
}

void display_post_order(struct BNode *node)
{
	// Type your code
  	if(node != NULL)
    {
  	display_post_order(node->left);
  	display_post_order(node->right);
  	printf("%d ",node->data);
    }
}


int main() 
{
  int n, i, tmp;
  struct BNode *root= NULL;
  
  scanf("%d", &n);
  for(i = 0; i < n; i++)
  {
	  scanf("%d", &tmp);
	  add_node(&root, tmp);
  }
  
  printf("In-Order Traversal: ");
  display_in_order(root);
  printf("\nPre-Order Traversal: ");
  display_pre_order(root);
  printf("\nPost-Order Traversal: ");
  display_post_order(root);
}