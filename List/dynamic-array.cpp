#include<iostream>

using namespace std;

int *p=NULL,n=5,top=-1;

int display()
{
	cout<<"List: ";
	for(int i=0;i<=top;i++)
		cout<<*(p+i)<<" ";
	cout<<"\n";
}

void insert_elem(int pos,int elem)
{
	if(top==n-1)
	{
		n = 2*n;
		p = (int *)realloc(p,n*sizeof(int));
	}
	for(int i=top;i>=pos;i--)
		p[i+1] = p[i];
	p[pos] = elem;
	top++;
}

void remove_elem(int pos)
{
	if(top==-1)
		cout<<"empty!\n";
	else
	{
		for(int i=pos;i<=top;i++)
			p[i] = p[i+1];
		top--;
	}

}

int retrieve(int pos)
{
	if(pos>top || pos<0)
	{
		cout<<"Invalid index!\n";
		return -1;
	}
	return p[pos];
}

void num()
{
	if(top==-1)
		cout<<"list empty!\n";
	else
	{
		cout<<"count ="<<(top+1)<<"\n";
		display();
	}
}

int main()
{
	p = (int *)malloc(n*sizeof(int));
	int choice;
	cout<<"menu: 1.insert 2.delete 3.retrieve 4.count 5.exit\n";
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
			case 4: num();
					break;
			case 5: exit(0);
		}
	}

	return 0;
}

