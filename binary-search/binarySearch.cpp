#include<stdio.h>
#include<iostream>

using namespace std;


int binarySearch(int * a,int n,int x)
{
 int low=0,high=n-1,mid;
 while(low<=high)
 {
  mid = low + (high-low)/2;
  if(a[mid]==x)
   return mid;
  else if(a[mid]>x)
   high = mid-1;
  else low = mid+1;
 }
 return -1;
}

/*
Recursive implementation
int binarySearch(int *a,int low,int high,int x)
{
 if(low>high) return -1;

 int mid = low + (high-low)/2;

 if(a[mid]==x) return mid;
 else if(a[mid]>x) binarySearch(a,low,mid-1,x);
 else binarySearch(a,mid+1,high,x);
}

*/

int main()
{
 int a[] = {2,3,4,5,6}, x;
 int n = sizeof(a)/sizeof(int);
 cout<<"enter an elem\n";
 cin>>x;
 int index = binarySearch(a,0,n-1,x);
 if(index!=-1)
  cout<<"elem found at "<<index;
 else cout<<"elem not found\n";
 return 0;
}
