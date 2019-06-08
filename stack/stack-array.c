#include<stdio.h>
#define MAX 10

int a[MAX],top=-1;

int IsEmpty()
{
	if(top==-1)
		return 1;
	return 0;
}

int Top()
{
	if(IsEmpty())
		return -1;
	else return a[top];
}

void display()
{
	printf("Stack: ");
	for(int i=0;i<=top;i++)
		printf(" %d",a[i]);
	printf("\nTop = %d\n",Top());
}

void push(int elem)
{
	if(top==MAX-1)
		printf("Stack overflow\n");
	else a[++top] = elem;
}

void pop()
{
	if(IsEmpty())
		printf(" Stack underflow!\n");
	else top -= 1;
}


int main()
{
	int n,elem;
	printf("enter n: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("enter elem: ");
		scanf("%d",&elem);
		push(elem);
		display();
	}
	printf("\nPopping elem:\n");
	for(int i=0;i<n;i++)
	{
		pop();
		display();
	}
	return 0;
}
