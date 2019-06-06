#include<iostream>

using namespace std;

typedef struct node
{
	int data;
	node *link;
}node;


node* Insert(node *head,int elem, int pos)
{
	node *prev=head;
	node *temp = (node *)malloc(sizeof(node));
	temp->data = elem;
	if(pos==1)
	{
		temp->link = head;
		head = temp;
		return head;
	}
	for(int i=0;i<pos-2;i++)
		prev = prev->link;
	temp->link = prev->link;
	prev->link = temp;
	return head;
}

node* Reverse(node* temp)
{
	node *head = NULL;
	if(temp->link==NULL)
	{
		head = temp;
		return head;
	}
	head = Reverse(temp->link);
	temp->link->link = temp;
	temp->link = NULL;
	return head;
}

void display(node *temp)
{
	cout<<"List :";
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->link;
	}
	cout<<"\n";
}

int main()
{
	node *head=NULL;
	int n,elem,pos;
	cout<<"enter n: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"enter elem and pos: ";
		cin>>elem>>pos;
		head = Insert(head,elem,pos);
		display(head);
	}
	cout<<"\nReversed list:\n";
	node* rhead = Reverse(head);
	display(rhead);
	return 0;
}
