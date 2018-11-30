#include<iostream>
#include<stack>
#include<string>

using namespace std;
 
int icp(char op)
{ 
    if (op == '$' || op == '(') return 0;
    else if (op == '+' || op == '-') return 1;
    else return 2;
}
 
bool oper(char ch)
{ 
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')') return true;
    else return false;
}
 
int main(void)
{
    string str;
    stack<char> st;
 
    cin >> str;
 
    st.push('$');
 
    for (int i = 0; i < str.length(); i++)
    {    
        if (!oper(str[i])) cout << str[i];
        else
	{
            if (str[i] == '(') st.push(str[i]);
            else if(str[i] == ')')
	    {
                while (st.top() != '(')
		{
                    cout << st.top();
                    st.pop();
                }
                st.pop();
            }
            else
	    {
                if (icp(st.top()) < icp(str[i])) st.push(str[i]);
                else
		{
                    while (icp(st.top()) >= icp(str[i]))
		    {
                        cout << st.top();
                        st.pop();
                    }
                    st.push(str[i]);
                }
            }
        }
    }
 
    while (st.top() != '$')
    {
        cout << st.top();
        st.pop();
    }
 
    return 0;
}

by Junsuk Oh
