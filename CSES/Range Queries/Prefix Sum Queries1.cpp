// Problem: Prefix Sum Queries
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2166
// Memory Limit: 512 MB
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
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int x[MAXN];

struct Node {
	int l, r, mx = 0, sum = 0;
}seg[MAXN << 2];

void pull(int id, int l, int r) {
	seg[id].sum = seg[l].sum + seg[r].sum;
	seg[id].mx = max(seg[l].mx, seg[l].sum + seg[r].mx);
	cmax(seg[id].mx, 0ll);
	return;
}

void build(int id, int l, int r) {
	seg[id].l = l, seg[id].r = r;
	if (l == r) {
		seg[id].sum = x[l];
		seg[id].mx = x[l];
		return;		
	}
	int mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	pull(id, id * 2, id * 2 + 1);
}

pii query(int id, int ql, int qr) {
	int l = seg[id].l, r = seg[id].r;
	
	if (l > qr || r < ql) return {-INF, 0};
	if (ql <= l && r <= qr) {
		return {seg[id].mx, seg[id].sum};
	}
	pii rtn = {-INF, 0};
	pii q1 = query(id * 2, ql, qr);
	pii q2 = query(id * 2 + 1, ql, qr);

	cmax(rtn.F, max(q1.F, q1.S + q2.F));
	rtn.S = q1.S + q2.S;
	return rtn;
}

void update(int id, int tar, int val) {
	int l = seg[id].l, r = seg[id].r;
	
	if (l > tar || r < tar) {
		return;
	}
	if (l == r && l == tar) {
		x[l] = val;
		seg[id].sum = val;
		seg[id].mx = val;
		return;
	}
	update(id * 2, tar, val);
	update(id * 2 + 1, tar, val);
	pull(id, id * 2, id * 2 + 1);
}
void sol()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}	
	
	build(1, 1, n);
	
	int k, a, b;
	while (m--) {
		cin >> k >> a >> b;
		if (k == 1) {
			update(1, a, b);
		}
		else {
			if (a) 
				cout << max(query(1, a, b).F, 0ll) << endl;		
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