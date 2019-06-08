#include<stack>
#include<stdio.h>
#include<string.h>

using namespace std;

bool isnum(char c)
{
	if(c>='0' && c<='9')
		return true;
	return false;
}

int preced(char c)
{
	if(c=='(')
		return 0;
	if(c=='+'||c=='-')
		return 1;
	if(c=='*'||c=='/')
		return 2;
}

void postfix(char *exp, char *pf)
{
	stack<char> stk;
	int j=0;
	for(int i=0;exp[i]!='\0';i++)
	{
		if(isnum(exp[i]))
			{
				pf[j] = exp[i];
				j++;
			}
		else if(exp[i]=='(')
			stk.push(exp[i]);
		else if(exp[i]==')')
		{
			while(!stk.empty() && stk.top()!='(')
			{
				pf[j] = stk.top();
				j++;
				stk.pop();
			}
			stk.pop();
		}
		else
		{
			while(!stk.empty() && preced(stk.top())>=preced(exp[i]))
			{
				pf[j] = stk.top(); stk.pop();
				j++;
			}
			stk.push(exp[i]);
		}
	}
	while(!stk.empty())
	{
		pf[j] = stk.top();
		stk.pop();
		j++;
	}
	pf[j] = '\0';
}

int main()
{
	char exp[20],pf[20];
	printf("enter infix exp: ");
	scanf("%s",exp);
	postfix(exp,pf);
	printf("\nPostfix exp: %s\n",pf);
	return 0;
}
