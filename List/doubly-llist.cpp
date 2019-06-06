#include<iostream>

using namespace std;

typedef struct node
{
	int data;
	node *prev;
	node *next;
}node;

node *head=NULL;

void display(node *head)
{
	node *temp1, *temp=head;
	if(head==NULL)
	{
		cout<<"empty!\n";
		return;
	}
	cout<<"Forward :";
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp1 = temp;
		temp = temp->next;
	}
	cout<<"\nReverse :";
	while(temp1!=NULL)
	{
		cout<<temp1->data<<" ";
		temp1 = temp1->prev;
	}
	cout<<"\n";
}

node* Insert(node *head, int elem, int pos)
{
	node *temp = (node *)malloc(sizeof(node));
	temp->data = elem;
	temp->prev = NULL;
	temp->next = NULL;
	if(pos==1)
	{
		temp->next = head;
		if(head!=NULL)
			head->prev= temp;
		head = temp;
		return head;
	}
	node *p = head;
	for(int i=0;i<pos-2;i++)
		p = p->next;
	temp->next = p->next;
	temp->prev = p;
	if(p->next!=NULL)
		p->next->prev = temp;
	p->next = temp;
	return head;
}

node* Delete(int pos)
{
	if(head==NULL)
	{
		cout<<"empty!\n";
		return head;
	}
	node *curr=head;
	if(pos==1)
	{
		head = curr->next;
		if(curr->next!=NULL)
			curr->next->prev = NULL;
	}
	else
	{
		node *p=head;
		for(int i=0;i<pos-2;i++)
			p = p->next;
		curr = p->next;
		p->next = curr->next;
		if(curr->next!=NULL)
			curr->next->prev = p;
	}
	free(curr);
	return head;
}

int main()
{
	int n,elem,pos;
	cout<<"enter n: ";
	cin>>n;
	cout<<"\nInsertion\n";
	for(int i=0;i<n;i++)
	{
		cout<<"enter elem and pos: ";
		cin>>elem>>pos;
		head = Insert(head,elem,pos);
		display(head);
	}
	cout<<"\nDeletion:\n";
	for(int i=0;i<n;i++)
	{
		cout<<"enter pos: ";
		cin>>pos;
		head = Delete(pos);
		display(head);
	}
	return 0;
}
