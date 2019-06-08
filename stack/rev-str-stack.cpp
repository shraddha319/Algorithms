#include<stdio.h>
#include<stack>
#include<string.h>

using namespace std;

void ReverseString(char *s,int n)
{
	stack<char> stk;
	for(int i=0;s[i]!='\0';i++)
		stk.push(s[i]);
	for(int i=0;i<n;i++)
	{
		s[i] = stk.top();
		stk.pop();
	}
}

int main()
{
	char s[10];
	printf("enter string: ");
	scanf("%s",s);
	ReverseString(s,strlen(s));
	printf("%s",s);
	return 0;
}
