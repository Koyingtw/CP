// Problem: Hotel Queries
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1143
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
#pragma region
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// #define int long long
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
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int x[MAXN];
struct Node
{
	int l, r, mx;
}seg[MAXN * 4];
 
void pull(int id)
{
	seg[id].mx = max(seg[id * 2].mx, seg[id * 2 + 1].mx);
}
 
void build(int id, int l, int r)
{
	seg[id].l = l, seg[id].r = r;
	if(l == r)
	{
		seg[id].mx = x[l];
		return;
	}
	int mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	seg[id].mx = max(seg[id * 2].mx, seg[id * 2 + 1].mx);
}
 
int query(int id, int tar)
{
	if(seg[id].l == seg[id].r)
	{
		return (seg[id].mx >= tar ? seg[id].l : INF);
	}
	if(seg[id].mx < tar) return INF; 
	if(seg[id * 2].mx >= tar)
		return query(id * 2, tar);
	else return query(id * 2 + 1, tar);
}
 
void update(int id, int tar, int val)
{
	if(seg[id].l > tar || seg[id].r < tar)
		return;
	if(seg[id].l == seg[id].r)
	{
		seg[id].mx = val;
		return;
	}
	update(id * 2, tar, val);
	update(id * 2 + 1, tar, val);
	seg[id].mx = max(seg[id * 2].mx, seg[id * 2 + 1].mx);
}
 
void sol()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> x[i];
	build(1, 1, n);
	// for(int i = 1; i < 15; i++) cout << seg[i].mx << " ";
	// cout << endl;
	for(int i = 0, a; i < m; i++)
	{
		cin >> a;
		int ans = query(1, a);
		if(ans == INF)
		{
			cout << 0 << " ";
			continue;
		}
		cout << ans << " ";
		update(1, ans, x[ans] - a);
		x[ans] -= a;
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