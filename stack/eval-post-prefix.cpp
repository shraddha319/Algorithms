#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stack>

using namespace std;

bool isnum(char c)
{
	if(c>='0' && c<='9')
		return true;
	return false;
}

bool isoperator(char c)
{
	if(c=='+' ||c=='-'||c=='*'||c=='/'||c=='^')
		return true;
	return false;
}

int eval(int op1, int op2, char c)
{
	switch(c)
	{
		case '+':return op1+op2;
		case '-':return op1-op2;
		case '*':return op1*op2;
		case '/':return op1/op2;
		case '^':return pow(op1,op2);
	}
}

int prefix(char *exp)
{
	stack<int> stk;
	int op1,op2;
	for(int i=strlen(exp);i>=0;i--)
	{
		if(exp[i]==',')
			continue;
		if(isoperator(exp[i]))
		{
			op2 = stk.top(); stk.pop();
			op1 = stk.top(); stk.pop();
			stk.push(eval(op1,op2,exp[i]));
		}
		else if(isnum(exp[i]))
		{
			char num[10];
			int j=0,n=0;
			while(exp[i]!=',' && i>=0)
			{
				num[j] = exp[i];
				j++; i--;
			}
			num[j] = '\0';
			for(j=0;j<strlen(num);j++)
				n += (num[j]-'0')*pow(10,j);
			stk.push(n);
		}
	}
	return stk.top();
}

int postfix(char *exp)
{
	stack<int> stk;
	int op1,op2;
	for(int i=0;exp[i]!='\0';i++)
	{
		if(exp[i]==',')
			continue;
		if(isoperator(exp[i]))
		{
			op2 = stk.top(); stk.pop();
			op1 = stk.top(); stk.pop();
			stk.push(eval(op1,op2,exp[i]));
		}
		else if(isnum(exp[i]))
		{
			char num[10];
			int j=0,n=0;
			while(exp[i]!=',' && exp[i]!='\0')
			{
				num[j] = exp[i];
				j++; i++;
			}
			num[j] = '\0';
			for(j=0;j<strlen(num);j++)
				n += (num[j]-'0')*pow(10,strlen(num)-j-1);
			stk.push(n);
		}
	}
	return stk.top();
}

int main()
{
	char exp[50];
	printf("enter postfix exp: ");
	scanf("%s",exp);
	int res1 = postfix(exp);
	printf("enter prefix exp: ");
	scanf("%s",exp);
	int res2 = prefix(exp);
	printf("\nPostfix eval = %d\nPrefix eval = %d\n",res1,res2);
	return 0;
}
