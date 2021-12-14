// Problem: Prefix Sum Queries
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2166
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma region
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
#define MAXN 2000005
#define MAXM 1000005 
int n, m;
int x[MAXN];
struct Node
{
	int id, l, r, mx, tag;
	void update(int val)
	{
		mx += val;
		tag += val;
		// if(val)
			// cout << "upd: " << l << " " << r << " " << tag << endl;
	}
}seg[MAXN * 4];

void pull(int id) {seg[id].mx = max(seg[id * 2].mx, seg[id * 2 + 1].mx);}

void push(int id)
{
	int tag = seg[id].tag;
	// if(tag)
		// cout << "push:" << seg[id].l << " " << seg[id].r << " " << tag << endl;
	if(seg[id].l != seg[id].r)
	{
		seg[id * 2].update(tag);
		seg[id * 2 + 1].update(tag);
		seg[id].tag = 0;
	}
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
	pull(id);
}
void update(int id, int ql, int qr, int val)
{
	int l = seg[id].l, r = seg[id].r;
	if(ql <= l && r <= qr)
	{
		seg[id].update(val);
		return;
	}
	if(ql > r || qr < l) return;
	push(id);
	update(id * 2, ql, qr, val);
	update(id * 2 + 1, ql, qr, val);
	pull(id);
}

int query(int id, int ql, int qr)
{
	int l = seg[id].l, r = seg[id].r;
	if(ql <= l && r <= qr)
		return seg[id].mx;
	if(ql > r || qr < l)
		return 0;
	push(id);
	return max(query(id * 2, ql, qr), query(id * 2 + 1, ql, qr));
}

void sol()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> x[i];
		x[i] = x[i] + x[i - 1];
		// cout << x[i] << " ";
	}
	build(1, 1, n);
	int k, a, b;
	while(m--)
	{
		cin >> k >> a >> b;
		if(k == 1)
		{
			int upd = b - (query(1, a, a) - query(1, a - 1, a - 1));
			update(1, a, n, upd);// 1 3 2 0 1 -4 -3 1
			// for(int id = 1; id < 16; id++)
			// {
				// cout << seg[id].l << " " << seg[id].r << " " << seg[id].mx << endl;
			// }
		}
		else
		{
			cout << max(query(1, a - 1, b) - query(1, a - 1, a - 1), 0ll) << endl;
		}
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