#include<bits/stdc++.h>
#define int long long
#define pr pair<int,int>
#define fr(i,a,b) for(int i=a;i<b;i++)
#define rf(i,a,b) for(int i=a;i>=b;i--)
#define Koying ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

using namespace std;

void sol()
{
    int t;
    while(cin>>t)
    {
        while(t--)
        {
            int n;
            cin>>n;
            stack<int> st; // L
            queue<int> q; // R
            fr(i,0,n)
            {
                int a;
                string s;
                cin>>a>>s;
                if(s[0]=='L')
                {
                    st.push(a);
                }
                else 
                {
                    q.push(a);
                }
            }
            while(!(st.empty()))
            {
                cout<<st.top()<<" ";
                st.pop();
            }
            while(!(q.empty()))
            {
                cout<<q.front()<<" ";
                q.pop();
            }
            cout<<endl;
        }
    }
}

signed main()
{
    sol();
}