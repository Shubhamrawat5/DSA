//To get the value of an arithmetic expression in which there are only single digit numbers only!

#include<iostream>
#include<stack>
using namespace std;

long cal(string s)
{
	string post; //for postfix
	stack<char> st;
	int i=0;
	for(i=0;s[i];++i)
	{
//		cout<<post<<endl;
		if(s[i]=='+' || s[i]=='-' || s[i]=='(') //for sign and opening bracket
		{
			if( st.size()==0 || st.top()=='(' || s[i]=='(')
				st.push(s[i]);
			
			else
			{
				post+=st.top();
				st.pop();
				st.push(s[i]);
			}
		}
		
		else if(s[i]==')') //for closing bracket
		{
			while(st.top()!='(')
			{
				post+=st.top();
				st.pop();
			}
			st.pop();
		}
		
		else //for numbers
		{
			post+=s[i];
		}
	}
	while(st.size()) //remaining signs in stack
	{
		post+=st.top();
		st.pop();
	}
	
	stack<int> stk; //int stack for postfix evaluation
//	cout<<post<<endl;
	
	int x,y;
	for(i=0;post[i];++i)
	{
		if(post[i]=='+' || post[i]=='-') //if sign then perform on top 2 element in stack
		{
			x=stk.top();
			stk.pop();
			y=stk.top();
			stk.pop();
			stk.push(post[i]=='+'?x+y:y-x);
		}
		else //if number just push to stack
			stk.push(post[i]-'0'); // minus '0' to get int values of single digit numbers
	}

	return stk.top();
}

int main()
{
	string s="1-0+(9+9-9)-9-9";
	cout<<cal(s);
}