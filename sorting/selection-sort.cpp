#include<iostream>
#define MAX 50

using namespace std;

void SelectionSort(int *a,int n)
{
	int imin;
	for(int i=0;i<=n-2;i++)
	{
		imin = i;
		for(int j=i+1;j<=n-1;j++)
		{
			if(a[imin]>a[j])
				imin = j;
		}
		int temp = a[imin];
		a[imin] = a[i];
		a[i] = temp;
	}
}

int main()
{
	int a[MAX],n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	SelectionSort(a,n);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	return 0;
}