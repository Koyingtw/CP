// Problem: D. Max GEQ Sum
// Contest: Codeforces - CodeCraft-22 and Codeforces Round #795 (Div. 2)
// URL: https://codeforces.com/contest/1691/problem/D
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast")
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
#define DB(x) cerr << #x << " " << x << endl
#define all(v) v.begin(), v.end()
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#if !LOCAL
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int x[MAXN];

struct Seg {
	signed l, r, mx, premx, sufmx;
	int sum, mxsum;
	Seg(int l, int r): l(l), r(r), mx(-INF), sum(0), premx(-INF), sufmx(-INF), mxsum(-INF) {}
	Seg(int l, int r, int a): l(l), r(r), mx(a), sum(a), premx(a), sufmx(a), mxsum(a) {}
	
	Seg operator +(Seg _a) {
		Seg tmp(0, 0);
		tmp.mx = max(mx, _a.mx);
		tmp.sum = sum + _a.sum;
		tmp.premx = max(premx, sum + _a.premx);
		tmp.sufmx = max(_a.sufmx, _a.sum + sufmx);
		tmp.mxsum = sufmx + _a.premx;
		cmax(tmp.mxsum, max(mxsum, _a.mxsum));
		return tmp;
	}
	
	void operator =(Seg _a) {
		mx = _a.mx;
		sum = _a.sum;
		premx = _a.premx;
		sufmx = _a.sufmx;
		mxsum = _a.mxsum;
	}
};

vector<Seg> seg(MAXN * 4, Seg(0, 0));




void build(int id, int l, int r) {
	seg[id].l = l, seg[id].r = r;
	if (l == r) {
		seg[id] = Seg(l, r, x[l]);
		return;
	}
	int mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	seg[id] = seg[id * 2] + seg[id * 2 + 1];
}

Seg query(int id, int ql, int qr) {
	int l = seg[id].l, r = seg[id].r;
	if (ql <= l && r <= qr) {
		return seg[id];
	}
	int mid = (l + r) / 2;
	if (qr <= mid)
		return query(id * 2, ql, qr);
	if (ql > mid)
		return query(id * 2 + 1, ql, qr);
	else
		return query(id * 2, ql, qr) + query(id * 2 + 1, ql, qr);
}

struct SparseTable {
	int arr[20][MAXN];
	
	void build() {
		for (int i = 1; i <= n; i++)
			arr[0][i] = x[i];
		for (int i = 1; i < 20; i++) {
			for (int j = 1; j <= n; j++) {
				if (j + (1 << (i - 1)) < MAXN)
					arr[i][j] = max(arr[i - 1][j], arr[i - 1][j + (1 << (i - 1))]);
			}
		}
	}
	
	int query(int ql, int qr) {
		int lg = __lg(qr - ql + 1);
		return max(arr[lg][ql], arr[lg][qr - (1 << lg) + 1]);
	}
}ST;

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	build(1, 1, n);
	ST.build();
	////
	int yes = 1;
	for (int i = 1; i <= n; i++) {
		// front
		int l = 1, r = i, L = i, R = i;
		while (l < r) {
			int mid = (l + r) / 2;
			int qq = ST.query(mid, i);
			if (qq > x[i])
				l = mid + 1;
			else
				r = mid;
		}
		L = r;
		
		// back
		l = i, r = n;
		while (l < r) {
			int mid = (l + r + 1) / 2;
			int qq = ST.query(i, mid);
			if (qq > x[i])
				r = mid - 1;
			else
				l = mid;
		}
		R = l;
		Seg res = query(1, L, R);
		yes &= (res.mxsum <= x[i]);
	}
	if (yes)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}

signed main() {
    Weakoying;
    int t = 1;
    while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}