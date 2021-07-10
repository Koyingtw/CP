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
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define DB(a) cout << a << endl; 
#define stop system("pause");
#define MEM(x,n) memset(x,n,sizeof(x));
const int INF = 0x3f3f3f3f;
using namespace std;

void OUT(string s)
{
    cout << s;
    return;
}
int dp[30];
void pre()
{
    dp[0]=1;
    dp[1]=1;
    int sum=2;
    fr(i,2,30)
    {
        dp[i]+=sum;
        sum+=2*dp[i];
        //DB(dp[i])
    }
}
void sol()
{
    int t;
    while(cin>>t)
    {
        while(t--)
        {
            int n,ans=0,sum=1;
            cin>>n;
            if(n==1)
            {
                cout<<0<<"\n";
                continue;
            }
            fr(i,1,30)
            {
                sum+=2*dp[i];
                //DB(sum)
                ans+=3;
                if(n <= sum)
                {
                    cout<<ans-1<<"\n";
                    break;
                }
                else
                {
                    if(sum+dp[i] >= n)
                    {
                        cout<<ans<<"\n";
                        break;
                    }
                    if(sum+dp[i]*2 >= n)
                    {
                        cout<<ans+1<<"\n";
                        break;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
        }
        cout<<endl;
    }
}


signed main()
{
    Koying
    pre();
    sol();
    return 0;
}