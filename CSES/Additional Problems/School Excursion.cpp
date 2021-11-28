// Problem: School Excursion
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1706
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
#define lowbit(x) x &(-x)
#if !LOCAL
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f;
const int P = 1e9+7;

using namespace std;
#pragma endregion
/******************************************************************************/
#define MAXN 100005
#define MAXM 1000005 
int n, m;
int dsu[MAXN], cnt[MAXN];
void init()
{
	for(int i = 0; i < MAXN; i++)
		dsu[i] = i, cnt[i] = 1;
}
int find(int a)
{
	if(dsu[a] == a) return a;
	else return dsu[a] = find(dsu[a]);
}
void unite(int a, int b)
{
	int aa = find(a), bb = find(b);
	if(aa == bb) return;
	if(cnt[aa] > cnt[bb])
	{
		swap(aa, bb);
	}
	dsu[bb] = aa;
	cnt[aa] += cnt[bb];
}
bitset<MAXN> dp{1};
void sol()
{
	cin >> n >> m;
	init();
	for(int i = 0, a, b; i < m; i++)
	{
		cin >> a >> b;
		unite(a, b);
	}
	dp[0] = true;
	//put(dp);
	for(int i = 1; i <= n; i++)
	{
		if(dsu[i] == i)
		{
			bitset<MAXN> tmp = dp;
			tmp <<= cnt[i];
			dp |= tmp;
		}
	}
	//put(dp);
	for(int i = 1; i <= n; i++)
	{
		cout << dp[i];
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