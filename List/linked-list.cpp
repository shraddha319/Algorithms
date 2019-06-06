#include<iostream>

using namespace std;

typedef struct node
{
	int data;
	node *link;
}node;

int n;

node* Insert(node *head,int elem,int pos)
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

node* Delete(node *head, int pos)
{
	node *prev=head,*temp=head;
	if(pos==1)
		//delete first node
		head = temp->link;
	else
	{	//If there is an (n-1)th node
		for(int i=0;i<pos-2;i++)
			prev = prev->link;
		temp = prev->link;
		prev->link = temp->link;
	}
	free(temp);
	return head;
}

void display(node *temp)
{
	cout<<"List: ";
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
	int elem,pos;
	cout<<"Enter n: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter elem and pos: ";
		cin>>elem>>pos;
		head = Insert(head,elem,pos);
		display(head);
	}
	cout<<"\nDelete:\n";
		for(int i=0;i<n;i++)
	{
		cout<<"Enter pos: ";
		cin>>pos;
		head = Delete(head,pos);
		display(head);
	}
	return 0;
}
