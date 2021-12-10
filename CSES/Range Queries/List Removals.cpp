// Problem: List Removals
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1749
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma region
#pragma optimize("O3")
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
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowBIT(x) x &(-x)
#if !LOCAL
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f;
const int P = 1e9+7;

using namespace std;
#pragma endregion
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int x[MAXN];
int BIT[MAXN];

void update(int i, int val)
{
	while(i < MAXN)
	{
		BIT[i] += val;
		i += lowBIT(i);
	}
}
int query(int q)
{
	int cnt = 0;
	for(int i = 17; i >= 0; i--)
	{
		if(cnt + (1 << i) <= n && BIT[cnt + (1 << i)] < q)	
		{
			cnt += (1 << i);
			q -= BIT[cnt];
		}
	}
	return cnt + 1;
}

void sol()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> x[i];
		update(i, 1);
	}
	for(int i = 1, a; i <= n; i++)
	{
		cin >> a;
		int ans = query(a);
		cout << x[ans] << " ";
		update(ans, -1);
	}
	cout << endl;
}

signed main()
{
    Weakoying;
    int t = 1;
    //while (cin >> t)
    {
    	while (t--)
        {
            sol();
        }
    }
        
    return 0;
}