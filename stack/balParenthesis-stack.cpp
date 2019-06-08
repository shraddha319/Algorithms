#include<stdio.h>
#include<stack>

using namespace std;

bool bal(char *exp)
{
	stack<char> stk;
	int flag=0;
	for(int i=0;exp[i]!='\0';i++)
	{
		if(exp[i]=='{'|| exp[i]=='['||exp[i]=='(')
				stk.push(exp[i]);
		else
		{
			flag = 0;
			switch(exp[i])
			{
				case '}': if(!stk.empty() && stk.top()=='{') stk.pop();
						  else flag=1;
						  break;
				case ']': if(!stk.empty() && stk.top()=='[') stk.pop();
						  else flag=1;
						  break;
				case ')': if(!stk.empty() && stk.top()=='(') stk.pop();
						  else flag=1;
						  break;
				default: continue;
			}

			if(flag==1)
				return false;
		}
	}
	if(!stk.empty())
		return false;
	return true;
}

int main()
{
	char exp[50];
	printf("enter exp: ");
	scanf("%s",exp);
	if(bal(exp))
		printf("exp is balanced\n");
	else printf("exp not balanced\n");
	return 0;
}
