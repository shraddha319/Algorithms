#include<iostream>
#define MAX 5
using namespace std;

int arr[MAX],top=-1;

void display()
{
	cout<<"List :";
	for(int i=0;i<=top;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";
}

void insert_elem(int pos, int elem)
{
	if(top==MAX-1)
		cout<<"array is full!\n";
	else{
		for(int i=top;i>=pos;i--)
			arr[i+1] = arr[i];
		arr[pos] = elem;
		top++;
	}
}

void remove_elem(int pos)
{
	if(top==-1)
	{
		cout<<"empty!\n";
		return;
	}
	for(int i=pos;i<=top;i++)
		arr[i] = arr[i+1];
	top--;
}

int retrieve(int pos)
{
	if(pos>top)
		{
			cout<<"Not present!\n";
			return -1;
		}
	else
		return *(arr+pos);
}

void state()
{
	if(top==-1)
		cout<<"empty!\n";
	else
	{
		if(top==MAX-1)
			cout<<"Array full!\n";
		display();
	}
}

int main()
{
	int choice;
	cout<<"menu: 1.insert 2.delete 3.retrieve 4.empty/full 5.exit\n";
	while(1)
	{
		int elem,pos;
		cout<<"\nenter choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1: cout<<"enter position and elem: ";
					cin>>pos>>elem;
					insert_elem(pos,elem);
					display();
					break;
			case 2: cout<<"enter position: ";
					cin>>pos;
					remove_elem(pos);
					display();
					break;
			case 3: cout<<"enter position: ";
					cin>>pos;
					cout<<"Elem: "<<retrieve(pos);
					break;
			case 4: state();
					break;
			case 5: exit(0);
		}
	}

	return 0;
}
