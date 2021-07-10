/*
.-..-.             _             
: :' ;            :_;            
:   '  .--. .-..-..-.,-.,-. .--. 
: :.`.' .; :: :; :: :: ,. :' .; :
:_;:_;`.__.'`._. ;:_;:_;:_;`._. ;
             .-. :          .-. :
             `._.'          `._.'
*/

#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define pr pair<int, int>
#define fr(i, a, b) for (int i = a; i < b; i++)
#define rf(i, a, b) for (int i = a; i >= b; i--)
#define F first
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define DB(a) cout << a << endl;
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
using namespace std;

void OUT(string s)
{
    cout << s;
    return;
}
const int N = 5005;
int dp[5005][5005];
int x[5005];
int pre[5005];
int f(int l,int r)
{
    if(dp[l][r]) return dp[l][r];
    if(r-l==2) return dp[l][r]=max(x[l],x[l+1]);
    if(r-l==1) return dp[l][r]=x[l];
    else
    {
        int a=f(l,r-2),b=f(l+1,r-1),c=f(l+2,r);
        int mn=max(a,max(b,c));
        
        if(mn==a)
            return dp[l][r]=max(dp[l][r],a+x[r-1]);
        if(mn==b)
            return dp[l][r]=max(dp[l][r],b+max(x[l],x[r]));
        else
            return dp[l][r]=max(dp[l][r],c+x[l]);
    }
}

int ff(int l,int r)
{
    if(dp[l][r]) return dp[l][r];
    if(r-l==2) return dp[l][r]=min(x[l],x[l+1]);
    if(r-l==1) return 0;
    else
    {
        dp[l][r]=max(dp[l][r],f(l,r-2)+x[r-1]);
        dp[l][r]=max(dp[l][r],f(l+1,r-1)+max(x[l],x[r]));
        dp[l][r]=max(dp[l][r],f(l+2,r)+x[l]);
    }
}

void sol()
{
    int n;
    while (cin >> n)
    {
        fr(i,0,n)
        {
            MEM(dp[i],0);
            cin>>x[i];
            //pre[i+1]=pre[i]+x[i+1];
        }
        DB(f(0,n));
        cout<<max(f(0,n-1),f(1,n))<<endl;
    }
}

signed main()
{
    Koying
    sol();
    return 0;
}