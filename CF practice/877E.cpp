// Problem: E. Danil and a Part-time Job
// Contest: Codeforces - Codeforces Round #442 (Div. 2)
// URL: https://codeforces.com/contest/877/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
int n, m, timeStamp = 0;
int c[MAXN], tt[MAXN], chd[MAXN];
pii rng[MAXN];
vector<int> G[MAXN];

void getTimeStamp(int i) {
	tt[i] = ++timeStamp;
	rng[tt[i]].F = tt[i];
	
	for (auto e: G[i]) {
		getTimeStamp(e);
	}
	
	rng[tt[i]].S = timeStamp;
	return;
}

struct Node {
	int id, l, r, val, tag;
	
	Node operator +(Node _a) {
		Node tmp = {id, l, _a.r, val + _a.val};
		return tmp;
	}
	
	void operator =(Node _a) {
		val = _a.val, tag = _a.tag;
		return;
	}
	
	void update() {
		val = (r - l + 1) - val;
	}
} seg[MAXN << 2];


void build(int id, int l, int r) {
	seg[id].l = l, seg[id].r = r;
	if (l == r) {
		seg[id] = {id, l, r, c[l], 0};
		return;
	}
	int mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	seg[id] = seg[id * 2] + seg[id * 2 + 1];
}

void push(int id) {
	if (id >= (MAXN << 2) || !seg[id].tag)
		return;
	seg[id * 2].tag ^= seg[id].tag;
	seg[id * 2].update();
	seg[id * 2 + 1].tag ^= seg[id].tag;
	seg[id * 2 + 1].update();
	seg[id].tag = 0;
}

void update(int id, int ql, int qr) {
	int l = seg[id].l, r = seg[id].r;
	
	if (ql > r || qr < l) {
		return;
	}
	if (ql <= l && r <= qr) {
		seg[id].tag ^= 1;
		seg[id].update();
		return;
	}
	push(id);
	update(id * 2, ql, qr);
	update(id * 2 + 1, ql, qr);
	seg[id] = seg[id * 2] + seg[id * 2 + 1];
}

Node query(int id, int ql, int qr) {
	int l = seg[id].l, r = seg[id].r;
	
	if (ql > r || qr < l) {
		Node tmp;
		tmp.val = tmp.tag = 0;
		return tmp;
	}
	if (ql <= l && r <= qr) {
		return seg[id];
	}
	push(id);
	Node q1 = query(id * 2, ql, qr);
	Node q2 = query(id * 2 + 1, ql, qr);
	return q1 + q2;
}

void sol() {
	cin >> n;
	for (int i = 2, a; i <= n; i++) {
		cin >> a;
		G[a].pb(i);
	}
	getTimeStamp(1);
	for (int i = 1; i <= n; i++)
		cin >> c[tt[i]];		
	build(1, 1, n);
	////
	cin >> m;
	while (m--) {
		string s;
		int v;
		cin >> s >> v;
		v = tt[v];
		
		if (s == "get") {
			Node qry = query(1, rng[v].F, rng[v].S);
			cout << qry.val << endl;
		}
		else {
			update(1, rng[v].F, rng[v].S);
			// cout << query(1, 1, n).val << endl;
		}
	}
}

signed main() {
    Weakoying;
    int t = 1;
    //while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}