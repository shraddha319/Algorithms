#include<iostream>
#define MAX 10

using namespace std;

class stack
{
private:
	int a[MAX],top;
public:
	stack()
	{
		top=-1;
	}

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
		return a[top];
	}

	void push(int elem)
	{
		if(top==MAX-1)
			cout<<"Stack overflow";
		else a[++top] = elem;
	}

	void pop()
	{
		if(IsEmpty())
			cout<<"Underflow\n";
		else top--;
	}

	void display()
	{
		cout<<"Stack: ";
		for(int i=0;i<=top;i++)
			cout<<a[i]<<" ";
		cout<<"\n";
	}
};

int main()
{
	stack s;
	int n,elem;
	cout<<"enter n:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"enter elem: ";
		cin>>elem;
		s.push(elem);
		s.display();
	}
	cout<<"\nPop\n";
	for(int i=0;i<n;i++)
	{
		s.pop();
		s.display();
	}
	return 0;
}
