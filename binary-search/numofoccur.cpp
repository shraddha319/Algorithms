#include<iostream>
#include<stdio.h>

using namespace std;

int binarySearch(int *a,int n,int x,bool first)
{
 int low = 0,high=n,result=-1;

 while(low<=high)
 {
  int mid = low + (high-low)/2;
  if(a[mid]==x)
  {
   result = mid;
   if(first)
    high = mid-1;
   else
    low = mid+1;
  }

  else if(a[mid]>x)
   high = mid-1;
  else
   low = mid+1;
 }
 return result;
}

int main()
{
 int a[] = {};
 int n = sizeof(a)/sizeof(a[0]), x;
 cout<<"enter element\n";
 cin>>x;
 int first,last;
 first = binarySearch(a,n,x,1);
 if(first==-1)
  cout<<"element not present\n";
 else
 {
  last = binarySearch(a,n,x,0);
  cout<<"count = "<<(last-first+1);
 }
 return 0;
}
