#include<stdio.h>
#include<stack>
#include<vector>

using namespace std;

int largestRectangle(vector<int> h) {
    int area=0;
    int i;
    stack<int> stk;
    for(i=0;i<h.size();i++)
    {
        if(stk.empty() || h[i]>=h[stk.top()])
            stk.push(i);
        else
        {
            int l;
            int a =0;
            l = h[stk.top()];
            stk.pop();
            if(stk.empty())
                a = i*l;
            else a = l*(i-stk.top()-1);
            printf("%d %d\n",l,a);
            if(a>area)
                area = a;
        }
    }
    i = h.size();
    while(!stk.empty())
    {
        int l;
        int a=0;
        l = h[stk.top()];
        stk.pop();
        if(stk.empty())
            a = i*l;
        else a = l*(i-stk.top()-1);
		printf("%d %d\n",l,a);
        if(a>area)
            area = a;
    }
    return area;
}

int main()
{
	vector<int> h= {8979,4570,6436,5083,7780,3269,5400,7579,2324,2116};
	int a = largestRectangle(h);
	printf("%d\n",a);
	return 0;
}
