#include<iostream>
#include<stack>
#include<stdio.h>

using namespace std;

typedef struct node
{
	int data;
	node* next;
}node;

void display(node *temp)
{
	printf("List: ");
	while(temp!=NULL)
	{
		printf(" %d",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

node* Insert(node *head,int elem)
{
	node *temp = (node*)malloc(sizeof(node));
	temp->data = elem;
	temp->next = head;
	head = temp;
	return head;
}

node* Reverse(node *temp)
{
	stack<node*> stk;
	while(temp->next!=NULL)
	{
		stk.push(temp);
		temp = temp->next;
	}
	node *head = temp;
	while(!stk.empty())
	{
		temp->next = stk.top();
		stk.pop();
		temp = temp->next;
	}
	temp->next = NULL;
	return head;
}

int main()
{
	node *head = NULL;
	int n,elem;
	printf("enter n: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("enter elem: ");
		scanf("%d",&elem);
		head = Insert(head,elem);
		display(head);
	}
	printf("\nReversed:\n");
	head = Reverse(head);
	display(head);
	return 0;
}
