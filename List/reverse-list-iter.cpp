#include<iostream>

using namespace std;

typedef struct node
{
	int data;
	node *link;
}node;

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



node* Insert(node *head, int elem, int pos)
{
	node* temp = (node *)malloc(sizeof(node));
	temp->data = elem;
	node *prev = head;
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

node* Reverse(node *head)
{
	node *prev=NULL ,*temp=head, *next=head->link;
	while(temp!=NULL)
	{
		next = temp->link;
		temp->link = prev;
		prev = temp;
		temp = next;
	}
	head = prev;
	return head;
}

int main()
{
	node *head = NULL;
	int n;
	cout<<"Enter n: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int elem,pos;
		cout<<"enter elem and pos: ";
		cin>>elem>>pos;
		head = Insert(head,elem,pos);
		display(head);
	}
	node *rhead = Reverse(head);
	display(rhead);
	return 0;
}
