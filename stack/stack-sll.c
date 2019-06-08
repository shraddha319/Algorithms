#include<stdio.h>

typedef struct node
{
	int data;
	node *next;
}node;

int IsEmpty(node *top)
{
	if(top==NULL)
		return 1;
	return 0;
}

int Top(node *top)
{
	if(IsEmpty())
		return -1;
	return top->data;
}

node* push(node *top, int elem)
{
	node *temp = (node*)malloc(sizeof(node));
	temp->data = elem;
	temp->next = top;
	top = temp;
	return top;
}

node* pop(node *top)
{
	if(IsEmpty())
		return NULL;
	node *temp = top;
	top = temp->next;
	free(temp);
	return top;
}

int main()
{
	int n,elem;
	node *top = NULL;
	printf("enter n: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("enter elem: ");
		scanf("%d",&elem);
		top = push(top,elem);
		display(top);
	}
	printf("\nPop\n");
	for(int i=0;i<n;i++)
	{
		top = pop(top);
		display(top);
	}
	return 0;
}
