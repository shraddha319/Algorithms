#include<stdio.h>
#include<iostream>

using namespace std;

typedef struct node
{
    int data;
    node *next;
}node;

node *f=NULL, *r=NULL;

void enqueue(int elem)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->data = elem;
    temp->next = NULL;
    if(f==NULL && r==NULL)
        f = r = temp;
    else
    {
        r->next = temp;
        r = temp;
    }
}

void dequeue()
{
    node *temp = f;
    if(f==NULL && r==NULL)
    {
        printf("Empty!\n");
        return;
    }
    if(f==r)
        f=r=NULL;
    else
        f = temp->next;
    free(temp);
}

void display()
{
    printf("Queue: ");
    node *temp = f;
    while(temp!=NULL)
    {
        printf(" %d",temp->data);
        temp = temp->next;
    }
    printf("\n");
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
        enqueue(elem);
        display();
    }
    printf("\nDequeue\n");
    for(int i=0;i<n;i++)
    {
        dequeue();
        display();
    }
    return 0;
}
