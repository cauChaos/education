#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;
 
int main(void)
{ 
    ios::sync_with_stdio(false);
    int T, cursor;
    string amho;
    stack<char> st;
    stack<char> st2;
 
    cin >> T;
    while (T--)
    {
        cin >> amho;
        cursor = -1;
        for (int i = 0; i < amho.length(); i++)
        {
            if (amho[i] == '<')
            {    
                if (st.empty()) continue;
                else
                {
                    st2.push(st.top());
                    st.pop();
                    cursor--;
                }
            }
            else if (amho[i] == '>')
            {
                if (st.empty() && st2.empty()) continue;
                else if (st.size() - 1 == cursor)
                {
                    if (st2.empty()) continue;
                    else
                    {
                        st.push(st2.top());
                        st2.pop();
                        cursor++;
                    }
                }
                else
                {
                        st.push(st2.top());
                        st2.pop();
                        cursor++;
                }
            }
            else if (amho[i] == '-')
            {    
                if (st.empty()) continue;
                else
                {
                    st.pop();
                    cursor--;
                }
            }
            else
            {
                st.push(amho[i]);
                cursor++;
            }
        }
        while (!st2.empty())
        {
            st.push(st2.top()); 
            st2.pop();
        }
        string ret;
        while (!st.empty())
        {
            ret += st.top();
            st.pop();
        }
        reverse(ret.begin(), ret.end());
        cout << ret << '\n';
    }
    return 0;
}
