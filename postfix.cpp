#include <iostream>
#include <stack>
using namespace std;

int pow(int a,int b)
{
	if(b==0)
		return 1;
	return a*pow(a,b-1);
}

bool isOperator(char c)
{
	switch(c)
	{
		case '+': case '-': case '*': case '/': case '^': return true;
		default: return false;
	}
}

int getResult(int a,int b,char c)
{
	switch(c)
	{
		case '+': return a+b;
		case '-': return a-b;
		case '*': return a*b;
		case '/': return a/b;
		case '^': return pow(a,b);
	}
}

//it will evaluate a postfix expression assuming it is valid
void evaluatePostfix(string s)
{
	stack<int> S;
	for(int i=0;i<s.length();i++)
	{
		if(isOperator(s[i]))
		{
			int b=S.top();S.pop();
			int a=S.top();S.pop();
			S.push(getResult(a,b,s[i]));
		}
		else
			S.push(s[i]-'0');
	}
	return S.top();
}

int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	cout<<"Result is "<<evaluatePostfix(s);
	return 0;
}