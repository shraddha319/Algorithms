#include<stdio.h>
#include<iostream>

using namespace std;

int RotbinarySearch(int *a ,int n)
{
 int low=0, high = n-1;
 while(low<=high)
 {
  if(a[low]<=a[high])
   return low;

  int mid = (low+high)/2;
  int prev=(mid-1+n)%n, next=(mid+1)%n;

  if(a[mid]<=a[prev] && a[mid]<=a[next])
   return mid;

  else if(a[mid]<=a[high])
   high = mid-1;
  else low = mid+1;
 }
}

int main()
{
 int a[] = {2,5,6,8,11,12,15,18}, n =sizeof(a)/sizeof(a[0]);
 int rot = RotbinarySearch(a,n);
 cout<<rot;
 return 0;
}
