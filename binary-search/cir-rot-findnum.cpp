#include<iostream>

using namespace std;

int findnum(int *a,int n,int x)
{
 int low=0,high=n-1;
 while(low<=high)
 {
  int mid = (low+high)/2;

  if(a[mid]==x) return mid;

  else if(a[mid]<=a[high])
  {
   if(x>=a[mid] && x<=a[high])
    low = mid+1;
   else high = mid-1;
  }

  else
  {
   if(x>=a[low]&&x<=a[mid])
    high = mid-1;
   else low=mid+1;
  }
 }
 return -1;
}

int main()
{
 int a[] = {11,12,15,18,2,5,6,8}, n =sizeof(a)/sizeof(a[0]), x;
 cout<<"enter elem\n";
 cin>>x;
 cout<<findnum(a,n,x);
 return 0;
}
