#include<iostream>
#define MAX 50

using namespace std;

void InsertionSort(int *a,int n)
{
	int i;
	for(i=1;i<=n-1;i++)
	{
		int value = a[i], hole=i;
		while(hole>0 && a[hole-1]>value)
		{
			a[hole] = a[hole-1];
			hole--;
		}
		a[hole] = value;
	}
}

int main()
{
	int a[MAX],n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	InsertionSort(a,n);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	return 0;
}