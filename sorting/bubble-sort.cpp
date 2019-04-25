#include<iostream>
#define MAX 50

using namespace std;

void BubbleSort(int *a,int n)
{
 int i,j,flag=0;
 for(i=1;i<=n-1;i++)
 {
  flag = 0;
  for(j=0;j<n-i-1;j++)
  {
   if(a[j]>a[j+1])
   {
    flag = 1;
    int temp = a[j];
    a[j] = a[j+1];
    a[j+1] = temp;
   }
  }
  if(flag==0)
   break;
 }
 cout<<"number of iter (i) = "<<i<<"\n";
}

int main()
{
 int a[MAX],n;
 cin>>n;
 for(int i=0;i<n;i++)
  cin>>a[i];
 BubbleSort(a,n);
 for(int i=0;i<n;i++)
  cout<<a[i]<<" ";
 cout<<"\n";
 return 0;
}
