// Problem: C. Wrong Addition
// Contest: Codeforces - Codeforces Round #762 (Div. 3)
// URL: https://codeforces.com/contest/1619/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pqueue priority_queue
#define pb push_back
#define F first
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) a = (a > b ? a : b)
#define cmin(a, b) a = (a < b ? a : b)
#define put(x) cout << x << endl;
#define putarr(x) for(int i = 0; i < sizeof(x); i++) cout << x[i] << (" \n")[i == sizeof(x) - 1]; 
#define all(v) v.begin(), v.end()
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#if !LOCAL
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 100005
#define MAXM 1000005 
int n, m;

void sol()
{
	cin >> n >> m;
	string ans;
	bool yes = 1;
	do
	{
		for(int i = 0; i < 10; i++)
		{
			if(i + n % 10 == m % 10)
			{
				ans += i + '0';
				m /= 10;
				n /= 10;
				break;
			}
			if(i + n % 10 == m % 100)
			{
				ans += i + '0';
				m /= 100;
				n /= 10;
				break;
			}
			if(i == 9)
			{
				yes = 0;
				break;
			}
		}
	}while(m && yes);	
	if(!yes || n != m || !ans.size()) cout << -1 << endl;
	else
	{
		reverse(all(ans));
		// cout << ans << endl;
		cout << stoll(ans) << endl;
	}
}

signed main()
{
    Weakoying;
    int t = 1;
    while (cin >> t)
    {
    	while (t--)
        {
            sol();
        }
    }
        
    return 0;
}