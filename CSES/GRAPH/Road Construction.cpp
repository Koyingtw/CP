// Problem: Road Construction
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1676/
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
#define MAXM 200005 
int n, m;
int dsu[MAXN], cnt[MAXN];
void init()
{
	for(int i = 0; i < MAXN; i++)
		dsu[i] = i, cnt[i] = 1;
}

int find(int x)
{
	if(dsu[x] == x) return x;
	return dsu[x] = find(dsu[x]);
}

void modify(int x, int y)
{
	int a = find(x);
	int b = find(y);
	if(cnt[a] < cnt[b])
	{
		swap(x, y);
		swap(a, b);
	}
	dsu[b] = a;
	cnt[a] += cnt[b];
}

void sol()
{
	cin >> n >> m;
	int sum = n;
	int mx = 1;
	init();
	for(int i = 0, a, b; i < m; i++)
	{
		cin >> a >> b;
		if(find(a) != find(b))
		{
			sum--;
			modify(a, b);
			cmax(mx, cnt[find(a)]);
		}
		cout << sum << ' ' << mx << endl;
	}
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