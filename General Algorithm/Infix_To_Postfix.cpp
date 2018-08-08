#include <iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<algorithm>
#include<math.h>
#include<iomanip>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace boost::multiprecision;
#define ll long long
#define in(a) scanf("%lld",&a)
#define out(a) printf("%lld\n",a)
#define for0(i,n) for(i=0;i<n;i++)
#define for1(i,n) for(i=1;i<=n;i++)
ll priority(char a)
{
    if(a=='+'||a=='-')
        return 1;
    else if(a=='*'||a=='/')
        return 2;
    else if(a=='^')
        return 3;
    else if(a=='(')
        return 0;
}
int main() {
	// your code goes here
    ll t,i,j,k;
    cin>>t;
    while(t--)
    {
        string infix;
        cin>>infix;
        ll n=infix.length();
        stack<char> s;
        for(i=0;i<n;i++)
        {
            if(infix[i]=='(')
                s.push(infix[i]);
            else if(infix[i]==')')
            {
                while((s.top()!='(')&&(!s.empty()))
                {
                    cout<<s.top();
                    s.pop();
                }
                if(s.top()=='(')
                    s.pop();
            }
            else if(infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/'||infix[i]=='^')
            {
                while(priority(infix[i])<=priority(s.top())&&(!s.empty()))
                { 
                    cout<<s.top();
                    s.pop();
                }
                s.push(infix[i]);
            }
            else
                cout<<infix[i];
        }
        while(!s.empty())
        {
            cout<<s.top();
            s.pop();
        }
        cout<<endl;
    }
	return 0;
}
